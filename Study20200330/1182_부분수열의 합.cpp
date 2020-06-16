#include<iostream>
using namespace std;

int arr[21];

int main(void) {
	int n, s;
	cin >> n >> s;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int cnt = 0;
	// 공집합을 제외하므로 i는 1부터 시작한다.
	// n개 비트의 모든 부분집합의 개수는 (1 << n) - 1이다.
	// 참고로 첫 비트의 인덱스는 0으로 간주한다.
	// 즉 n개 비트의 인덱스 범위는 0~n-1이다.
	// (i <= (1 << n) - 1) == (i < (1 << n))
	for (int i = 1; i <= (1 << n) - 1; i++) {
		int sum = 0;
		// 0번째 비트부터 n-1번째 비트를 검사한다.
		for (int j = 0; j < n; j++) {
			// 해당 비트가 켜져있다면 그 인덱스의 배열값을 더한다.
			if (0 != (i & (1 << j))) sum += arr[j];
		}
		if (sum == s) cnt++;
	}

	cout << cnt;

	return 0;
}