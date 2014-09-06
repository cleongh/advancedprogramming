#include "bots.h"

#include <thread>
#include <memory>
#include <iostream>
#include <string>
#include <exception>
#include <boost/archive/text_oarchive.hpp> 
#include <boost/asio.hpp>
#include <boost/thread/thread.hpp>
#include <boost/program_options.hpp>

using boost::asio::ip::tcp;

void send(tcp::socket &socket, const std::string & str) {
    boost::asio::write(socket, boost::asio::buffer(str + "\n"), boost::asio::transfer_all());
}

void client_thread(std::shared_ptr<tcp::socket> socket, bots & bots) {

    bool client_connected = true;

    bot::team_id id = bots.generate_team(5);

    std::stringstream st;

    auto size = bots.get_size();

    st << "welcome " << id << " " << size.first << " " << size.second;
    
    send(*socket, st.str());

    // this must be outside the scope for preventing deleting during stack
    // unwinding because there could be data beyond the delimiter already
    // present in the buffer that could be destroyed
    boost::asio::streambuf buf;
    while(client_connected) {

        read_until(*socket, buf, "\n");

        std::string data;
        std::istream is(&buf);
        std::getline(is, data); 

        std::istringstream stream(data);

        std::string command;

        stream >> command;

        if(command == "goodbye") {
            std::cout << "client left." << std::endl;
            client_connected = false;
        }
        else if(command == "move") {
            int dir;
            int x, y;
            stream >> x;
            stream >> y;
            bot *b = bots.find_at({x, y});
            if(b && b->get_team() == id) {
                stream >> dir;
                b->try_to_do(static_cast<bot::direction>(dir));
            }
        }
        else {
            std::cout << "client sent this unknown message: " << data << std::endl;
        }
    }
}

void server_thread(int port, boost::asio::io_service &io_service, bots & bots, bool &gameover,
        std::vector<std::pair<std::shared_ptr<boost::thread>, std::shared_ptr<tcp::socket> > >& clients) {

    tcp::acceptor acceptor(io_service, tcp::endpoint(tcp::v4(), port));

    std::cout << "starting server..." << std::endl;

    std::cout << "listening on port " << port << "." << std::endl;

    while(!gameover)
    {
        std::shared_ptr<tcp::socket> socket(new tcp::socket(io_service));

        acceptor.accept(*socket);

        std::cout << "someone is connecting...";

        std::shared_ptr<boost::thread> t(new boost::thread([socket, &bots] () { client_thread(socket, bots); } ));

        clients.push_back({t, socket});
        std::cout << " connected!" << std::endl;
    }

    std::cout << "sending \"gameover\" to clients...";
    for(auto & kv : clients) {
        send(*kv.second, "gameover");
    }

    std::cout << " done!" << std::endl;
    std::cout << "waiting for clients to close connection...";
    for(auto &kv : clients) {
        kv.first->join();
    }
    std::cout << " done!" << std::endl;
}

typedef unsigned int port_number_type;
typedef unsigned int time_duration_type;

const time_duration_type DEFAULT_STEP_DURATION_IN_MILLISECONDS = 400;

void read_arguments(int argc, char *argv[], port_number_type &port_number, time_duration_type &step_in_milliseconds) {

    boost::program_options::options_description command_line_description("Arguments");
    command_line_description.add_options()
            ("port", boost::program_options::value<port_number_type>(&port_number)->required(), "port number")
            ("step_duration", boost::program_options::value<time_duration_type>(&step_in_milliseconds)->default_value(DEFAULT_STEP_DURATION_IN_MILLISECONDS), "duration of game step (in milliseconds)");

    try {
        boost::program_options::variables_map arguments;
        boost::program_options::store(boost::program_options::parse_command_line(argc, argv, command_line_description), arguments);
        boost::program_options::notify(arguments);

    } catch (boost::program_options::error &wrong_arguments) {
        std::cerr << wrong_arguments.what() << std::endl;
        std::cerr << command_line_description << std::endl;
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char * argv[])
{

    try {

        port_number_type port;
        time_duration_type millis;

        read_arguments(argc, argv, port, millis);

        const int field_width = 10;
        const int field_height = 10;

        bots bots(field_width, field_height);

        //bots.generate(2, 2);

        bool gameover = false;

        boost::asio::io_service io_service;


        std::vector<std::pair<std::shared_ptr<boost::thread>, std::shared_ptr<tcp::socket> > > clients;

        std::thread server(server_thread, port,
                std::ref(io_service), std::ref(bots), std::ref(gameover),
                std::ref(clients));


        auto previous_time = std::clock();
        std::clock_t acc_time = 0;


        while (!gameover) {

            auto current_time = std::clock();

            auto delta = current_time - previous_time;

            previous_time = current_time;

            acc_time += delta;

            if (acc_time > millis * 1000) {

                bots.step();

                std::stringstream stream;
                boost::archive::text_oarchive oa(stream); 
                oa << bots;

                for(auto kv : clients) {
                    send(*kv.second, "state " + stream.str());
                }

                acc_time = 0;
            }

        }

        server.join();

        //if(bots.game_over()) {
            if(bots.bot_count().size() != 1) {
                std::cout << "it's a tie!" << std::endl;
            }
            else {
                for(auto kv : bots.bot_count()) {
                    std::cout << kv.first << " wins!" << std::endl;
                }
            }
        //}

        std::cout << "server correctly closed." << std::endl;

        return EXIT_SUCCESS;

    } catch (std::exception &e) {
        std::cerr << "Unhandled exception: " << std::endl;
        std::cerr << e.what();
        return EXIT_FAILURE;
    } catch (...) {
        std::cerr << "Unhandled exception" << std::endl;
        return EXIT_FAILURE;
    }

}
