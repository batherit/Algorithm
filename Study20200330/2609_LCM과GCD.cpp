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
	int a, b;
	cin >> a >> b;
	
	int G = gcd(a, b);
	int L = (a / G) * b;

	cout << G << '\n' << L;

	return 0;
}