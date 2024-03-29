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
	void (KTest::*pHp)(int);
	pHp = &KTest::SetHp2;
	(t.*pHp)(99);
	printf("%i\r\n", t.iHp); // 99
	KTest t2 = { 10, 30, { 60, 70, 80, 90 }, 50 };
	(t2.*pHp)(999);
	printf("%i\r\n", t2.iHp); // 999
}