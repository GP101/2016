#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <Windows.h>
#include <time.h>
#include <conio.h>
#include <iostream>

namespace std2 {
    std::ostream& endl( std::ostream& out ) {
        out << "\r\n\r\n";
        return out;
    }
}

class KTest {
public:
    typedef std::ostream& (*FUNCTION)( std::ostream& out );
    KTest& operator<<( FUNCTION callback ) {
        std::cout << __FUNCSIG__ << std::endl;
        callback( std::cout );
        return *this;
    }
};//class KTest

void main() {
    std::cout << "Hello" << std2::endl;

    KTest t;
    t << std2::endl;

    std::cout << "World" << std2::endl;
}//main()
