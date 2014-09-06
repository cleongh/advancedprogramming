#include <iostream>
#include <random>

int dumb_las_vegas(int value)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution < int >dis(1, value);
    int rnd;
    do {
	rnd = dis(gen);
    }
    while (rnd % value != 0);
    return rnd;
}

int main()
{

    std::cout << dumb_las_vegas(123456789) << std::endl;

    return 0;
}
