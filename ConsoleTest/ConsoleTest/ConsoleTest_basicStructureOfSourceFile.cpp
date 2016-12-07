// ConsoleApplication.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

//#include <stdio.h>

extern "C" {
    int __cdecl printf(const char * _Format, ...);
}

int main(int argc, char* argv[])
{
    printf("I love the God");
    return 0;
}

