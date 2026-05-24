#include "Homework_03.h"
#include <iostream>

void Homework03_Run()
{
	srand(time(0));

	int haveMoney = 10000;
	int betMoney = 0;

	int slot[3] = {};
	const int slotSize = sizeof(slot) / sizeof(int);

	std::cout << "☆-★-☆-★-☆-★-☆-★- 슬롯 머신 -☆-★-☆-★-☆-★-☆-★" << std::endl;

	while (true)
	{
		if (haveMoney < 100)
		{
			std::cout << "소지금이 100원보다 적습니다. 게임을 끝냅니다." << std::endl;
			break;
		}

		RunSlotMachine(slot, slotSize, betMoney, haveMoney);
	}

}

void RunSlotMachine(int* _slotArr, int _slotSize, int& _betMoney, int& _haveMoney)
{

	std::cout << "소지금 : " << _haveMoney << std::endl;
	std::cout << "얼마를 배팅하시겠습니까? (100원 이상) : ";
	std::cin >> _betMoney;

	if (_betMoney > _haveMoney)
	{
		std::cout << "소지금보다 배팅금이 더 많습니다." << std::endl;
		return;
	}

	if (_betMoney < 100)
	{
		std::cout << "100원 이상을 배팅하세요 !!" << std::endl;
		return;
	}

	for (int i = 0; i < _slotSize; ++i)
	{
		_slotArr[i] = randSlotNum();
		std::cout << "[" << _slotArr[i] << "] ";
	}

	CheckJacpot(_slotArr, _betMoney, _haveMoney);
}

int randSlotNum()
{
	return rand() % 9 + 1; // 1-9
}

void CheckJacpot(int* _arr, int& betMoney, int& haveMoney)
{
	if (_arr[0] == _arr[1])
	{
		if (_arr[0] == _arr[2])
		{
			if (7 != _arr[0]) // 7이 아닌데 숫자 3개 일치
			{
				std::cout << "숫자 세개가 일치합니다 !!! 배팅금의 50배를 드릴게요 !!!" << std::endl;
				betMoney = betMoney * 50;
			}
			else // 7 7 7
			{
				std::cout << "J--A--C--K--P--O--T !!! 배팅금의 10000배를 드릴게요 !!!" << std::endl;
				betMoney = betMoney * 10000;
			}

			haveMoney += betMoney; // 지갑에 배팅금 넣기
			betMoney = 0; // 배팅금 초기화
			return;
		}
	}
	haveMoney -= betMoney; // 배팅금만큼 잃기
	betMoney = 0; // 배팅금 초기화
	std::cout << "일치하는 숫자가 없네요... 아쉽습니다..." << std::endl;

}
