#include<iostream>
#include<string>
using namespace std;

int to_int(char ch) {
	int ret = ch - '0';

	if (0 <= ret && ret <= 9) return ch - '0';
	else return ch - 'A' + 10;
}

int sol(const string& n, int b) {
	// b������ ���� n�� 10�������� ǥ���Ѵ�.
	int q = to_int(n[0]);

	for (int i = 1; i < n.size(); i++) {
		q = b * q + to_int(n[i]);
	}

	return q;
}

int main(void) {
	string n;
	int b;
	cin >> n >> b; // n�� b������ ���̴�.

	cout << sol(n, b);

	return 0;
}