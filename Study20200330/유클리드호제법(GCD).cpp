#include<iostream>
using namespace std;

int gcd1(int a, int b) {
	if (b == 0) return a;
	else return gcd1(b, a%b);
}

int gcd2(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main(void) {

	cout << gcd(16, 24);

	return 0;
}