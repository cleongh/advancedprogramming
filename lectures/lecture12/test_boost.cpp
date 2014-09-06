#define BOOST_TEST_MAIN

#if !defined( WIN32 )
    #define BOOST_TEST_DYN_LINK
#endif

#include <boost/test/unit_test.hpp>

class test
{
public:
    test (int i) : _i (i) {}
    virtual ~test () {}

    inline int get_i() const {
        return _i;
    }

private:
    int _i;
};



BOOST_AUTO_TEST_CASE( test_equals )
{
    const int test_value = 2;
    test t(test_value);

    //BOOST_CHECK( test_value != t.get_i() );
    BOOST_CHECK_EQUAL( test_value, t.get_i() );
}

