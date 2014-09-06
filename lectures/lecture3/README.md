# Lecture 3 - C++ (II)

- C++ (II)
    - Rvalues and lvalues: 
      http://eli.thegreenplace.net/2011/12/15/understanding-lvalues-and-rvalues-in-c-and-c/
        - * gets a r-value and yields a l-value
        - & gets a l-value and yields a r-value
    - RAII: http://en.wikipedia.org/wiki/Resource_Acquisition_Is_Initialization
        - move semantics


# Exercise

- write a class that auto deletes a pointer created previously. The class gets a pointer as 
  parameter and cleans everything up when it gets destroyed.
- use the class with RAII and check that it works without leaks.
- write a class that implements a move constructor with std::move. The class must have one single 
  attribute, a std::string. Use reinterpret_cast<const void*> to check that the object is not being
  copied but rather moved.
