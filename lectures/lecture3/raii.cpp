#include <iostream>

using namespace std;

class Test
{
public:
    Test (int value) {
        mValue = value;
        cout << "hello " << mValue << "!" << endl;
    }
    virtual ~Test () {
        cout << "goodbye " << mValue << "!" << endl;
    }

private:
    int mValue;
};

int main()
{
    Test t1(6);
    {
        Test t2(15);
    }
    cout << "can you see?" << endl;
    return 0;
}
