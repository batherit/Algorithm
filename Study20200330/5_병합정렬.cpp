// �����İ� �ٸ��� �׻� O(NlogN) ���� => ��Ȯ�� ���� �ڸ��� ����.
// �ϴ� ������ �ɰ��� ���߿� ��ģ�ٴ� Ư¡. => �ɰ��� �ִ� ������ �Ǿ��ִ� �� ����(O(logN))�� ��ġ�� �������� �ٽ� ����(O(N))
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