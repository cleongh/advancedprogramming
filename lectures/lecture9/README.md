# Lecture 9: Pointers

- Pointers
    - [Pointers and references](http://www.codeproject.com/Articles/4894/Pointer-to-Pointer-and-Reference-to-Pointer)
        - 'pointers to pointers' exist
        - 'reference to pointer' exists
        - 'pointer to reference' doesn't exist
        - 'reference to reference' doesn't exist (it's a r-value reference)
    - [Smart pointers](http://www.codeproject.com/Articles/541067/Cplusplus11-Smart-Pointers)
        - [`auto_ptr`](http://en.wikipedia.org/wiki/Auto_ptr) (deprecated): 
        - `unique_ptr` (C++11, replaces `auto_ptr` in most cases)
        - `shared_ptr`, with reference counting
        - [Boost](http://www.boost.org/doc/libs/1_55_0/libs/smart_ptr/smart_ptr.htm)
            - `scoped_ptr`/`scoped_array` for dynamic RIIA, no special semantics
            - `shared_ptr`/[`shared_array`](http://stackoverflow.com/questions/13061979/shared-ptr-to-an-array-should-it-be-used) (like std::shared_ptr)
            - [`intrusive_ptr`](http://www.boost.org/doc/libs/1_55_0/libs/smart_ptr/intrusive_ptr.html) for object providing their own reference counting:
        - smart pointers are thread safe, but the objects they point to can be unsafe
    - [Opaque pointers](http://en.wikipedia.org/wiki/Opaque_pointer)
        - .h file includes the _declaration_ of a pointer type to a struct that is declared in the .c[pp] file.
        - the compiler doesn't need to know the inner details of the struct because it is only
          using a pointer (`sizeof(ptr_to_opaque) == `sizeof(ptr_to_full_structure)`).


# Extended bibliography

- [More Effective C++: 35 New Ways to Improve Your Programs and Designs](http://www.amazon.com/gp/product/020163371X?ie=UTF8tag=aristeia.com-20linkCode=as2camp=1789creative=9325creativeASIN=020163371X)

# Exercises

- there's no specific exercise for this lecture, but "correct" use of pointers and references will
  be required from now on.
