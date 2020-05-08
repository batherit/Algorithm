#include<iostream>
#include<iomanip>
#include<stack>
#include<string>
using namespace std;

double arr[30];

bool isoper(char ch) {
	if (ch == '+') return true;
	else if (ch == '-') return true;
	else if (ch == '*') return true;
	else if (ch == '/') return true;
	return false;
}

int main(void) {
	int n;
	cin >> n;

	string str;
	cin >> str;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	stack<double> s;
	double oper1, oper2;
	for (int i = 0; i < str.size(); i++) {
		if (!isoper(str[i])) s.push(arr[str[i] - 'A']);
		else {
			oper2 = s.top(); s.pop();
			oper1 = s.top(); s.pop();
			switch (str[i])
			{
			case '+':
				s.push(oper1 + oper2);
				break;
			case '-':
				s.push(oper1 - oper2);
				break;
			case '*':
				s.push(oper1 * oper2);
				break;
			case '/':
				s.push(oper1 / oper2);
				break;
			}
		}
	}
	cout << fixed << setprecision(2) << s.top();

	return 0;
}