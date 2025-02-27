#include <tuple>
#include <string>
#include <iostream>

std::tuple<int, std::string, double> f()
{
    int i{ 108 };
    std::string s{ "Some text" };
    double d{ .01 };
    return { i,s,d };
}
struct S
{
    std::string name;
    int num;
};

S g()
{
    std::string t{ "hello" };
    int u{ 42 };
    return { t, u };
}

int main()
{
    auto[x, y, z] = f(); // init from tuple
    std::cout << x << " " << y << " " << z << std::endl;

    auto[a, b] = g(); // init from POD struct
    std::cout << a << " " << b << std::endl;
    return 0;
}
