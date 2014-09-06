#include<iostream>
#include<vector>



// const variables
const int N = 10;

int array[N];


void line() {
    std::cout << "------------------------------------" << std::endl;
}

char * broken() {
    return "yeah"; // the compiler is kind enough to warn us
}

const char * safe() {
    return "yeah";
}

class ConstClass
{
public:
    ConstClass (int v) : mValue(v) {}
    virtual ~ConstClass () {}


    int GetValue() const {
        return mValue;
    }

    // be careful: the compiler lets me declare const and non-const methods
    // it will use a const one if the variable is declared as const
    void YouShouldntModify() {
        mValue = 6; // what if I don't want this?
    }
    void YouShouldntModify() const {
        mMutableValue = 91;
        //mValue = 6; // the compiler doesn't let me do this
    }

private:
    int mValue;

    // values that const methods can modify. this is used to keep "constness" while allowing for
    // internal computations (caches, for instance).
    mutable int mMutableValue; 
};


// ouch!
void say_something_1(std::string s) {
    std::cout << s << std::endl;
}
// somewhat better
void say_something_2(std::string & s) {
    std::cout << s << std::endl;
}
// this is what we want
void say_something_3(const std::string & s) {
    std::cout << s << std::endl;
}

int main() {

    int a = 5;

    // variable pointer to variable value
    int * r = &a;
    *r = 6; 
    r++;

    // variable pointer to constant integer
    const int * p = &a;
    //*p = 6; // fails, can't modify *p. the value is constant
    p++; // the pointer is variable

    int const * q = &a;
    //*q = 6; // fails, can't modify *p
    q++;


    int * const s = &a; // constant pointer to a variable integer and
    *s = 8;
    //s++;

    const int * const u = &a; // constant pointer to a variable integer and
    //*u = 8;
    //s++;


    char * b = broken();
    //b[0] = 'j'; ////////////////// TRY THIS!!!!

    const char * j = safe();
    //j[0] = 'j'; // can't do this!


    int ar = 4;
    const int & br = ar;
    //br = 6; // nope

    //int & const cannotBeDone = ar; // constant pointer to a variable integer and

    // parameters and const references
    say_something_1("one");
    say_something_2("two"); // const problems!
    say_something_3("three");


    ConstClass c(3);
    c.YouShouldntModify();
    std::cout << c.GetValue() << std::endl;

    const ConstClass d(3);
    d.YouShouldntModify();
    std::cout << d.GetValue() << std::endl;

    line();
    
    std::vector<int> vec;
    vec.push_back( 3 );
    vec.push_back( 4 );
    vec.push_back( 8 );

    for ( std::vector <int>::const_iterator itr = vec.begin(), end = vec.end(); itr != end; ++itr )
    {
        // just print out the values...
        std::cout<< *itr <<std::endl;
    }

    for(int i : vec) {
        // this is a kind of const iterator
    }

    for(int & i : vec) {
        // this is a kind of non-const iterator
    }

    return 0;

    // use with caution: this is meant for functions that DO NOT MODIFY SOMETHING but whose
    // parameters aren't declared as const
    const int * i = &a;
    int *i2 = const_cast<int *>(i);
    const int *i3 = const_cast<const int *>(i2);
}

