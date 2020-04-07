#include<iostream>
using namespace std;

int prime[100];		// 소수 저장
int pn = 0;			// 소수의 개수
bool check[101];	// 지워졌으면 true
int n = 100;		// 100까지 소수

// O(NloglogN)
int main(void) {
	for (int i = 2; i <= n; i++) {
		if (check[i] == false) {
			prime[pn++] = i;
			// j = i * i에서 i가 백만이면 i * i는 1조가 되기 때문에, int로 처리를 못하는 경우가 존재한다.
			// 따라서, i * 2로 바꾸는 것이 좋다.
			for (int j = i * i; j <= n; j += i) {
				check[j] = true;
			}
		}
	}

	return 0;
}