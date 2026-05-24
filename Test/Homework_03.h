#pragma once

void Homework03_Run();

void RunSlotMachine(int* _arr, int _slotSize, int& _betMoney, int& _haveMoney);

// 랜덤으로 슬롯 숫자를 뽑아주는 함수
int randSlotNum();

// 나온 숫자들이 잭팟인지 판단하는 함수
void CheckJacpot(int* _slotArr, int& betMoney, int& haveMoney);