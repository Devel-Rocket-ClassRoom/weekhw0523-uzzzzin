#include "Homework_02.h"
#include <iostream>

void Homework02_Run()
{
	int inputNum = 0;
	int sumResult = 0;

	std::cout << "숫자를 입력하세요 : ";
	std::cin >> inputNum;

	while (true)
	{
		if (0 == inputNum) break;

		sumResult += inputNum % 10; // 끝자릿수 더함
		inputNum /= 10; // 끝자릿수 없앰
	}

	std::cout << "자릿수들의 합은 : " << sumResult;
}
