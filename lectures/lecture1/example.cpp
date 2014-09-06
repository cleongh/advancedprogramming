#include <iostream>
#include <cmath>

/**
 * some people dislike this.
 */
using namespace std;

/**
 * PI constant
 */
const double PI = 3.14159265;

void test() {
    cout << "test" << endl;
}

/**
 * Main function
 */
int main() {

    cout << "hi, advanced programmers!" << endl;

    double degrees = 125;
    double radians = degrees * 180 / PI;

    cout << cos(radians) << endl;
    return 0;
}

