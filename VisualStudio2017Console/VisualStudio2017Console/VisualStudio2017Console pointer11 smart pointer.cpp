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

struct KTestWrapper
{
	KTest* m_pTest;
	void SetKTest(KTest* pTest)
	{
		m_pTest = pTest;
	}
	KTest* operator->()
	{
		return m_pTest;
	}
};

void main() {
	KTest t = { 1, 3, { 6, 7, 8, 9 }, 5 };
	KTestWrapper w;
	w.SetKTest(&t);
	w->iHp += 1;

	printf("%i\r\n", t.iHp); // 4
}