#include<iostream>
#include <map>
#include <vector>

int main()
{

    // an array
    int the_array [] = {1, 2, 3, 4, 5};

    std::cout << "using arrays..." << std::endl;

    for(auto v : the_array) {
        v += 1;
    }
    
    for(auto v : the_array) {
        std::cout << v << std::endl;
    }
    // what? this doesn't change the value!
    
    std::cout << "using arrays in a working loop..." << std::endl;
    for(auto & v : the_array) {
        v += 1;
    }
    
    for(auto v : the_array) {
        std::cout << v << std::endl;
    }
    // much better (note the reference)... =)
    
    // a vector
    std::vector<int> the_vector = {1, 2, 3, 4, 5};

    std::cout << "using vector..." << std::endl;
    for(auto v : the_vector) {
        std::cout << v << std::endl;
    }
    
    // c++11 rocks! a map
    std::map<int, std::string> the_map = {{1, "me"}, {2, "you"}, {3, "they"}};

    std::cout << "using maps..." << std::endl;
    for(auto kv : the_map) {
        std::cout << kv.first << ", " << kv.second << std::endl;
    }

    return 0;
}

