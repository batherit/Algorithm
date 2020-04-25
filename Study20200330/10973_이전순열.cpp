#include<iostream>
#include<algorithm>
using namespace std;

int main(void) {
	int t;
	cin >> t;
	
	int arr[10001];
	for (int i = 0; i < t; i++) {
		cin >> arr[i];
	}

	if (prev_permutation(arr, arr + t)) {
		for (int i = 0; i < t; i++) {
			cout << arr[i] << ' ';
		}
	}
	else {
		cout << -1;
	}

	return 0;
}