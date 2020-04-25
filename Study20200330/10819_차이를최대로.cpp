#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

int cal(int arr[], int n) {
	int sum = 0;
	for (int i = 0; i < n - 1; i++) {
		sum += abs(arr[i] - arr[i + 1]);
	}
	return sum;
}

int main(void) {
	int t;
	cin >> t;
	
	int arr[10];
	for (int i = 0; i < t; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + t);

	int mx = cal(arr, t);	// �ʱ� max�� ����
	while (next_permutation(arr, arr + t)) {
		int ret = cal(arr, t);
		if (ret > mx) {
			mx = ret;
		}
	}

	cout << mx;

	return 0;
}