#include <stdio.h>
#include <conio.h>

void Test1(int a1[5])
{
    for (int i = 0; i < 5; ++i)
    {
        printf("%d\r\n", a1[i]);
        a1[i] += 1;
    }
}

void Test2(int b2[2][3])
{
    for (int r = 0; r < 2; ++r)
    {
        for (int c = 0; c < 3; ++c)
        {
            printf("%d ", b2[r][c]);
        }
        printf("\r\n");
    }
}

void main()
{
    int a[5] = { 1,3,5,7,9 };
    //  일차원 배열one dimensional array
    //  ^ 배열 이름array name
    //    ^첨자index 1개 사용
    //            ^ 요소element
    printf("%d,%d\r\n", a[1], *(a + 1));
    Test1(a);
    for (int i = 0; i < 5; ++i)
    {
        printf("%d\r\n", a[i]);
    }

    int b[2][3] = { {1,2,3},{5,7,9} };
    Test2(b);
    printf("%d,%d\r\n", b[0][1], b[1][2]);
        // 2, 9
    printf("%d,%d\r\n", *(b[0] + 1), *(b[1] + 2));
    printf("%d,%d\r\n", *(b[0]+4), b[0][4] );
        // 7,7
}