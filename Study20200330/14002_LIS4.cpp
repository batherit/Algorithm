#include<iostream>
#include<stack>
using namespace std;

int A[1001];
int D[1001];
int C[1001];

int main(void) {
	int t;
	cin >> t;

	for (int i = 1; i <= t; i++) {
		cin >> A[i];
	}

	int mx_idx = 0;
	int ret_idx = 0;
	for (int i = 1; i <= t; i++) {
		mx_idx = 0;
		D[i] = 1;
		for (int j = i - 1; j >= 1; j--) {
			if (D[j] > D[mx_idx] && A[j] < A[i]) {
				mx_idx = j;
			}
		}
		D[i] += D[mx_idx];
		if (D[i] > D[ret_idx]) {
			ret_idx = i;
		}
		C[i] = mx_idx;
	}

	stack<int> s;
	while (ret_idx != 0) {
		s.push(A[ret_idx]);
		ret_idx = C[ret_idx];
	}

	cout << s.size() << '\n';
	while (!s.empty()) {
		cout << s.top() << ' ';
		s.pop();
	}

	return 0;
}