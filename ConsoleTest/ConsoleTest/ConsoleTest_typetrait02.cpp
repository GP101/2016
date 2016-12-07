#include <iostream>
#include <algorithm>
//#include <boost/bind.hpp>
#include <string>

template <class T, T val>
struct integral_constant
{
    typedef integral_constant<T, val>  type;
    typedef T                          value_type;
    static const T value = val;
};

typedef integral_constant<bool, true>  true_type;
typedef integral_constant<bool, false> false_type;

template <typename T>
struct is_void : public false_type{};

template <>
struct is_void<void> : public true_type{};

template <typename T>
struct is_pointer : public false_type{};

template <typename T>
struct is_pointer<T*> : public true_type{};

void main()
{
    std::cout << is_void<void>::value << std::endl; // 1
    std::cout << is_void<int>::value << std::endl; // 0
    std::cout << is_pointer<int>::value << std::endl; // 0
    std::cout << is_pointer<int*>::value << std::endl; // 1
    std::cout << is_pointer<int**>::value << std::endl; // 1
}//main()
