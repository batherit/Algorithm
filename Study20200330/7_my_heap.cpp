#include<iostream>
#include<ctime>
using namespace std;

int get_candidate_child(int arr[], int num, int parent) {
	int l_child = 2 * parent + 1;
	int r_child = 2 * parent + 2;

	if (num - 1 < l_child) { 
		// 단말 노드인 경우
		return -1; 
	}
	else if (num - 1 == l_child) {
		// 왼쪽 자식 노드만 있는 경우
		return l_child; 
	}
	else {
		if (arr[l_child] < arr[r_child]) {
			return l_child;
		}
		else {
			return r_child;
		}
	}
}

// 서브트리가 힙 구조를 만족할 때, 진짜 루트 노드를 찾아
// 최상단 노드에 위치시킨다.
void locate_root(int arr[], int num, int root) {
	int parent = root;
	int child;

	while (-1 != (child = get_candidate_child(arr, num, parent))) {
		if (arr[parent] > arr[child]) {
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
	// 전체를 힙구조로 만든다.
	heapify(arr, num, 0);

	for (int i = num - 1; i > 0; i--) {
		swap(arr[0], arr[i]);
		locate_root(arr, i, 0);
	}
}

void prt_arr(int arr[], int num) {
	for (int i = 0; i < num; i++) {
		cout << arr[i] << ' ';
	}
	cout << endl;
}

void set_rand_arr(int arr[], int num) {
	for (int i = 0; i < num; i++) {
		arr[i] = rand() % 50;
	}
}

int main(void) {
	srand((unsigned int)time(nullptr));
	int arr[15];
	int num = 10;

	set_rand_arr(arr, num);
	prt_arr(arr, num);
	my_heap(arr, num);
	prt_arr(arr, num);

	return 0;
}