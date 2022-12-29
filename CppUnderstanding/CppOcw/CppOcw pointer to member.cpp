#include <stdio.h>
#include <algorithm>
#include <memory>

class KTest
{
public:
    int* _ip;
    KTest(int* ip): _ip(ip) {}

    void Print()
    {
        printf("%s %i\n",__FUNCTION__, *_ip);
    }
    int GetInt()
    {
        return *_ip;
    }
};

void main()
{
    int* ip = new int(1);
    KTest   t(ip);
    t.Print();
    printf("%i\n", *(t._ip));

    *ip += 1;
    void (KTest:: * MFP)();
    MFP = &KTest::Print;
    (t.*MFP)();

    printf("begin block\n");
    {
        KTest* pt = nullptr;
        pt = new KTest(ip);
        ((*pt).*MFP)();
        (pt->*MFP)();
        delete pt;
    }

    delete ip;
}//int main()
