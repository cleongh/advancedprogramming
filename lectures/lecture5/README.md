# Lecture 5 - C++ (IV)

- C++ (IV)
    - Auto and decltype
        - new function syntax
    - Lambdas and closures
        - referencing functions easily. No more parenthesis
        - lambas
            - capture defaults
                - it just captures what it needs:
                  http://stackoverflow.com/questions/6181464/c11-lambda-capture-semantics
            - explicit capture
            - reference and value
    - Advanced inheritance
        - virtual, override, final: http://en.wikipedia.org/wiki/C++11#Explicit_overrides_and_final
            - when virtual is needed
        - delete and default constructors and destructor: http://en.cppreference.com/w/cpp/language/destructor
            - You can generate default elements explicitly
            - `default` when other constructors are created so that the compiler creates the default 
              one
            - `delete` when you _don't want_ the constructor or the destructor.
        - public/private/protected inheritance
            - http://stackoverflow.com/questions/860339/difference-between-private-public-and-protected-inheritance-in-c
        - must know this:
            - calling superclass (constructors by name, Father::method otherwise)
            - multiple inheritance
                - the diamond problem: http://en.wikipedia.org/wiki/Diamond_problem#The_diamond_problem


- Exercise
    - Start your project and create the OO design
        - Design your clases and add default constructors explicitly
        - Create virtual methods and include `override` in every overriding method
    - use `auto` as much as you can. use `decltype` only when you need it.
    - use lambdas. Try to use `for_each` from `std::` and use lambas there.
