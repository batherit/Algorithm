#include<iostream>
#include<algorithm>
using namespace std;

bool cmp(int a, int b) {
	return a > b; // 내림차순
}

int main(void) {
	int arr[] = { 3, 5, 1, 9 };
	int e_n = sizeof(arr) / sizeof(int);
	sort(arr, arr + e_n, cmp);
	for (int i = 0; i < e_n; i++) {
		cout << arr[i] << ' ';
	}
}