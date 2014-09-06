#include <iostream>
#include <memory>

// pointer to pointer to modify a pointer
int c = 9;
void modify_pointer(int ** p) {
    *p = &c;
}

int d = 15;
// note that the order is "*&"
void reference_to_pointer(int *& p) {
    p = &d;
}

// Pointers and references
void pointers_and_references() {
    int a = 4;
    int * b = &a;
    std::cout << "this should print " << a << ": " << *b << std::endl;
    modify_pointer(&b);
    std::cout << "this should print " << c << ": " << *b << std::endl;
    reference_to_pointer(b);
    std::cout << "this should print " << d << ": " << *b << std::endl;

    // pointer aritmetic
    struct test {
        int x;
        int y;
    };
    test t[3];

    t[0].x = 50;
    t[0].y = 500;

    t[1].x = 50;
    t[1].y = 500;

    t[2].x = 10;
    t[2].y = 100;


    test * tp = t;

    // pointer can be used as "memory positions", the compiler translates this
    // as offsets
    std::cout << (tp + 2)->x << ", " << (tp + 2)->y << std::endl;

    // tp == 0, we modify it
    ++tp;
    std::cout << tp->x << ", " << tp->y << std::endl;

}

// Smart pointers
void smart_pointers() {
    
    //////////////////////////////////////////////////////////////////////////// unique
    // unique pointers are used to have a single pointer. this means that the
    // owner of the pointer is the only responsible for deleting it (or doing
    // whatever he wants). Since move semantics are enforced, the user can be
    // sure no other part of the program can mess with a `unique_ptr`
    
    std::unique_ptr<int> u1(new int(5));
    //std::unique_ptr<int> u2 = u1; // doesn't compile
    std::unique_ptr<int> u3 = std::move(u1); //Transfers ownership. p3 now owns the memory and p1 is rendered invalid.
     
    u3.reset(); // Deletes the memory.
    u1.reset(); // Does nothing.



    // shared pointer
    // reference counted pointers. only really destroyed when there's no one using them
    std::shared_ptr<int> s1(new int(5));
    std::shared_ptr<int> s2 = s1; //Both now own the memory.

    // non inmediate initialization
    std::shared_ptr<int> s3 = std::make_shared<int>(5);

    s1.reset(); //Memory still exists, due to p2.
    s2.reset(); //Deletes the memory, since no one else owns the memory.

    // circular references are a problem (A has a pointer to B and B has a
    // pointer to A. If A is deleted, should B be deleted too?)
    
    // s1 still owns the memory. w1 does not increment reference counting. s1
    // might be destroyed and w1 would be pointing to a non-existent object
    std::weak_ptr<int> w1 = s1; 
}

int main()
{

    pointers_and_references();

    smart_pointers();

    return 0;
}

