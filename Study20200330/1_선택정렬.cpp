// O(N^2)
#include <iostream>
using namespace std;

void selection(int arr[], int num) {
	for (int i = 0; i < num - 1; i++) {
		int min = i;
		for (int j = i + 1; j < num; j++) {
			if (arr[j] < arr[min]) {
				min = j;
			}
		}
		swap(arr[i], arr[min]);
	}
}

void selection(const char* arr[], int num) {
	for (int i = 0; i < num - 1; i++) {
		int min = i;
		for (int j = i + 1; j < num; j++) {
			if (strcmp(arr[j], arr[min]) < 0) {
				min = j;
			}
		}
		swap(arr[i], arr[min]);
	}
}

int main(void) {
	//const char* arr[] = { "담비", "나비", "가리비" };
	int arr[] = { 10, 2, 4, 6, 8, 6, 1 };

	int num = sizeof(arr) / sizeof(int);
	selection(arr, num);

	for (int i = 0; i < num; i++) {
		cout << arr[i] << ' ';
	}
}