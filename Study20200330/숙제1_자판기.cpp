/*
숙제 1.
반복문을 통한 반복로직 구현 자판기.
1.소지금 입력 받기
2. 현재 소지금의 보유 잔액 표시
3. 메뉴출력
1.콜라, 2.사이다.3., , , 0, 반환
음료 선택시 해당 물품 구매 완료 출력후 보유 잔액 변동
단, 해당 잔액보다 구매 물품 값이 크면 구매 불가.
다음 메뉴 고를시 이전 출력된 내용은 system함수르 지워준다.
반환을 누르면 현재 거스름돈은 얼마 입니다 출력후 종료.*/

#include<iostream>
using namespace std;

int main(void) {
	const int iColaCost = 200;
	const int iCiderCost = 300;

	const int cola = 1;
	const int cider = 2;
	const int exit = 0;

	int iMyMoney;

	while (true) {
		cout << "현재의 소지금을 입력하세요. : ";
		cin >> iMyMoney;
		cout << endl;

		if (0 > iMyMoney) {
			cout << "소지금액이 음수일 수는 없습니다.";
			continue;
		}
		break;
	}

	int iSelect;
	while (true) {
		cout << "[현재의 소지금 : " << iMyMoney << "원]" << endl;
		cout << "1. 콜라(200원), 2. 사이다(300원), 0. 종료" << endl;
		cout << "구입할 음료를 입력하세요. : ";
		cin >> iSelect;
		cout << endl;
		system("cls");
		switch (iSelect)
		{
		case cola:
			if (0 > iMyMoney - iColaCost) {
				cout << "현재의 소지금으로는 구입할 수 없습니다!" << endl;
			}
			else {
				cout << "콜라를 구입하였습니다." << endl;
				iMyMoney -= iColaCost;
			}
			break;
		case cider:
			if (0 > iMyMoney - iCiderCost) {
				cout << "현재의 소지금으로는 구입할 수 없습니다!" << endl;
			}
			else {
				cout << "사이다를 구입하였습니다." << endl;
				iMyMoney -= iCiderCost;
			}
			break;
		case exit:
			cout << "프로그램을 종료합니다." << endl;
			return 0;
		default:
			cout << "잘못된 입력입니다!" << endl;
			break;
		}

		cout << endl;
	}

	return 0;
}