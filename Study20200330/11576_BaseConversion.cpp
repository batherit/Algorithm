#include<iostream>
#include<stack>
using namespace std;

int main(void) {
	int A, B;
	cin >> A >> B;

	int n;
	cin >> n;

	int ar[30];
	
	unsigned int q;
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}
	q = ar[0];
	for (int i = 1; i < n; i++) {
		q = A * q + ar[i];
	}

	stack<int> s;
	while (q > 0) {
		s.push(q % B);
		q /= B;
	}

	while (!s.empty()) {
		cout << s.top() << ' ';
		s.pop();
	}

	return 0;
}