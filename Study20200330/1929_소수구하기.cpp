//#include<iostream>
//using namespace std;
//
//bool prime[1000001];
//
//int main(void) {
//	int a, b;
//	cin >> a >> b;
//
//	for (int i = 2; i <= b; i++) {
//		if (prime[i] == false) {
//			if (i >= a) cout << i << '\n';
//			// i * i 으로 하면 i 가 백만일 시 i*i이 오버플로우되기 때문에 i + i로 시도하는게 바람직.
//			for (int j = i + i; j <= b; j += i) {
//				prime[j] = true;
//			}
//		}
//	}
//
//	return 0;
//}

#include<iostream>
using namespace std;

bool prime[1000001];

int main(void) {
	prime[1] = true;

	int a, b;
	cin >> a >> b;

	for (int i = 2; i * i <= b; i++) {
		if (prime[i] == false) {
			for (int j = i * i; j <= b; j += i) {
				prime[j] = true;
			}
		}
	}

	for (int i = a; i <= b; i++) {
		if (prime[i] == false) {
			cout << i << '\n';
		}
	}

	return 0;
}