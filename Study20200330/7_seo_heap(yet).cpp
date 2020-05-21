#include<iostream>
using namespace std;


// arr[k]를 루트로 하는 트리를 힙성질을 만족하도록 수선한다.
// arr[k]의 두 자식을 루트로 하는 두 서브트리는 힙성질을 만족하고 있다.
// n은 최대 인덱스(전체 배열의 크기)
void heapify(int arr[], int num, int k) {
	int l_child = 2 * k;
	int r_child = 2 * k + 1;
	int smaller;

	// 작은 자식 고르기, smaller : arr[l_child]와 arr[r_child] 중에 작은 원소 인덱스
	if (r_child <= num) {
		// k가 두 자식을 가지는 경우
		if (arr[l_child] < arr[r_child]) {
			smaller = l_child;
		}
		else {
			smaller = r_child;
		}
	}
	else if (l_child <= num) smaller = l_child;	// k의 왼쪽 자식만 있는 경우
	else return;	// k가 리프노드임

	// 재귀적 조정 (하향식)
	if (arr[smaller] < arr[k]) {
		swap(arr[k], arr[smaller]);
		heapify(arr, num, smaller);
	}
 }

// 힙 만들기
void build_heap(int arr[], int num) {
	for (int i = num / 2; i >= 1; i--) {
		heapify(arr, num, i);
	}
}

// arr[1...num]을 정렬한다.
void heap(int arr[], int num) {
	build_heap(arr, num);
	for (int i = num; i > 1; i--) {
		swap(arr[1], arr[i]);
		heapify(arr, i - 1, 1);
	}
}

int main(void) {
	return 0;
}