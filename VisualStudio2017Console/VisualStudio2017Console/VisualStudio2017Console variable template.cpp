// C++14
#include <string>
#include <vector>
#include <iostream>

// C++14 variable template, _20191023_jintaeks
template<class T>
constexpr T pi = T(3.141592L); // variable template

template<class T>
T CircularArea(T r) // function template
{
	return pi<T> * r * r; // pi<T> is a variable template instantiation
}

int main()
{
	printf("%g\r\n", CircularArea(1.0));
}
/*	output:
	3.14159
*/
