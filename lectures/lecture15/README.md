# Lecture 15: Other languages

- Other languages (and what they are good for)
    - Python, Ruby, Perl, PHP and Lua
        - dynamic languages
        - used for non-scripting tasks: webapps, desktop apps, prototyping...
        - bad performance (often acceptable for many purposes), high productivity
    - Javascript
        - Web programming
        - Not only web programming (node.js)
        - The assembler of the web
    - Scala/Scheme/Clojure/Haskell...
        - Functional programming from different perspectives
        - Reasonable performance
        - Positive influence in imperative languages
    - Prolog and logic languages
        - NLP
        - Knowledge represetation
        - Not widely used in production environments
    - Java and C#
        - When you don't need top performance
        - When you can cope with GC
        - When your team can't manage the complexity of other languages
- The ultimate programming language
    - It doesn't exist. Not in general at least.
        - implementations influence language (JVM-based?, multiplatform compiler?)
    - Before implementing your own programming/scripting language, check that you can do better and
      that the time you spend on the design+implementation is really worth the effort.
    - *Right tool for the right job* is not always a solution
        - you'd need to know well too many languages
        - or you just need to be a specialist on a particular technology
    - Try to know as many as you can.

# Extended bibliography

- [TIOBE](http://www.tiobe.com/index.php/content/paperinfo/tpci/index.html)
- [The Computer Language Benchmarks Game](http://benchmarksgame.alioth.debian.org/)
- [Top Ten Most Popular Programming Languages 2013](http://bestteneverything.com/top-ten-most-popular-programming-languages-2013/)

# Exercises

- write a script in Python or Ruby (preferably the one you know less) that:
    - asks for the number of players
    - asks for the size of the field
    - runs a simulation with those parameters
    - You can use Qt or whatever other GUI framework you prefer
