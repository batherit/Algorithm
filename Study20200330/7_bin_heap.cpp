// ����� ���� ���
#include<iostream>
#include<ctime>
using namespace std;

void set_rand_arr(int arr[], int num) {
	for (int i = 0; i < num; i++) {
		arr[i] = rand() % 50;
	}
}

void heap_up(int arr[], int num) {
	// ���� ����
	for (int i = 1; i < num; i++) {
		int child = i;
		do {
			int parent = (child - 1) / 2;
			if (arr[parent] < arr[child]) {
				swap(arr[parent], arr[child]);
			}
			child = parent;
		} while (child != 0); // 0�� ��Ʈ�� �ǹ���.
	}

	// ũ�⸦ �ٿ����� �ݺ������� ���� ����
	for (int i = num - 1; i >= 0; i--) {
		// ��Ʈ ���ҿ� �� ������ ���Ҹ� �����Ѵ�.
		swap(arr[0], arr[i]);
		int parent = 0;
		int child = 1;
		do {
			// ���� �ڽ��� ã�´�.
			child = 2 * parent + 1;
			if (child < i - 1 && arr[child] < arr[child + 1]) {
				// ������ �ڽİ��� ���� �ڽİ����� ũ�ٸ�
				// ������ �ڽ� ���� Ÿ���� �����Ѵ�.
				child++;
			}

			// �θ𺸴� �ڽ��� ũ�ٸ� ��ȯ�Ѵ�.
			if (child < i && arr[parent] < arr[child]) {
				swap(arr[parent], arr[child]);
			}
			// ����� ����
			parent = child;
		} while (child < i);
	}
}

void heapify(int arr[], int num, int i) {
	// ���� �ڽ��� ã�´�.
	int child = 2 * i + 1;

	if (child < num && arr[child] < arr[child + 1]) {
		// ������ �ڽ� ��尡 �ְ�, ���� �ڽ� ��庸�� ũ�ٸ�
		// ������ �ڽ� ���� Ÿ���� �����Ѵ�.
		child++;
	}

	// �θ𺸴� �ڽ��� �� ũ�ٸ� ���� ��ȯ�Ѵ�.
	if (arr[i] < arr[child]) {
		swap(arr[i], arr[child]);
	}

	// num / 2������ �����Ѵ�.
	if (child <= num / 2) heapify(arr, num, child);
}

void heap_down(int arr[], int num) {
	// ���� �����Ѵ�.
	for (int i = num / 2; i >= 0; i--) {
		heapify(arr, num, i);
	}

	// ������ �����Ѵ�.
	for (int i = num - 1; i >= 0; i--) {
		// ��Ʈ ���� ������ ��带 ���� �����Ѵ�.
		swap(arr[0], arr[i]);

		int parent = 0;
		int child = 1;
		do {
			child = 2 * parent + 1;
			if (child < i - 1 && arr[child] < arr[child + 1]) {
				child++;
			}
			if (child < i && arr[parent] < arr[child]) {
				swap(arr[parent], arr[child]);
			}
			parent = child;
		} while (child < i);
	}
}

void prt_arr(int arr[], int num) {
	for (int i = 0; i < num; i++) {
		cout << arr[i] << ' ';
	}
	cout << endl;
}


int main(void) {
	srand((unsigned int)time(nullptr));
	int arr[15];
	int num = 10;

	set_rand_arr(arr, num);
	prt_arr(arr, num);
	heap_up(arr, num);
	prt_arr(arr, num);
	cout << "--------------------" << endl;

	set_rand_arr(arr, num);
	prt_arr(arr, num);
	heap_down(arr, num);
	prt_arr(arr, num);


	return 0;
}