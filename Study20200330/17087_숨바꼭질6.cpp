#include<iostream>
#include<stack>
#include<cmath>
using namespace std;

int gcd(int a, int b) {
	if (b == 0) return a;
	else return gcd(b, a%b);
}

int main(void) {
	int n, s;
	cin >> n >> s;

	stack<int> st;
	int in;
	while (n--) {
		cin >> in;
		st.push(abs(in - s));
	}

	int a, b;
	while (st.size() > 1) {
		a = st.top(); st.pop();
		b = st.top(); st.pop();
		st.push(gcd(a, b));
	}

	cout << st.top();

	return 0;
}