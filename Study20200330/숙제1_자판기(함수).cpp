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

const int COLA = 1;
const int CIDER = 2;
const int END = 0;

/* InputMyMoney
=> Input : void
=> Ouput : 올바른 소지금액이 입력되었을 경우, 이를 반환합니다.*/
int InputMyMoney(void) {
	int iMoney;

	while (true) {
		system("cls");
		cout << "현재의 소지금을 입력하세요. : ";
		cin >> iMoney;

		if (0 > iMoney) {
			cout << "소지금액이 음수일 수는 없습니다." << endl;
			system("pause");
			continue;
		}
		break;
	}
	system("cls");

	return iMoney;
}

/* PrintMachineInterface
=> Input : 현재의 소지금액
=> Output : void*/
void PrintMachineInterface(int iMyMoney) {
	system("cls");
	cout << "[현재의 소지금 : " << iMyMoney << "원]" << endl;
	cout << "1. 콜라(200원), 2. 사이다(300원), 0. 반환" << endl;
	cout << "구입할 음료를 입력하세요. : ";
}

/* GetMenu
=> Input : void
=> Output : 사용자가 선택한 메뉴값을 입력받아 그대로 반환합니다. */
int GetMenu(void) {
	int iSelect;
	cin >> iSelect;
	cout << endl;
	return iSelect;
}

/* GetMoneyAfterColaSelection
=> Input : 현재의 소지금액
=> Output : 콜라를 구입한 이후 거스름돈*/
int GetMoneyAfterColaSelection(int iCurrentMoney) {
	// 콜라 가격은 200원으로 책정
	const int iColaCost = 200;

	if (0 > iCurrentMoney - iColaCost) {
		cout << "현재의 소지금으로는 구입할 수 없습니다!" << endl;
		return iCurrentMoney;
	}
	else {
		cout << "콜라를 구입하였습니다." << endl;
		return iCurrentMoney -= iColaCost;
	}
}

/* GetMoneyAfterCiderSelection
=> Input : 현재의 소지금액
=> Output : 사이다를 구입한 이후 거스름돈*/
int GetMoneyAfterCiderSelection(int iCurrentMoney) {
	// 사이다 가격은 300원으로 책정
	const int iCiderCost = 300;

	if (0 > iCurrentMoney - iCiderCost) {
		cout << "현재의 소지금으로는 구입할 수 없습니다!" << endl;
		return iCurrentMoney;
	}
	else {
		cout << "사이다를 구입하였습니다." << endl;
		return iCurrentMoney -= iCiderCost;
	}
}

/* PrintEndCase
=> Input : 현재의 소지금액
=> Output : void
*/
void PrintEndCase(int iMyMoney) {
	cout << "반환된 금액은 " << iMyMoney << "원입니다." << endl;
	cout << "프로그램을 종료합니다." << endl;
}

/* PrintErrorCase
=> Input : void
=> Output : void
*/
void PrintErrorCase(void) {
	cout << "잘못된 입력입니다!" << endl;
}

int main(void) {
	int iMyMoney = InputMyMoney();
	while (true) {
		PrintMachineInterface(iMyMoney);
		switch (GetMenu())
		{
		case COLA:	iMyMoney = GetMoneyAfterColaSelection(iMyMoney);
			break;
		case CIDER:	iMyMoney = GetMoneyAfterCiderSelection(iMyMoney);
			break;
		case END:	PrintEndCase(iMyMoney);
			return 0;
		default:	PrintErrorCase();
			break;
		}
		system("pause");
		cout << endl;
	}

	return 0;
}