#include<iostream>
#include<algorithm>
using namespace std;

int main(void) {
	int a, b;
	cin >> a >> b;

	int g = 1;
	for (int i = 2; i <= min(a, b); i++) {
		if (a%i == 0 && b % i == 0) {
			g = i;
		}
	}

	return 0;
}