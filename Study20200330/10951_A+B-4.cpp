#include<iostream>
using namespace std;

int main(void) {
	int a, b;
	
	while (cin >> a >> b /*���� ǥ�� : EOF != scanf("%d %d", &A, &B)*/) {
		cout << a + b << '\n';
	}

	return 0;
}