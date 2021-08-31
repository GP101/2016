#include <stdio.h>
//#include <cstddef>

class KNullTest
{
private:
	int* _pdata = new int();
public:
	~KNullTest()
	{
		if (_pdata) delete _pdata;
	}
	KNullTest& operator =(int i)
	{
		printf("operator=(int)\r\n");
		*_pdata = i;
		return *this;
	}
	//KNullTest& operator =(std::nullptr_t i)
	KNullTest& operator =(decltype(nullptr) i)
	{
		printf("operator=(nullptr)\r\n");
		_pdata = i;
		return *this;
	}
};

int main()
{
	KNullTest t;
	t = NULL;
	t = nullptr;
	return 0;
}