#include<iostream>
#include<algorithm>
using namespace std;

int price[1001];

int main(void) {
	int t;
	cin >> t;

	for (int i = 1; i <= t; i++) {
		cin >> price[i];
		for (int j = 1; j < i; j++) {
			price[i] = min(price[i - j] + price[j], price[i]);
		}
	}
	cout << price[t];

	return 0;
}