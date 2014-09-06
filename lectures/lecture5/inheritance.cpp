#include <iostream> 

class father {
    public:
        father(int v) : _value(v) {}
        virtual ~father() {
            std::cout << "father dies" << std::endl;
        }

        void add_one() {
            _value++;
        }

        virtual void add_two() {
            _value += 2;
        }

        virtual void add_three() final {
            _value += 3;
        }

        // most modern compilers won't pay much attention to inline...
        inline int get_value() const {
            return _value;
        }

    protected:
        int _value;

};

class son : public father {
    public:
        son (int v) : father(v) {}
        virtual ~son () {
            std::cout << "son dies..." << std::endl;
        }

        //void add_one() override { // this doesn't work, add_one isn't virtual
        void add_one() {
            _value += 10;
        }

        void add_two() override { // not needed but useful; it outputs an error if add_two is not virtual
            _value += 20;
        }

        // can't override a virtual final function
        //void add_three() {
            //_value += 30;
        //}
};


int main()
{
    son s(7);
    father * f = &s;
    //s.add_one; // this doesn't bring any problem since the compiler knows "son" must be used
    f->add_one(); // when the instance is used with an ancestor, virtual is needed!!!

    std::cout << s.get_value() << std::endl;
    return 0;
}

