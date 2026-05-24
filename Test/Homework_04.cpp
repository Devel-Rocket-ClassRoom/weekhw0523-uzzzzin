#include "Homework_04.h"
#include <iostream>

void Homework04_Run()
{
	srand(time(0));

	int haveMoney = 10000;
	int betMoney = 0;

	// 11(J), 12(Q), 13(K), 14(JOKER)
	int cards[14] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };

	std::cout << "☆-★-☆-★-☆-★-☆-★- 도둑 잡기 -☆-★-☆-★-☆-★-☆-★" << std::endl;

	while (true)
	{
		if (haveMoney < 100)
		{
			std::cout << "소지금이 100원보다 적습니다. 게임을 끝냅니다." << std::endl;
			break;
		}

		RunThiefGame(cards, betMoney, haveMoney);
	}
}

void RunThiefGame(int* _cardArr, int& _betMoney, int& _haveMoney)
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

	FisherYatesShuffle(_cardArr, 14); // 카드 섞음

	// 첫번째 카드 뽑기
	if (14 == _cardArr[0]) // 조커를 뽑았어요
	{
		std::cout << "조커를 뽑았습니다 !!! 배팅금의 2배를 드립니다." << std::endl;
		_betMoney = _betMoney * 2;
		_haveMoney += _betMoney;
	}
	else
	{
		std::cout << "조커를 뽑지 못했습니다.... " << std::endl;
		std::cout << "1. 다음 게임을 시작. 2. 배팅금 2배으로 한 번 더 선택! (숫자 입력) : ";
		int choose = 0; std::cin >> choose;

		if (2 == choose)
		{
			_betMoney = _betMoney * 2;
			if (14 == _cardArr[1]) // 배팅 성공
			{
				std::cout << "조커를 뽑았습니다 !!! 배팅금의 2배를 드립니다." << std::endl;
				_haveMoney += _betMoney;
				_betMoney = 0;
				return;
			}
			else
				std::cout << "조커를 뽑지 못했습니다.... " << std::endl;
		}

		_haveMoney -= _betMoney;
	}
	_betMoney = 0;
}

void FisherYatesShuffle(int* _arr, int _len)
{
	// 1. 인덱스는 배열의 마지막 요소에서 첫번째 요소로 진행
	// 2. 인덱스가 가리키는 요소와 0-인덱스까지의 요소 중 임의의 요소를 선택
	// 3. 인덱스가 가이키는 요소와 임의로 선택된 요소를 교환
	// 4. 인덱스는 1 감소

	int curCursorIdx = _len - 1; // 현재 커서는 배열의 제일 끝 요소의 인덱스

	//PrintArray(_arr, _len);
	for (int i = curCursorIdx; i > 0; --i)
	{
		int randChangeIdx = rand() % curCursorIdx; // 랜덤하게 바꿀 커서 인덱스 값

		// 랜덤 커서 인덱스의 배열값과 현재 커서 인덱스의 배열값을 스왑
		int temp = _arr[curCursorIdx];
		_arr[curCursorIdx] = _arr[randChangeIdx];
		_arr[randChangeIdx] = temp;
	}
	//PrintArray(_arr, _len);
}