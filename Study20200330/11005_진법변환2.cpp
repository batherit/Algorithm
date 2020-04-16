#include<iostream>
#include<string>
#include<stack>
using namespace std;

char to_char(int n) {
	if (0 <= n && n <= 9) return n + '0';
	else return n - 10 + 'A';
}

string sol(int n, int b) {
	// 10�������� ǥ���� �� n�� b������ ���� ǥ���Ѵ�.
	string result;
	
	stack<char> s;
	while (n != 0) {
		s.push(to_char(n % b));
		n /= b;
	}

	while (!s.empty()) {
		result.push_back(s.top());
		s.pop();
	}

	return result;
}

int main(void) {
	int n, b;
	cin >> n >> b;

	cout << sol(n, b);

	return 0;
}