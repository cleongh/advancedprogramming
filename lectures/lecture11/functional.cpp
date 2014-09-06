#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

template <class c, int n>
struct add {
    c operator()(c & a) {
        a += n;
    }
};

int main() {
    std::vector<int> v = {1, 2, 3, 4, 5};

    std::for_each(v.begin(), v.end(), add<int, 10>());
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, "\n"));
    return 0;
}

