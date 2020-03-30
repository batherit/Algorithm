#include<iostream>
using namespace std;

int main(void) {
	int a, b;
	
	while (cin >> a >> b /*동일 표현 : EOF != scanf("%d %d", &A, &B)*/) {
		cout << a + b << '\n';
	}

	return 0;
}