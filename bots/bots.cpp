#include "bots.h"
#include <algorithm>

bots::bots(bot::field_size width, bot::field_size height)
{
    set_size(width, height);
}


bot::team_id bots::generate_team(size_t number_of_bots) throw(too_many_bots) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::mt19937 gen2(rd());
    std::uniform_int_distribution < bot::field_size > random_width(0, _width - 1);
    std::uniform_int_distribution < bot::field_size > random_height(0, _height - 1);

    // get a free team id
    auto bc = bot_count();
    int i = 0;
    while(bc.find(i) != bc.end()) {
        i++;
    }

    if (number_of_bots + _bots.size() > _width * _height) {
        throw new too_many_bots;
    }

    for (size_t j = 0; j < number_of_bots; j++) {

        std::pair < int, int > position;
        do {
            position.first = random_width(gen);
            position.second = random_height(gen2);
        } while (!empty(position));

        create_bot(position, i);
    }
    return i;
}

void bots::generate(size_t number_teams, size_t bots_per_team) throw(too_many_bots)
{
//std::random_device rd;
    //std::mt19937 gen(rd());
    //std::mt19937 gen2(rd());
    //std::uniform_int_distribution < bot::field_size > random_width(0, _width - 1);
    //std::uniform_int_distribution < bot::field_size > random_height(0, _height - 1);

    //if (number_teams * bots_per_team > _width * _height) {
        //throw new too_many_bots;
    //}

    // reasonably efficient for sparse distributions
    // a las vegas algorithm!!
    for (size_t i = 0; i < number_teams; ++i) {

        generate_team(bots_per_team);
        //for (size_t j = 0; j < bots_per_team; j++) {

            //std::pair < int, int >position;
            //do {
                //position.first = random_width(gen);
                //position.second = random_height(gen2);
            //} while (!empty(position));

            //create_bot(position, i);
        //}

    }
}

bots::~bots()
{
}


bot *bots::find_at(const bot::position & pos)
{
    auto it = iterator_at(pos);

    if (it != _bots.end()) {
        return &(*it);
    } else {
        return nullptr;
    }
}

const bot *bots::find_at(const bot::position & pos) const {
    // yeah, "never use const_cast"...
    return const_cast<const bot*>(const_cast<bots*>(this)->find_at(pos));
}

bool bots::empty(const bot::position & pos) const
{
    return find_at(pos) == nullptr;
}

// TODO check whether the other bot is moving (you can move if the other guy is moving
bool bots::can_move(const bot & the_bot, const bot::direction & dir) const
{
    const bot::position & p = bot::new_position(the_bot.get_position(), dir);
    return dir == bot::NOTHING || (p.first >= 0 && p.first < _width &&
        p.second >= 0 && p.second < _height && 
        empty(p));
}

void bots::perform_action(bot & the_bot)
{

    bot::position & pos = the_bot._position;
    const bot::direction & dir = the_bot.get_next_direction();

    if (bot * victim = attacks(the_bot, dir)) {
        victim->_energy = std::max(0, 
                victim->_energy - std::max(0, 
                    the_bot.get_attack () - victim->get_defense()));
        if(victim->get_energy() <= 0) {
            the_bot.kills_bot(*victim);
        }
    } 
    else if (can_move(the_bot, dir)) {
        pos = bot::new_position(pos, dir);
    }
}


bot *bots::attacks(const bot & the_bot, const bot::direction & dir)
{
    bot * b = find_at(bot::new_position(the_bot.get_position(), dir));

    if(nullptr != b && b->get_team() != the_bot.get_team()) {
        return b;
    }
    else {
        return nullptr;
    }
}
const bot *bots::attacks(const bot & the_bot, const bot::direction & dir) const {
    // yeah, "never use const_cast"...
    return const_cast<const bot*>(const_cast<bots*>(this)->attacks(the_bot, dir));
}

void bots::step()
{
    for_each_bot([this] (bot & the_bot) { perform_action(the_bot); });

    _bots.erase( std::remove_if( _bots.begin(), _bots.end(), 
                [] (const bot & b) {return b.get_energy() <= 0;}) , _bots.end() );
}

std::map<bot::team_id, size_t> bots::bot_count() const {
    std::map <bot::team_id, size_t> result;
    for_each_bot([&result] (const bot & the_bot)  { ++result[the_bot.get_team()]; });

    // RVO: http://en.wikipedia.org/wiki/Return_value_optimization
    return result;
}


bots::field_bots::iterator bots::iterator_at(const bot::position & pos) {
    return std::find_if(_bots.begin(), _bots.end(), 
            [&pos] (const bot & the_bot) { 
            return the_bot.get_position() == pos; 
            });
}

bot &bots::operator[](const bot::position & pos) {
    return *iterator_at(pos);

}

const bot &bots::operator[](const bot::position & pos) const{
    // yeah, "never use const_cast"...
    return const_cast<const bot&>(const_cast<bots*>(this)->operator[](pos));
}


std::vector<bot *> bots::include_if(std::function<bool(const bot &)> fun)  {
    std::vector<bot *> destiny;
    for_each_bot([this, &fun, &destiny] (bot &the_bot) {
        if (fun(the_bot)) {
            destiny.push_back(&the_bot);
        }
    });
    return destiny;
}

std::vector<bot *> bots::adjacent(const bot::position & pos)  {
    return include_if([this, &pos] (const bot& b) { return is_adjacent((*this)[pos], b); });
}


std::vector <bot *> bots::team_bots(bot::team_id id) {
    return include_if([this, &id] (const bot& b) { return b.get_team() == id; });
}

