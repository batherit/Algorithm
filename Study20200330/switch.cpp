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
			break; // switch �� Ż��
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
		// {}�� �ļ� �� ���ο� ���� ������ ������ �� �ִ�.
		// ���� ������ case�ȿ��� ���� ���̶�� {}�� ġ���� ����.
		string str = "����";

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