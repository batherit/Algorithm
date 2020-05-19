#include<iostream>
using namespace std;

int main(void) {
	const int* ptr1;		// 역참조후 변수값 변경 불가, 포인터 변수값 변경 가능
	int* const ptr2;		// 역참조후 변수값 변경 가능, 포인터 변수값 변경 불가 => 선언과 초기화 동시에 할 필요
	const int* const ptr3;	// 역참조후 변수값 변경 불가, 포인터 변수값 변경 불가 => 선언과 초기화 동시에 할 필요
	return 0;
}