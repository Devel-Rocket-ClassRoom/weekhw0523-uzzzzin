#include "Homework_05.h"
#include <iostream>

void Homework05_Run()
{
    srand(time(0));

    // 미로 크기
    const int Rows = 10;
    const int Cols = 20;

    int HP = 100;

    // 미로 배열
    int Maze[Rows][Cols] =
    {
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        {1,2,0,0,0,1,0,0,0,0,1,0,0,1,0,0,0,1,0,1},
        {1,1,1,1,0,1,0,1,1,0,1,0,1,1,0,1,0,1,0,1},
        {1,0,0,1,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1},
        {1,0,1,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1},
        {1,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,1},
        {1,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1},
        {1,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,3,1},
        {1,0,1,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1},
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
    };

    FindTheMaze(Maze[0], Rows, Cols, HP);
}

void FindTheMaze(int* _arr, int _rowSize, int _colSize, int& _hp)
{
    std::cout << "=== 텍스트 미로 탈출 게임 ===" << std::endl;
    int curPosIdx = FindStartIdx(_arr, _rowSize, _colSize);

    while (true)
    {
        PrintMaze(_arr, _rowSize, _colSize);

        if (true == MoveMaze(_arr, _rowSize, _colSize, curPosIdx))
        {
            PrintMaze(_arr, _rowSize, _colSize);
            break;
        }
        
        if (true == CheckEncounter()) // 몬스터 출현!
        {
            if (false == Battle(_hp)) // 배틀하다가 죽으면 겜 끝 ㅠ
                break;
        }
    }

}

void PrintMaze(int* _arr, int _rowSize, int _colSize)
{
    for (int i = 0; i < _rowSize; ++i)
    {
        for (int j = 0; j < _colSize; ++j)
        {
            switch (_arr[i * _colSize + j])
            {
            case 0: std::cout << "."; break;
            case 1: std::cout << "#"; break;
            case 2: std::cout << "S"; break;
            case 3: std::cout << "E"; break;
            case 4: std::cout << "P"; break;
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int FindStartIdx(int* _arr, int _rowSize, int _colSize)
{
    for (int i = 0; i < _rowSize; ++i)
    {
        for (int j = 0; j < _colSize; ++j)
        {
            if (2 == _arr[i * _colSize + j])
                return i * _colSize + j;
        }
    }
}

bool MoveMaze(int* _arr, int _rowSize, int _colSize, int& _curPosIdx)
{
    char dir = InputCanMoveDir(_arr, _rowSize, _colSize, _curPosIdx);

    int temp = -1;

    switch (dir)
    {
    case 'A':
        _arr[_curPosIdx] = 0;
        temp = _arr[_curPosIdx - 1];
        _arr[_curPosIdx - 1] = 4;
        _curPosIdx -= 1;
        break;

    case 'D':
        _arr[_curPosIdx] = 0;
        temp = _arr[_curPosIdx + 1];
        _arr[_curPosIdx + 1] = 4;
        _curPosIdx += 1;
        break;
    case 'W':
        _arr[_curPosIdx] = 0;
        temp = _arr[_curPosIdx - _colSize];
        _arr[_curPosIdx - _colSize] = 4;
        _curPosIdx -= _colSize;
        break;
    case 'S':
        _arr[_curPosIdx] = 0;
        temp = _arr[_curPosIdx + _colSize];
        _arr[_curPosIdx + _colSize] = 4;
        _curPosIdx += _colSize;
        break;
    }

    if (3 == temp)
        return true;

    return false;
}

bool CheckEncounter()
{
    const int encounterRate = 10; // 적 출현 확률
    return rand() % 100 < encounterRate; // 0-99 중에 0-9가 나오면 몬스터가 출현했다고 판정
}

bool Battle(int& _hp)
{
    int enemyHP = 50;
    std::cout << "==========================================" << std::endl;
    std::cout << "HP" << enemyHP <<"의 야생 몬스터가 나타났다 !!!!" << std::endl << std::endl;

    int tempDamage = 0;
    bool bIsCritical = false;

    while (true)
    {
        if (_hp < 1)
        {
            std::cout << "HP가 다 닳아서 죽었습니다 ㅜ_ㅜ";
            std::cout << "==========================================" << std::endl;
            return false;
        }

        if (enemyHP < 1)
        {
            std::cout << "몬스터를 물리쳤습니다 >_<" << std::endl;
            std::cout << "==========================================" << std::endl;
            return true;
        }

        tempDamage = rand() % 11 + 5; // 5-15
        _hp -= tempDamage;
        std::cout << "몬스터가 나를 공격합니다.. 체력이 " << tempDamage << " 깎였습니다." << std::endl;

        tempDamage = rand() % 11 + 5;
        bIsCritical = (rand() % 100) < 10; // 10% 확률로 크리티컬
        if (true == bIsCritical)
        {
            tempDamage *= 2; // 크리티컬 터지면 2배
            std::cout << "크리티컬 공격이 발동됩니다 ! 몬스터를 공격합니다.. 체력이 " << tempDamage << " 깎였습니다." << std::endl;
        }
        else
        {
            std::cout << "내가 몬스터를 공격합니다.. 체력이 " << tempDamage << " 깎였습니다." << std::endl;
        }
        enemyHP -= tempDamage;

        PrintHP(_hp, enemyHP);
    }

    return true;
}

void PrintHP(int& _hp, int& _enemyHP)
{
    if (_hp < 0) _hp = 0;

    if (_enemyHP < 0) _enemyHP = 0;

    std::cout << "------------------------------------------" << std::endl;
    std::cout << "나의 현재 체력 : " << _hp << std::endl;
    std::cout << "몬스터의 현재 체력 : " << _enemyHP << std::endl;
    std::cout << "------------------------------------------" << std::endl;
}

char InputCanMoveDir(int* _arr, int _rowSize, int _colSize, int& _curPosIdx)
{
    std::cout << "이동할 수 있는 방향을 선택하세요. (W:위 A:왼쪽 S:아래쪽 D:오른쪽)" << std::endl;
    std::cout << "입력할 수 있는 방향 (";

    int rowIdx = _curPosIdx / _colSize;
    int colIdx = _curPosIdx % _colSize;

    if ((colIdx - 1 > -1) && (0 == _arr[_curPosIdx - 1] || 3 == _arr[_curPosIdx - 1]))
        std::cout << "A(왼쪽) ";

    if ((_colSize + 1 > colIdx + 1) && (0 == _arr[_curPosIdx + 1] || 3 == _arr[_curPosIdx + 1]))
        std::cout << "D(오른쪽) ";

    if ((rowIdx - 1 > -1) && (0 == _arr[_curPosIdx - _colSize] || 3 == _arr[_curPosIdx - _colSize]))
        std::cout << "W(위쪽) ";

    if ((_rowSize + 1 > rowIdx + 1) && (0 == _arr[_curPosIdx + _colSize] || 3 == _arr[_curPosIdx + _colSize]))
        std::cout << "S(아래쪽) ";

    std::cout << " 입력 가능) : ";
    char input = ' ';
    std::cin >> input;
    return input;
}