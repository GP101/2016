#include <functional>
#include <queue>
#include <vector>
#include <iostream>

class KTest
{
public:
	int     intData;
	std::string name;
};

int main() {
	KTest t2{ 1, "hello" };
	KTest* t = new KTest{ 1, "hello" };
}