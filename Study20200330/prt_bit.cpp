#include<iostream>
#include<stack>
using namespace std;

void prt(char c) {
	for (int i = 7; i <= 0; i--) {
		cout << ((c & (1 << i)) >> i);
	}
}

char conv(int b) {
	char c = 0;

	int tmp = b;
	stack<int> s;

	while (tmp > 0) {
		s.push(tmp % 10);
		tmp /= 10;
	}

	while (!s.empty()) {
		c = c | (s.top() << (s.size() - 1));
		s.pop();
	}

	return c;
}

char conv2(int b) {
	int tmp = b;
	char res = 0;

	stack<int> s;

	while (tmp > 0) {
		s.push(tmp % 10);
		tmp /= 10;
	}

	while (!s.empty()) {
		res *= 2;
		res += (s.top() == 1) ? 1 : 0;
		s.pop();
	}

	return res;
}

void main(void) {
	cout << (int)conv2(1010);
}