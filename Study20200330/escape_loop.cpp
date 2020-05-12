#include<iostream>
using namespace std;

int main(void) {
	// try - catch 문을 사용하여 탈출
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
		cout << "탈출!" << endl;
	}

	// goto 문을 사용하여 탈출
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
	cout << "탈출!" << endl;

	// check 변수를 이용하여 탈출
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

	cout << "탈출!" << endl;

	return 0;
}