#include <iostream>

class KObject
{
public:
    KObject()
    {
        m_iInitialized = 99;
    }
    int GetInitialized() const
    {
        return m_iInitialized;
    }
private:
    int m_iInitialized;
};//KObject

class KBase
{
public:
    KBase( KObject& obj_ )
    {
        std::cout << obj_.GetInitialized() << std::endl;
    }
};//class KBase

class KDerived1 : public KBase
{
public:
    KDerived1() : KBase( m_object )
    {
    }
private:
    KObject m_object;
};//class KDerived

struct KPrivateBase
{
   KObject m_object;
};//struct KPrivateBase

class KDerived2 : protected KPrivateBase, public KBase
{
public:
    KDerived2() : KBase( m_object )
    {
    }
private:
    //KObject m_object;
};//class KDerived

int main ()
{
    KDerived1 d1;
    KDerived2 d2;

    return 0;
}
