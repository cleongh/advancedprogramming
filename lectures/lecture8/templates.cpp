#include <iostream>

// templates lets us use generic programming in C++
// http://en.wikipedia.org/wiki/Generic_programming
template <typename N>
N add(N a, N b) {
    return a + b;
}

// templates are turing complete!
// C++ templates allow for typed "variables"
template <int n>
struct Const {
    enum { value = n };
};

////////////////////////////////////////////////////////
// template specialization and metaprogramming
//
// template metaprograming allows for loops, but these must be implemented
// recursively
template <unsigned n>
struct factorial
{
  // both syntaxes are valid
  //enum { value = n * factorial<n-1>::value };
  static const int value = n * factorial<n-1>::value;
};
template <>          // | look at this syntax!
struct factorial<0>  // |
{
  enum { value = 1 };
};
////////////////////////////////////////////////////////



////////////////////////////////////////////////////////
// boost has traits:
// http://www.boost.org/doc/libs/1_55_0/libs/type_traits/doc/html/index.html

// implementation of the trait "can_be_incremented"
template<typename T>
struct can_be_incremented {
    static const bool value = false; // static-const-things can also be used
};

template<>
struct can_be_incremented <int> {
    static const bool value = true;
};
//////////////////////////////////////////////////////////////

// the metaprogramming template "increment" can increment any value
// that satisfies the troit "can_be_incremented"
template<typename A, bool>
struct increment {
    // compile-time error by default
};

template<typename A>
struct increment <A, true> {
    constexpr static A increment_number(A a) {
        return a++;
    }
};
//////////////////////////////////////////////////////////////

// comfortable use of traits
template<typename T>
T increment_number(T j)  {
    return increment<T, can_be_incremented<T>::value>::increment_number(j);
}

/////////////////////////////////////////////////////////////


int main()
{
    
    // not very related, but it's good to know other compile-time programming techniques
    // preprocessor macros have limited use, but they're still valid for a
    // number of programming patterns. 
    //
    // when running the compiler, preprocessor variables can be defined. there
    // variables can help to choose which code to compile. Useful for
    // multi-platform code, features that the user wants in the code...
#define ALTERNATIVE 5
#ifdef ALTERNATIVE
    std::cout << "yeah, compile-time programming existed before C++" << std::endl;
#else
    std::cout << "but not everything will be COMPILED" << std::endl;
#endif

#ifndef SOME_UNDEFINED_PREPROCESSOR_SYMBOL
    std::cout << "prints!" << std::endl;
#endif

#if ALTERNATIVE > 5
    std::cout << "comparisons are valid" << std::endl;
#endif


    // just to make it explicit...
    std::cout << "template adding with float: " << add((int)3, (int)5) << std::endl;

    // the function with templates accepts different types
    std::cout << "template adding with int: " << add((float)3.7, (float)15.0) << std::endl;

    int a = Const<9>::value;
    std::cout << "const: " << a << std::endl;

    int b = factorial<5>::value;
    std::cout << "factorial: " << b << std::endl;

    // traits

    int j = 9;
    //std::cout << "incremented: " << increment_type<decltype(j)>::increment_number(j) << std::endl;
    std::cout << "incremented: " << increment_number(j) << std::endl;

    // non-compiling template
    std::cout << increment_number('a') << std::endl;

    return 0;
}

