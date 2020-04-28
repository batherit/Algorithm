#include<iostream>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	n = 2 * n - 1;
	int cnt = n;

	bool tog = false;
	
	while (cnt <= n) {
		for (int i = 0; i < (n - cnt) / 2; i++) {
			cout << ' ';
		}
		for (int i = 0; i < cnt; i++) {
			cout << '*';
		}
		cout << '\n';
		if (cnt == 1) tog = true;
		if (tog) cnt += 2;
		else cnt -= 2;
	}

	return 0;
}