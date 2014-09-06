#include <iostream>
#include <fstream>



int main()
{
    
    std::fstream * ptr_file;


    // see how blocks create and destroy the object. the file is closed
    // when the resource is deallocated
    
    {
    std::fstream file("test.txt");

    ptr_file = &file;

    std::string str;

    file >> str;

    std::cout << str << std::endl;
    }

    // this will fail!!!!! DANGER!!!!!
    std::cout << ptr_file->is_open() << std::endl;

    //------------------------------------------------------------

    std::ifstream * ptr_other_file;


    try {

        std::ifstream other_file("test.txt");

        ptr_other_file = &other_file;

        other_file.exceptions ( std::ifstream::failbit | std::ifstream::badbit );

        throw 0;

        // we will never reach this point
        other_file.close();
    }
    catch (int) {
        std::cout << "exception!" << std::endl;
    }

    // this will always be closed
    std::cout << ptr_other_file->is_open() << std::endl;


    return 0;
}

