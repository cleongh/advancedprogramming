#include <vector>
#include <iostream>

void line() {
    std::cout << "------------------------------------" << std::endl;
}

//http://www.cprogramming.com/tutorial/stl/iterators.html
int main()
{
    std::vector<int> vec = {5, 4, 3, 2, 1};

    // WE DO NOT WANT THIS!!:
    // http://stackoverflow.com/questions/14373934/iterator-loop-vs-index-loop 
    for(ulong i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << std::endl;
    }

    line();

    std::vector<int>::iterator it = vec.begin();

    //std::cout << it + 2 << std::endl; // doesn't compile

    std::cout << *it + 2 << std::endl; // see the differences?

    std::cout << *(it + 2) << std::endl;

    line();


    // This is much better
    // note that I don't need to initialize it, it has been initialized before
    for(; it != vec.end(); it++) {
        std::cout << *it << std::endl;
    }

    line();

    // This is much better
    // note that I need the it = vec.begin() here, the iterator doesn't point to the begin now
    // what happens if I don't initialize it?
    for(std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++) {
        *it += 100;
    }

    // Yeah, I'm DRYing here... =$
    for(std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++) {
        std::cout << *it << std::endl;
    }

    
    return 0;
}
