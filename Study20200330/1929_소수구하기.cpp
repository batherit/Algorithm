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
//			// i * i ���� �ϸ� i �� �鸸�� �� i*i�� �����÷ο�Ǳ� ������ i + i�� �õ��ϴ°� �ٶ���.
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