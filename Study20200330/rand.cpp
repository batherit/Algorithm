#include<iostream>
#include<ctime>
using namespace std;

int main(void) {
	srand(unsigned(time(nullptr))); // 시간 간격을 두며 호출하면 고른 랜덤 수를 추출할 수 있을 것임.
	int iRandVal = rand();

	// srand() 호출되는 순간, n씨드의 0행을 참조(refresh) !!
	// 아무리 시간이라도 컴퓨터가 워낙 빠르기 때문에 1초 보다 짧은 주기로
	// srand()를 호출하면 큰 효과를 보지 못할 것.

	return 0;
}