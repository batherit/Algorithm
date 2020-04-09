#include<iostream>
using namespace std;

bool prime(int a) {
	if (a <= 1) return false;

	for (int i = 2; i * i <= a; i++) {
		if (a % i == 0) return false;
	}
	return true;
}

int main(void) {
	int t;
	cin >> t;

	int cnt = 0;
	int in;
	for (int i = 0; i < t; i++) {
		cin >> in;
		if (prime(in)) cnt++;
	}

	cout << cnt;

	return 0;
}