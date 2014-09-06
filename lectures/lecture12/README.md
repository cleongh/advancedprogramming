# Lecture 12: Testing

- Testing
    - Automated tests
    - [Test driven development](http://en.wikipedia.org/wiki/Test-driven_development)
        1. write the tests
        2. check that they fail
        3. make code that passes those tests
        4. refactor to make it look like real code
        5. goto 1
    - Testing *drives* the development. It's not only a proof of quality but a full development
      system.
    - [Code coverage](http://en.wikipedia.org/wiki/Code_coverage) estimates the amount of code that is checked by the tests.
        - it can be automatically estimated with some compilers.
        - you run your test suite and see which functions are called. Those which are not are not
          covered.
        - [Gcov](http://en.wikipedia.org/wiki/Gcov)
    - Requirements influence the tests.
    - [Boost Test library](http://www.boost.org/doc/libs/1_55_0/libs/test/doc/html/index.html)
    - There are [many others](http://en.wikipedia.org/wiki/List_of_unit_testing_frameworks#C.2B.2B)
    - [Cmake & Ctest](http://www.vtk.org/Wiki/CMake/Testing_With_CTest)
        - Ctest uses any executable as a test and acts according to its return value.

# Extended bibliography

- [Test-Driven Development by Example](http://en.wikipedia.org/wiki/Test-Driven_Development_by_Example)

# Exercises

- write 5 tests for your client.
- you can use whatever test library you like most
- apply tdd while creating them and document it in the code (not much is needed, just to check that
  you have really followed some sort of TDD).
