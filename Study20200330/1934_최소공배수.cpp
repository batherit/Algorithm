#include<iostream>
using namespace std;

int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	else {
		return gcd(b, a%b);
	}
}

int main(void) {
	int t;
	cin >> t;
	
	int a, b, G;
	for (int i = 0; i < t; i++) {
		cin >> a >> b;
		cout << (a / gcd(a, b)) * b << '\n';
	}

	return 0;
}