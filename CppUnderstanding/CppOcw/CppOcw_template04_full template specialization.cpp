#include <iostream>

template <class T> class Formatter
{
    T* m_t;
public:
    Formatter(T* t) : m_t(t) {}
    void Print()
    {
        std::cout << *m_t << std::endl;
    }//Print()
};//class Formatter

template<> class Formatter<char*>
{
    char* m_t;
public:
    Formatter(char* t) : m_t(t) {}
    void Print()
    {
        std::cout << m_t << std::endl;
    }//Print()
};//class Formatter

void main()
{
    int i = 157;
    // Use the generic template with int as the argument.
    Formatter<int> f1(&i);

    char* str1 = "Hello";
    // Use the specialized template.
    Formatter<char*> f2(str1);

    f1.Print();
    f2.Print();
}//main()
