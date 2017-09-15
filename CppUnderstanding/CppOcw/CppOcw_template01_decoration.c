#include <stdio.h>

void Test()
{
    printf("%s\r\n", __FUNCDNAME__);
    printf("%s\r\n", __FUNCSIG__);
    /** with extension .c
        _Test
        with extension .cpp
        decorated name */
}

//int GetMax(int a, int b)
//{
//    printf("%s\r\n", __FUNCDNAME__);
//    printf("%s\r\n", __FUNCSIG__);
//    return a > b ? a : b;
//}
//
//float GetMax(float a, float b)
//{
//    printf("%s\r\n", __FUNCDNAME__);
//    printf("%s\r\n", __FUNCSIG__);
//    return a > b ? a : b;
//}
//
//template<typename T>
//T Sum(T a, T b)
//{
//    printf("%s\r\n", __FUNCDNAME__ );
//    printf("%s\r\n", __FUNCSIG__);
//    printf("%s\r\n", __FUNCTION__ );
//    return a + b;
//}

void main()
{
    int i = 2;
    int j = 3;

    Test();

    //GetMax(i, j);
    //GetMax(2.0f, 3.0f);
    //GetMax(2, 3);

    //Sum(i, j);
    //Sum(2.0f, 3.0f);
    //Sum(2, 3);

}//main()
