#include<iostream>
using namespace std;

int main(void) {
	// try - catch ���� ����Ͽ� Ż��
	try {
		while (true) {
			cout << "Hello ";
			while (true) {
				cout << "C ";
				while (true) {
					cout << "World " << endl;
					throw false;
				}
			}
		}
	}
	catch (bool error) {
		cout << "Ż��!" << endl;
	}

	// goto ���� ����Ͽ� Ż��
	while (true) {
		cout << "Hello ";
		while (true) {
			cout << "C ";
			while (true) {
				cout << "World " << endl;
				goto ESCAPE;
			}
		}
	}

ESCAPE:
	cout << "Ż��!" << endl;

	// check ������ �̿��Ͽ� Ż��
	bool check = false;

	while (!check && true) {
		cout << "Hello ";
		while (!check && true) {
			cout << "C ";
			while (!check && true) {
				cout << "World " << endl;
				check = true;
			}
		}
	}

	cout << "Ż��!" << endl;

	return 0;
}