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
	// �������� �����ϹǷ� i�� 1���� �����Ѵ�.
	// n�� ��Ʈ�� ��� �κ������� ������ (1 << n) - 1�̴�.
	// ����� ù ��Ʈ�� �ε����� 0���� �����Ѵ�.
	// �� n�� ��Ʈ�� �ε��� ������ 0~n-1�̴�.
	// (i <= (1 << n) - 1) == (i < (1 << n))
	for (int i = 1; i <= (1 << n) - 1; i++) {
		int sum = 0;
		// 0��° ��Ʈ���� n-1��° ��Ʈ�� �˻��Ѵ�.
		for (int j = 0; j < n; j++) {
			// �ش� ��Ʈ�� �����ִٸ� �� �ε����� �迭���� ���Ѵ�.
			if (0 != (i & (1 << j))) sum += arr[j];
		}
		if (sum == s) cnt++;
	}

	cout << cnt;

	return 0;
}