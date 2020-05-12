#include<iostream>
#include<string>
using namespace std;

int main(void) {
	int iData = 1;

	switch (iData)
	{
	case 1:
		if (true) {
			cout << "case 1" << endl;
			break; // switch 문 탈출
		}
	case 2:
		cout << "Hello C World!" << endl;
	}

	/*if (true) {
		cout << "error!" << endl;
		break; // compile error
	}*/

	const int attack = 1;
	const int run = 2;
	const int defence = 3;

	int iSelect;
	cin >> iSelect;
	switch (iSelect)
	{
	case attack:
	{
		// {}를 쳐서 그 내부에 지역 변수를 선언할 수 있다.
		// 지역 변수를 case안에서 만들 것이라면 {}를 치도록 하자.
		string str = "공격";

	}
	break;

	case run:
		break;

	case defence:
		break;

	default:
		break;
	}

	return 0;
}