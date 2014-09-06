# Lecture 10: Programming patterns

- [Design patterns](http://en.wikibooks.org/wiki/C%2B%2B_Programming/Code/Design_Patterns)
    - You should know and know when to use these patterns. There exist [many others](http://en.wikipedia.org/wiki/Software_design_pattern).
        - Factory/abstract factory: building objects through polymorphism
        - Builder: proxy class for building objects
        - Singleton: class with a single instance
        - Prototype: class that can be cloned
        - Adapter: conversion of interface
        - Bridge: separate API from implementation
        - Composite: treat compositing and individual objects the same
        - Decorator: attach functionality dynamically
        - Facade: hide complexity
        - Flyweight: saving memory by sharing resources
        - Proxy: interfaces to other classes (smart pointers)
        - Mixins: combination without inheritance
        - Interface-based Programming: enforcing encapsulation
        - Chain of Responsibility: delegation
        - Command: commands as instances with a common interface
        - Interpreter: language/DSL
        - Iterator: STL is a good example
        - Mediator: interaction between classes
        - Memento: serialization
        - Observer: letting objects know about changes
        - State: changing behavior when state changes (FSMs)
        - Strategy: several algorithms, single interface
        - Template Method: deferring particular behavior to subclasses
        - Visitor: when you let other class in
        - Model-View-Controller (MVC)
    - Not for every language (certainly useful for C++). Other programming paradigms are not
      benefited from or don't need these patterns.

# Extended bibliography

- ["Gang of four"](http://en.wikipedia.org/wiki/Design_Patterns)
- [Code examples](http://calumgrant.net/patterns/)
- [UML diagrams and some code](http://www.oodesign.com/)

# Exercises

- Read, understand and learn all these patterns
- Make your frontend a singleton
- Create a facade class between your networking code and your client
- Clearly separate model and view in your program
- If you use any sort of tree search (and you should!), implement your operators using the command
  pattern
- Add methods to serialize and de-serialize your AI's state (you can use Boost)
- Implement two different AI strategies with the strategy pattern (one of them can be dumb)
- Any other application of a design pattern will be taken into consideration

