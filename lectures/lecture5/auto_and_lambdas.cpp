#include <iostream>
#include <string> // VS requires this
#include <algorithm>

int add(int i, int j) {
    return i + j;
}

void lambdas() {

    // LAMDAS
    // auto helps avoiding explicit type
    auto add_replace = add;
    std::cout << add_replace(6, 7) << std::endl;

    // no more pointers and parenthesis
    // this is included in the "algorithm" library
    std::function<int(int, int)> other_add = add;
    std::cout << other_add(11, 17) << std::endl;

    auto lambda = [] (const std::string & value) {
        std::cout << "I print \"" << value << "\"" << std::endl;
    };

    lambda("woahhh!");
}


int x = 10;
int y = 6;

// one of the typical uses of decltype (more useful in classes...)
auto subtract() -> decltype(x){
    return x - y;
}

void auto_and_decltype() {
    int a = 5;

    auto b = 6;

    // http://www.cprogramming.com/c++11/c++11-auto-decltype-return-value-after-function.html
    int & i = a;
    auto j = i; // j is not a reference, auto defaults to by-value. j isn't a reference
    auto & k = i; // is IS a reference

    int *m = &a; 
    auto n = m;// but picks up a pointer! (n is a pointer)

    decltype(a) c = 6;

    std::cout << "decltype is good: " << c << std::endl;

    // decltype can be used for functions with the new syntax when the type can't be known a priori
    // www.cprogramming.com/c++11/c++11-auto-decltype-return-value-after-function.html
    std::cout << "subtract returns: " << subtract() << std::endl;
}

void closures() {
    int b = 3;

    // CLOSURES!!!!

    // capture by reference
    auto capture_lambda = [&b] (int value) {
        //auto capture_lambda = [] (int value) {
        std::cout << "I print \"" << value * b << "\" by reference" << std::endl;
    };

    // http://stackoverflow.com/questions/6181464/c11-lambda-capture-semantics
    capture_lambda(6);

    const std::string str = "En un lugar de la Mancha de cuyo nombre no quiero acordarme...";

    // capture by value
    auto capture_value_lambda = [str] () {
        std::cout << "I print \"" << str << "\" by value" << std::endl;
    };
    capture_value_lambda();

    // capture by reference as default (no explicitation needed)
    auto capture_reference_lambda = [&] () {
        std::cout << "I print \"" << str << "\" by default reference" << std::endl;
    };
    capture_reference_lambda();


    // capture by value as default (no explicitation needed)
    auto capture_value_default= [=] () {
        std::cout << "I print \"" << str << "\" by default value" << std::endl;
    };
    capture_value_default();


}

int main()
{

    auto_and_decltype();

    lambdas();

    closures();

    return 0;
}

