#include<iostream>
#include<string>
using namespace std;

int main(void) {
	string str;
	getline(cin, str);

	for (auto &ch : str) {
		if (isupper(ch)) {
			ch = ((ch - 'A') + 13) % 26 + 'A';
		}
		else if (islower(ch)) {
			ch = ((ch - 'a') + 13) % 26 + 'a';
		}
	}
	cout << str;

	return 0;
}