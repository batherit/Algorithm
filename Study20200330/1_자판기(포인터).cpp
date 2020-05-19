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

const int COLA_COST = 200;
const int CIDER_COST = 300;


void SetMyMoney(int* iMyMoney);
void PrintMachineInterface(int iMyMoney);
void SetMySelect(int* iMySelect);
void SetMoneyAfterColaSelection(int* iCurrentMoney);
void SetMoneyAfterCiderSelection(int* iCurrentMoney);
void SetMyMoneyAfterPurchase(int* iMyMoney, int iCost);
void PrintEndCase(int iMyMoney);
void PrintErrorCase(void);
void RunVendingMachine(void);

int main(void) {
	RunVendingMachine();

	return 0;
}




























/* SetMyMoney
=> Input : 내 소지금액 변수 주소
=> Ouput : void*/
void SetMyMoney(int* iMyMoney) {
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

	// 올바른 소지금액을 변수 iMyMoney에 대입한다.
	*iMyMoney = iMoney;
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

/* SetMySelect
=> Input : 나의 선택 변수의 주소
=> Output : void */
void SetMySelect(int* iMySelect) {
	cin >> *iMySelect;
	cout << endl;
}

/* SetMoneyAfterColaSelection
=> Input : 현재의 소지금액
=> Output : void*/
void SetMoneyAfterColaSelection(int* iCurrentMoney) {
	// 콜라 가격은 200원으로 책정
	const int iColaCost = 200;

	if (0 > *iCurrentMoney - iColaCost) {
		cout << "현재의 소지금으로는 구입할 수 없습니다!" << endl;
	}
	else {
		cout << "콜라를 구입하였습니다." << endl;

		// 거스름돈을 대입한다.
		*iCurrentMoney -= iColaCost;
	}
}

/* SetMoneyAfterCiderSelection
=> Input : 현재의 소지금액
=> Output : void*/
void SetMoneyAfterCiderSelection(int* iCurrentMoney) {
	// 사이다 가격은 300원으로 책정
	const int iCiderCost = 300;

	if (0 > *iCurrentMoney - iCiderCost) {
		cout << "현재의 소지금으로는 구입할 수 없습니다!" << endl;
	}
	else {
		cout << "사이다를 구입하였습니다." << endl;

		// 거스름돈을 대입한다.
		*iCurrentMoney -= iCiderCost;
	}
}

void SetMyMoneyAfterPurchase(int* iMyMoney, int iCost) {
	if (0 > *iMyMoney - iCost) {
		cout << "현재의 소지금으로는 구입할 수 없습니다!" << endl;
	}
	else {
		cout << "음료를 구입하였습니다!" << endl;

		// 거스름돈을 대입한다.
		*iMyMoney -= iCost;
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

/* RunVendingMachine
=> Input : void
=> Output : void
*/
void RunVendingMachine(void) {
	int iMyMoney;
	// 포인터
	SetMyMoney(&iMyMoney);

	int iMySelect;
	while (true) {
		PrintMachineInterface(iMyMoney);
		SetMySelect(&iMySelect);
		switch (iMySelect)
		{
		case COLA:
			// 포인터
			SetMyMoneyAfterPurchase(&iMyMoney, COLA_COST);
			break;
		case CIDER:
			// 포인터
			SetMyMoneyAfterPurchase(&iMyMoney, CIDER_COST);
			break;
		case END:	PrintEndCase(iMyMoney);
			return;
		default:	PrintErrorCase();
			break;
		}
		system("pause");
		cout << endl;
	}
}