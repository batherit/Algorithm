// 평균 속도 O(NlogN) why. 분할 정복 알고리즘
/*
특정한 값(피봇)을 기준으로 쿤 수자와 작은 숫자의 집합으로 나눈다. => 빠른 이유
보통 맨 앞의 값을 피봇으로 삼음.
*/

#include <iostream>
using namespace std;

void quick(int arr[], int left, int right) {
	int pivot = left;
	int l = left + 1;
	int r = right;

	if (l > r) return;
	while (l <= r) {
		while (l <= r && arr[l] <= arr[pivot]) l++;
		while (l <= r && arr[r] >= arr[pivot]) r--;
		if (l <= r) swap(arr[l], arr[r]);
		else {
			swap(arr[pivot], arr[r]);
			break;
		}
	}
	quick(arr, left, r - 1);
	quick(arr, r + 1, right);
}



int main(void) {
	int arr[] = { 4, 3, 1, 5, 3 };

	int num = sizeof(arr) / sizeof(int);
	quick(arr, 0, num - 1);

	for (int i = 0; i < num; i++) {
		cout << arr[i] << ' ';
	}
}