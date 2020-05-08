#include<iostream>
using namespace std;

void swap(int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
}

bool next_permutation(int *a, int n) {
	// 1. a[i - 1] < a[i]를 만족하는 가장 큰 i를 찾는다.
	int i = n - 1;
	while (i > 0 && a[i - 1] >= a[i]) i -= 1;
	if (i <= 0) return false; // 마지막 순열
	
	// 2. j >= i이면서 a[j] > a[i - 1]를 만족하는 가장 큰 j를 찾는다.
	int j = n - 1;
	while (a[j] <= a[i - 1]) j -= 1;

	// 3. a[i - 1]과 a[j]를 swap한다.
	swap(a[i - 1], a[j]); 

	// 4. a[i]부터 순열을 뒤집는다.
	j = n - 1;
	while (i < j) {
		swap(a[i], a[j]);
		i += 1; j -= 1;
	}
	return true;
}

int main(void) {
	return 0;
}