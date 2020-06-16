#include<iostream>
using namespace std;

void bubble(int arr[], int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - 1 - i; j++) {
			if (arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);
		}
	}
}

int main(void) {
	//char ch1 = 0;
	//char ch2 = 0;
	//cout << sizeof(10.0 + 10) << endl;

	////for(int i = 0; i < 5)

	//int arr[2][2];

	//cout << (int)arr - (int)(arr + 1) << endl;
	//cout << sizeof(*(arr + 0)) << endl;

	/*int n;
	cin >> n;

	for (int i = 0; i < n / 2; i++) {
		for (int j = 0; j < n / 2 - i; j++) {
			cout << " ";
		}
		for (int j = 0; j < 2 * (i + 1) - 1; j++) {
			cout << "*";
		}
		cout << endl;
	}

	for (int i = n / 2 + 1 ; i > 0; i--) {
		for (int j = 0; j < n / 2 + 1 - i; j++) {
			cout << " ";
		}
		for (int j = 0; j < (2 * i - 1); j++) {
			cout << "*";
		}
		cout << endl;
	}

	int arr[] = { 5, 1, 8 };
	bubble(arr, 3);
	for (int i = 0; i < 3; i++) {
		cout << arr[i] << ' ';
	}*/

	//int arr[2][2] = {
	//	{1, 0},
	//	{3, 2}
	//};

	//int(*parr)[2] = arr;
	//
	//cout << *arr[1] << endl;	// 3이 나올 것이다.
	//cout << (*arr)[1] << endl;	// 0이 나올 것이다.

	return 0;
}