#include <stdio.h>
#include <stdlib.h>

struct KTest {
	int iAge;
	int iHp;
	int aData[4];
	int iMp;

	void SetHp2(int hp)
	{
		this->iHp = hp;
	}
};

void main() {
	KTest t = { 1, 3, { 6, 7, 8, 9 }, 5 };
	int KTest::*pHp = nullptr;
	pHp = &KTest::iHp;
	t.*pHp += 1;
	KTest t2 = { 10, 30, { 60, 70, 80, 90 }, 50 };
	t2.*pHp += 1;
	int* pi = nullptr;
	pi = &t.iHp;
	*pi += 1;
	printf("%i\r\n", t.iHp); // 5
}