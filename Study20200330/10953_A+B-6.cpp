#include<iostream>
using namespace std;

int main(void) {
	int t;
	cin >> t;

	char ar[5];
	while (t--) {
		cin >> ar;
		cout << ar[0] - '0' + ar[2] - '0' << '\n';
	}

	return 0;
}