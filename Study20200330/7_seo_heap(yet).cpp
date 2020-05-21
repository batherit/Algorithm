#include<iostream>
using namespace std;


// arr[k]�� ��Ʈ�� �ϴ� Ʈ���� �������� �����ϵ��� �����Ѵ�.
// arr[k]�� �� �ڽ��� ��Ʈ�� �ϴ� �� ����Ʈ���� �������� �����ϰ� �ִ�.
// n�� �ִ� �ε���(��ü �迭�� ũ��)
void heapify(int arr[], int num, int k) {
	int l_child = 2 * k;
	int r_child = 2 * k + 1;
	int smaller;

	// ���� �ڽ� ����, smaller : arr[l_child]�� arr[r_child] �߿� ���� ���� �ε���
	if (r_child <= num) {
		// k�� �� �ڽ��� ������ ���
		if (arr[l_child] < arr[r_child]) {
			smaller = l_child;
		}
		else {
			smaller = r_child;
		}
	}
	else if (l_child <= num) smaller = l_child;	// k�� ���� �ڽĸ� �ִ� ���
	else return;	// k�� ���������

	// ����� ���� (�����)
	if (arr[smaller] < arr[k]) {
		swap(arr[k], arr[smaller]);
		heapify(arr, num, smaller);
	}
 }

// �� �����
void build_heap(int arr[], int num) {
	for (int i = num / 2; i >= 1; i--) {
		heapify(arr, num, i);
	}
}

// arr[1...num]�� �����Ѵ�.
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