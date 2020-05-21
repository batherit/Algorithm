#include<iostream>
using namespace std;

int get_candidate_child(int arr[], int num, int parent) {
	int l_child = 2 * parent + 1;
	int r_child = 2 * parent + 2;

	if (num - 1 < l_child) {
		// �ܸ� ����� ���
		return -1;
	}
	else if (num - 1 == l_child) {
		// ���� �ڽ� ��常 �ִ� ���
		return l_child;
	}
	else {
		if (arr[l_child] > arr[r_child]) {
			return l_child;
		}
		else {
			return r_child;
		}
	}
}

// ����Ʈ���� �� ������ ������ ��, ��¥ ��Ʈ ��带 ã��
// �ֻ�� ��忡 ��ġ��Ų��.
void locate_root(int arr[], int num, int root) {
	int parent = root;
	int child;

	while (-1 != (child = get_candidate_child(arr, num, parent))) {
		if (arr[parent] </*����*/ arr[child]) {
			swap(arr[parent], arr[child]);
			parent = child;
		}
		else break;
	}
}

void heapify(int arr[], int num, int parent) {
	int l_child = 2 * parent + 1;
	int r_child = 2 * parent + 2;

	if (num - 1 >= l_child) {
		heapify(arr, num, l_child);
		heapify(arr, num, r_child);
		locate_root(arr, num, parent);
	}
}

void my_heap(int arr[], int num) {
	// ��ü�� �������� �����.
	heapify(arr, num, 0);

	for (int i = num - 1; i > 0; i--) {
		swap(arr[0], arr[i]);
		locate_root(arr, i, 0);
	}
}

int main(void) {
	int arr[10001];/*00*/
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	my_heap(arr, n);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << '\n';
	}

	return 0;
}