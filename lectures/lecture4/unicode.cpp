#include <iostream>
#include <cstdlib>

// from Wikipedia: http://en.wikipedia.org/wiki/C++11
int main()
{

    std::cout << u8"I'm a UTF-8 string." << std::endl;

    // this is problematic
    std::cout << u"This is a UTF-16 string." << std::endl;
    std::cout << U"This is a UTF-32 string." << std::endl;

    std::cout << u8"This is a Unicode Character: \u2018." << std::endl;

    // this is problematic, too
    std::cout << u"This is a bigger Unicode Character: \u2018." << std::endl;
    std::cout << U"This is a Unicode Character: \U00002018." << std::endl;

    std::cout << R"( "The String Data \ Stuff" )" << std::endl;
    std::cout << R"delimiter( "The String Data \ Stuff " )delimiter" << std::endl;
    std::cout << u8R"XXX(I'm a "raw UTF-8" string.)XXX" << std::endl;
    std::cout << uR"*(This is a "raw UTF-16" string.)*" << std::endl;
    std::cout << UR"(This is a "raw UTF-32" string.)" << std::endl;


    // from http://prog.eskosoft.com/2007/01/13/19:
    //Definitelly, the wchar_t is not UTF-16. The wchar_t is not even Unicode.
    //The C++ standard only guarantees that wchar_t is wide enough to hold any
    //character from the character set, supported by the implementation. There
    //are no mentions about concrete encoding. It can be ANSI, or UCS-2, or
    //UCS-4, or even those SCU-128 encoding from the far future.

    wchar_t out[128];
    mbtowc(out, "hola", sizeof("hola"));
    
    //std::wstring str("hola"); // wstring doesn't accept const chars*
    
    std::wstring str(out);

    // it's actually this simple:
    //typedef basic_string<wchar_t> wstring;
    //typedef basic_string<char> string;
    
    return 0;
}
