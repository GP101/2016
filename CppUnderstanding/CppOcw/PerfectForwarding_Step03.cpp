// PerfectForwarding.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <utility>

class KTest
{
private:
    int*    pData;
    int     dataSize;
public:
    KTest()
    {
        dataSize = 3;
        pData = new int[dataSize];
        printf("constructor\r\n");
    }

    //KTest(const KTest& rhs) // copy constructor
    //{
    //    dataSize = rhs.dataSize;
    //    pData = new int[dataSize];
    //    memcpy(pData, rhs.pData, sizeof(int) * dataSize);
    //    printf("copy constructor\r\n");
    //}

    //KTest& operator=(const KTest& rhs)
    //{
    //    if (this == &rhs)
    //        return *this;

    //    Release();

    //    dataSize = rhs.dataSize;
    //    pData = new int[dataSize];
    //    memcpy(pData, rhs.pData, sizeof(int) * dataSize);
    //    printf("operator=()\r\n");
    //    return *this;
    //}

    void Release()
    {
        dataSize = 0;
        if (pData != nullptr)
            delete[] pData;
        pData = nullptr;
    }
    ~KTest()
    {
        Release();
        printf("destructor\r\n");
    }
};

void Test(KTest t)
{
    printf("Test()\r\n");
}

KTest GetTest()
{
    KTest t;
    return t;
}

void main()
{
    KTest t;
    Test(t); // crash
    //t = GetTest(); // crash

    // no crashes but still memory overhead copying problem
    //std::vector<KTest> v0;
    //for (int i = 0; i < 8; ++i)
    //{
    //    v0.push_back(KTest());
    //}
}
