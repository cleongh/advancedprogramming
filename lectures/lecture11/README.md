# Lecture: Programming paradigms and Event driven programming

- Programming paradigms
    - Procedural, OOP, Functional, Logic, Symbolic
    - [Functional](http://www.haskell.org/haskellwiki/Functional_programming)
        - many patterns, different languages use different subsets
        - referential transparency
        - purity
        - recursion
        - high order functions ...
        - [Functional](http://msdn.microsoft.com/en-us/magazine/jj553512.aspx) in C++11:
            - for_each
            - lambdas
            - better syntax for referring to functions...
    - [Logic programming](http://en.wikipedia.org/wiki/Logic_programming)
        - [Prolog](http://en.wikipedia.org/wiki/Prolog) - [SWI Prolog](http://www.swi-prolog.org/) is a free interpreter
        - [CLP](http://en.wikipedia.org/wiki/Constraint_logic_programming)
            - problem description. solution is automatically computed.
    - [Symbolic](http://en.wikipedia.org/wiki/Symbolic_programming)
        - Homoiconicity
        - Macros
        - eval
- Event driven programming
    - What's EDT
    - Differences between procedural programming and EDT
    - SDL event loop, for instance

# Extended bibliography

- [Learn You a Haskell for Great Good](http://www.nostarch.com/lyah.htm)
- [The Art of Prolog](http://mitpress.mit.edu/books/art-prolog)
- [Event-Driven Programming: Introduction, Tutorial, History](http://eventdrivenpgm.sourceforge.net/)

# Exercises

- reprogram your client with an event-driven pattern:
    - put messages from the server in an event queue
    - take the messages from the queue and dispatch them
    - use mutexes where needed
- functional style will be valued
- *optional*
    - implement your search algorithm in Prolog, Clojure or any other symbolic programming language.

