#include<iostream>
using namespace std;

int main(void) {
	// ������ ���� ��� ���� 100-90 ���� 89-80 �� ..�� ..�� �׿� ����
	// ���������� �� ���Դϴ�. ...
	// ������ �� ���̰� ����� �� ���̰�
	// ������ ���� �����Դϴ�.

	// ���� �Էº�
	int iKor = 0, iEng = 0, iMath = 0;
	cout << "���� ������ �Է��ϼ���. :";
	cin >> iKor;

	cout << "���� ������ �Է��ϼ���. :";
	cin >> iEng;

	cout << "���� ������ �Է��ϼ���. :";
	cin >> iMath;

	cout << "-----[���]-----" << endl;

	// ���� �� ��� ����
	int iTotal = iKor + iEng + iMath;
	float fAvg = iTotal / 3.f;

	// ��� ��º�
	cout << "���� ������ " << iKor << "�Դϴ�." << endl;
	cout << "���� ������ " << iEng << "�Դϴ�." << endl;
	cout << "���� ������ " << iMath << "�Դϴ�." << endl;
	cout << "������ " << iTotal << "�̸�, ����� " << fAvg << "�Դϴ�." << endl;
	cout << "����� ������ ��, ������ ";

	if (fAvg >= 90.f) cout << "'A'";
	else if (fAvg >= 80.f) cout << "'B'";
	else if (fAvg >= 70.f) cout << "'C'";
	else if (fAvg >= 60.f) cout << "'D'";
	else cout << "'F'";

	cout << "�Դϴ�.";
	return 0;
}