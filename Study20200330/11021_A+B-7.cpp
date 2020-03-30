#include <iostream>
using namespace std;

int main(void) {
	int t;
	cin >> t;
	
	int a, b;
	for (int i = 0; i < t; i++) {
		cin >> a >> b;
		cout << "Case #" << i + 1 << ": " << a + b << '\n';
	}

	return 0;
}