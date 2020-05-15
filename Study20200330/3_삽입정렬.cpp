// O(N) ~ O(N^2)
// 정렬된 경우, 바로 빠져나오기 때문에 최상의 경우 O(N)
#include <iostream>
using namespace std;

void insert(int arr[], int n) {
	for (int i = 1; i < n; i++) {
		int j = i;
		while (j > 0 && arr[j - 1] > arr[j]) {
			swap(arr[j - 1], arr[j]);
			j--;
		}
	}
}

int main(void) {
	int arr[5] = { 5, 1, 2, 5, 3 };

	insert(arr, 5);

	for (int i = 0; i < 5; i++) {
		cout << arr[i] << ' ';
	}

	return 0;
}