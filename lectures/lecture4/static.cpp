#include <iostream>
#include "static_header.h"

class StaticClass
{
private:
    static int mInt; 
public:
    StaticClass () {
        addOne();
    }

    virtual ~StaticClass () {
    }


    static void addOne() {
        mInt++;
    }

    static int getInt() {
        return mInt;
    }

};
// static attrs must be initialized!!!
int StaticClass::mInt = 0;

int count_how_many() {
    static int how_many = 0;
    return ++how_many;

}

int main()
{
    count_how_many();
    count_how_many();
    count_how_many();
    count_how_many();
    int r = count_how_many();
    std::cout << "times executed = " << r << std::endl;


    StaticClass st1;
    StaticClass st2;
    StaticClass st3;
    StaticClass st4;

    std::cout << "I have " << StaticClass::getInt() << " instances" << std::endl;

    add_unit();
    add_unit();
    add_unit();
    add_unit();
    add_unit();
    add_unit();
    add_unit();

    std::cout << "I have " << get_units() << " units" << std::endl;

    return 0;
}

