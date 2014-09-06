# Lecture 2 - General aspects, C++11 (I)

- Cost and big O notation (briefly)
    - Introduce big-o notation: http://en.wikipedia.org/wiki/Big_O_notation
    - Explain algorithms
    - More to come in profiling tools
    - Main term is estimating cost
    - http://bigocheatsheet.com/
    - Asymptotically optimal algorithm and non-optimality in reality: 
      http://en.wikipedia.org/wiki/Asymptotically_optimal_algorithm
- Clean code
    - DRY
    - return something useful from main.
    - Refactoring: http://en.wikipedia.org/wiki/Code_refactoring
    - Document everything. Really.
    - Adhere to conding conventions: http://en.wikipedia.org/wiki/Coding_conventions
    - Make your code maintainable.
    - Don't optimize non-working code
    - Don't build a framework for a 10 lines script
    - Read a lot of code.
    - Write perfect code, always. You'll end up writing perfect code.
- C++11 (I)
    - C++ standards: http://isocpp.org/
    - C++11: http://en.wikipedia.org/wiki/C++11
    - Iterators: http://www.cprogramming.com/tutorial/stl/iterators.html
    - Range-based for loops (at last!): http://www.cprogramming.com/c++11/c++11-ranged-for-loop.html
        - show ranged vector
        - show ranged map (returns a std::pair)

# Exercise

- Run and gather execution time (4 or 5 samples), then draw a graph (with Calc, octave, gnuplot).
- modify the code in github and program the comparison (take more samples).
- upload results to your github account
- write a Makefile for the code, it must contain "all" and "clean"
- Create the loops that the exercises (loop_exercises.cpp) don't implement
- Transform loops in the exercise to ranged loops

