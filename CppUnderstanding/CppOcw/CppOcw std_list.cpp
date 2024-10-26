// Algorithm.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <list>

void Test(std::initializer_list<int> l_)
{
}

void main()
{
	std::list<int> intList{1,3,5};

	//intList.assign({ 1, 3, 5 });
	//Test({ 1, 3, 5 });

	for (int c : intList) {
		std::cout << c << ", ";
		// 1, 3, 5
	}
	std::cout << std::endl;
	std::list<int>::iterator	listHandle = intList.begin();
	listHandle++; // listHandle indicates node '3'

	intList.insert(listHandle, 9); // 1, 9, 3, 5 and listHandle indicates '3' consistently
	intList.insert(listHandle, 99); // 1, 9, 99, 3, 5

	for (std::list<int>::iterator it = intList.begin(); it != intList.end(); ++it) {
		const int value = *it;
		std::cout << value << ", ";
	}
}
