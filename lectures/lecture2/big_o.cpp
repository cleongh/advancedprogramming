#include <iostream>
#include <random>
#include <vector>

#include <algorithm>
#include <functional>
#include <iterator>

#include <sstream>

// borrowed from http://anandpandia.blogspot.com.es/2012/08/quicksort-algorithm-and-example-in-c.html
// (ask for permission!)
using namespace std;
void quickSort(vector < int >&input, int left, int right)
{
    int i = left, j = right;
    int pivot = input[(i + j) / 2];

    // partition  
    while (i <= j) {
        while (input[i] < pivot)
            i++;

        while (input[j] > pivot)
            j--;

        if (i <= j) {
            int tmp = input[i];
            input[i] = input[j];
            input[j] = tmp;

            i++;
            j--;
        }
    }

    // recursion  
    if (left < j)
        quickSort(input, left, j);

    if (i < right)
        quickSort(input, i, right);
}

void quickSort(vector < int >&input)
{
    quickSort(input, 0, input.size() - 1);
}

// adapted from 
// http://en.wikibooks.org/wiki/Algorithm_Implementation/Sorting/Bubble_sort#C.2B.2B
void bubbleSort(vector < int >&list)
{
    auto first = list.begin();
    auto last = list.end();

    for (auto i = first; i != last; i++) {
        for (auto j = first; j < i; j++) {
            if (*i < *j) {
                iter_swap(i, j);
            }
        }
    }
}

int main(int argc, char const *argv[])
{

    if (argc < 3) {
        cout <<
            "I need the algorithm (bubble | quick) and the amount of random numbers to order."
            << endl;
        return -1;
    } else {
        cout << "big o notation sample" << endl;

        // random the c++11 way
        random_device rd;
        std::mt19937 gen(rd());
        uniform_int_distribution < int >dis(1, 100);

        vector < int >list;


        // atoi the c++ way
        stringstream str;
        str << argv[2];
        int x;
        str >> x;


        for (int n = 0; n < x; ++n) {
            list.push_back(dis(gen));
        }

        string kind(argv[1]);

        if (kind == "bubble") {
            bubbleSort(list);
            cout << "using bubblesort" << endl;
        } else {
            cout << "using quicksort" << endl;
            quickSort(list);
        }

        // http://www.cprogramming.com/c++11/c++11-ranged-for-loop.html   
        for (int i:list) {
            cout << i << endl;
        }
        return 0;
    }

}
