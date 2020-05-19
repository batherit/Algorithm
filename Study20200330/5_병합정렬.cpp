// 퀵정렬과 다르게 항상 O(NlogN) 만족 => 정확히 반을 자르기 때문.
// 일단 반으로 쪼개고 나중에 합친다는 특징. => 쪼개져 있는 정렬이 되어있는 두 집합(O(logN))을 합치는 과정에서 다시 정렬(O(N))
#include <iostream>
using namespace std;

int arr[1001];

void merge(int *start, int *end) {
	if (start >= end - 1) return;

	int count = end - start;
	int *middle = (count - 1) / 2 + start;
	merge(start, middle + 1);
	merge(middle + 1, end);

	int i = 0, j = 0, k = 0;
	while (start + i < middle + 1 && middle + 1 + j < end) {
		if (*(start + i) < *(middle + 1 + j)) {
			arr[k++] = start[i++];
		}
		else arr[k++] = (middle + 1)[j++];
	}

	if (start + i >= middle + 1) {
		while (middle + 1 + j < end) arr[k++] = (middle + 1)[j++];
	}

	if (middle + 1 + j >= end) {
		while (start + i < middle + 1) arr[k++] = start[i++];
	}

	for (int i = 0; i < count; i++) {
		start[i] = arr[i];
	}
}

int main(void) {
	int ar[5] = { 3, 1, 3, 5, 0 };

	merge(ar, ar + 5);

	for (int i = 0; i < 5; i++) {
		cout << ar[i] << ' ';
	}


	return 0;
}