#include <stdio.h>
#include <string.h>
#include <iostream>

template<typename T, int SIZE = 100>
class KStack
{
public:
    KStack() : sp(0) {}
    void push(T d) {
        data[sp] = d;
        ++sp;
    }
    bool pop(T& d);
    T& top() {
        return data[sp - 1];
    }

    bool empty() const {
        return sp == 0;
    }
private:
    int     sp;
    T       data[SIZE];
};//KStack

template<typename T, int SIZE>
bool KStack<T, SIZE>::pop(T& d)
{
    if (sp == 0)
        return false;

    --sp;
    d = data[sp]; // set [out] parameter
    return true;
}

void main()
{
    KStack<int, 10> s;
    KStack<float>   s2;

    s.push(3);
    s.push(5);
    while (!s.empty())
    {
        int i;
        s.pop(i);
        std::cout << i << std::endl;
    }
}//main()
