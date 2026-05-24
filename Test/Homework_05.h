#pragma once

void Homework05_Run();

// 미로찾기
void FindTheMaze(int* _arr, int _rowSize, int _colSize, int& _hp);

// 미로맵 출력하기
void PrintMaze(int* _arr, int _rowSize, int _colSize);

// 스타트 지점 찾기
int FindStartIdx(int* _arr, int _rowSize, int _colSize);

// 미로맵 이동 입력받기
char InputCanMoveDir(int* _arr, int _rowSize, int _colSize, int& _curPosIdx);

// 미로맵 실제 이동하기
bool MoveMaze(int* _arr, int _rowSize, int _colSize, int& _curPosIdx);

// 칸을 이동했을 때 몬스터가 나타났는지 안 나타났는지 불값으로 반환하는 함수
// true를 반환하면 몬스터가 나타난 것
bool CheckEncounter();

// 적이랑 배틀하다가 죽으면 false를 반환하는 함수
bool Battle(int& _hp);

// 나와 적의 체력을 출력하는 함수
void PrintHP(int& _hp, int& _enemyHP);