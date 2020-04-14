#include<iostream>
using namespace std;

int main(void) {
	int t;
	cin >> t;

	for (int i = 2; t > 1; i++) {
		while (t % i == 0) {
			cout << i << '\n';
			t /= i;
		}
	}

	return 0;
}