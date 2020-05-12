#include<iostream>
using namespace std;

void swap(int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
}

bool next_permutation(int *a, int n) {
	// 1. a[i - 1] < a[i]�� �����ϴ� ���� ū i�� ã�´�. 
	// Ex. 7236541 -> i == 3
	int i = n - 1;
	while (i > 0 && a[i - 1] >= a[i]) i -= 1;
	if (i <= 0) return false; // ������ ����
	
	// 2. j >= i�̸鼭 a[j] > a[i - 1]�� �����ϴ� ���� ū j�� ã�´�. 
	// Ex. 7236541 -> a[i - 1 == 2] == 3 < a[j == 5] == 4 -> j == 5
	int j = n - 1;
	while (a[j] <= a[i - 1]) j -= 1;

	// 3. a[i - 1]�� a[j]�� swap�Ѵ�.
	// Ex. 7246531
	swap(a[i - 1], a[j]);  

	// 4. a[i]���� ������ �����´�.
	// Ex, 7241356
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