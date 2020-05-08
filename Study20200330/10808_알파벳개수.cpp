#include<iostream>
#include<string>
using namespace std;

int cnt[30];

int main(void) {
	string str;
	cin >> str;

	for (auto ch : str) {
		cnt[ch - 'a']++;
	}

	for (int i = 0; i < 'z' - 'a' + 1; i++) {
		cout << cnt[i] << ' ';
	}

	return 0;
}