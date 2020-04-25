#include<iostream>
#include<algorithm>
using namespace std;

int main(void) {
	int t;
	cin >> t;

	int arr[8];
	for (int i = 0; i < t; i++) {
		arr[i] = i + 1;
	}

	do {
		for (int i = 0; i < t; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
	} while (next_permutation(arr, arr + t));

	return 0;
}