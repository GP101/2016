#include <stdio.h>
#include <conio.h>

void main()
{
    int ch = 0;

    while (ch != 27)
    {
        ch = _getch();

        //if (ch == 'a')
        //    printf("a pressed\r\n");
        //else if (ch == 'b')
        //    printf("b pressed\r\n");
        //else if (ch == 'c')
        //    printf("c pressed\r\n");
        //else
        //    printf("%d\r\n", ch);
        switch (ch)
        {
        case 'a':
            printf("a pressed\r\n");
            break;
        case 'b':
            printf("b pressed\r\n");
            break;
        case 'c':
            printf("c pressed\r\n");
            break;
        default:
            printf("%d\r\n", ch);
            break;
        }
    }
}