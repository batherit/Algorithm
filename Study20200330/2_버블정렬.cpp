// O(N^2) => �Ź� ���� ������ ��ġ�� ������ �������ĺ��� �� ��ȿ����
// �ڿ������� ���ĵȴٴ� Ư¡�� ����.
#include<iostream>
using namespace std;

void bubble(int arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - 1 - i; j++) {
			if (arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
		}
	}
}

int main(void) {
	int arr[5] = { 5, 3, 2, 1, 5 };

	int num = sizeof(arr) / sizeof(int);
	bubble(arr, num);

	for (int i = 0; i < 5; i++) {
		cout << arr[i] << ' ';
	}

	return 0;
}