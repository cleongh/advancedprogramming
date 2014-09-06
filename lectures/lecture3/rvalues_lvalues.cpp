#include<iostream>
#include<map>
#include<utility>

int x = 5;

int & getX() {
    return x;

}

// pointers do not work here
int * getXPointer() {
    return &x;
}

std::string getName() {
    return "Luis";
}


int && getRvalueInt ()
{
    // notice that it's fine to move a primitive type--remember, std::move is just a cast
    return std::move( x );
}

int getInt() 
{
    return x;
}



// from: http://www.cprogramming.com/c++11/rvalue-references-and-move-semantics-in-c++11.html
// how to check wether the value is a temp
void printReference (const std::string& str)
{
    std::cout << str;
}

void printReference (std::string&& str)
{
    std::cout << str;
}


// move constructur
// yeah, taken from:
// http://www.cprogramming.com/c++11/rvalue-references-and-move-semantics-in-c++11.html
class ArrayWrapper
{
public:
    // default constructor produces a moderately sized array
    ArrayWrapper ()
        : _p_vals( new int[ 64 ] )
        , _size( 64 )
    {}
 
    ArrayWrapper (int n)
        : _p_vals( new int[ n ] )
        , _size( n )
    {}
 
    // move constructor
    ArrayWrapper (ArrayWrapper&& other)
        : _p_vals( other._p_vals  )
        , _size( other._size )
    {
        // NEEDED! otherwise values will disappear when other._p_vals is destroyed
        other._p_vals = NULL;
        other._size = 0;
    }
 
    // copy constructor
    ArrayWrapper (const ArrayWrapper& other)
        : _p_vals( new int[ other._size  ] )
        , _size( other._size )
    {
        for ( int i = 0; i < _size; ++i )
        {
            _p_vals[ i ] = other._p_vals[ i ];
        }
    }
    ~ArrayWrapper ()
    {
        delete [] _p_vals;
    }
 
private:
    int *_p_vals;
    int _size;
};

int main()
{
    // how to check identity
    int v = 5;
    int & v2 = v;
    std::cout << reinterpret_cast<const void*>( & v ) << std::endl;
    std::cout << reinterpret_cast<const void*>( & v2 ) << std::endl;

    std::cout << "original x = " << x << std::endl;
    getX() = 7;
    std::cout << "original x = " << x << std::endl;

    getXPointer();

    //getXPointer() = 7; // &x is not a l-value

    //&x = 7;


    // pointers and references
    int val = 7;
    int *p = &val;
    std::cout << *p << std::endl;

    // [] returns a l-value
    std::map<int, float> mymap;
    mymap[10] = 5.6;


    // from: http://www.cprogramming.com/c++11/rvalue-references-and-move-semantics-in-c++11.html
    //The intuition here is that you cannot use a "mutable" reference because, if you did, you'd be
    //able to modify some object that is about to disappear, and that would be dangerous. Notice, by
    //the way, that holding on to a const reference to a temporary object ensures that the temporary
    //object isn't immediately destructed. This is a nice guarantee of C++, but it is still a
    //temporary object, so you don't want to modify it.

    const std::string& name = getName(); // ok

    //string& name = getName(); // NOT ok
    //
    std::string&& name_11 = getName(); // ok



    return 0;
}

