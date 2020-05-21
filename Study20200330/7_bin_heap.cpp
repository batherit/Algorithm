// 상향식 구현 방식
#include<iostream>
#include<ctime>
using namespace std;

void set_rand_arr(int arr[], int num) {
	for (int i = 0; i < num; i++) {
		arr[i] = rand() % 50;
	}
}

void heap_up(int arr[], int num) {
	// 힙을 구성
	for (int i = 1; i < num; i++) {
		int child = i;
		do {
			int parent = (child - 1) / 2;
			if (arr[parent] < arr[child]) {
				swap(arr[parent], arr[child]);
			}
			child = parent;
		} while (child != 0); // 0은 루트를 의미함.
	}

	// 크기를 줄여가며 반복적으로 힙을 구성
	for (int i = num - 1; i >= 0; i--) {
		// 루트 원소와 맨 마지막 원소를 스왑한다.
		swap(arr[0], arr[i]);
		int parent = 0;
		int child = 1;
		do {
			// 왼쪽 자식을 찾는다.
			child = 2 * parent + 1;
			if (child < i - 1 && arr[child] < arr[child + 1]) {
				// 오른쪽 자식값이 왼쪽 자식값보다 크다면
				// 오른쪽 자식 노드로 타겟을 변경한다.
				child++;
			}

			// 부모보다 자식이 크다면 교환한다.
			if (child < i && arr[parent] < arr[child]) {
				swap(arr[parent], arr[child]);
			}
			// 하향식 접근
			parent = child;
		} while (child < i);
	}
}

void heapify(int arr[], int num, int i) {
	// 왼쪽 자식을 찾는다.
	int child = 2 * i + 1;

	if (child < num && arr[child] < arr[child + 1]) {
		// 오른쪽 자식 노드가 있고, 왼쪽 자식 노드보다 크다면
		// 오른쪽 자식 노드로 타겟을 변경한다.
		child++;
	}

	// 부모보다 자식이 더 크다면 서로 교환한다.
	if (arr[i] < arr[child]) {
		swap(arr[i], arr[child]);
	}

	// num / 2까지만 수행한다.
	if (child <= num / 2) heapify(arr, num, child);
}

void heap_down(int arr[], int num) {
	// 힙을 생성한다.
	for (int i = num / 2; i >= 0; i--) {
		heapify(arr, num, i);
	}

	// 정렬을 수행한다.
	for (int i = num - 1; i >= 0; i--) {
		// 루트 노드와 마지막 노드를 서로 스왑한다.
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