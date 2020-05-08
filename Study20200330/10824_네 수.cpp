#include<iostream>
#include<string>
using namespace std;

int main(void) {
	string str;
	getline(cin, str);

	string l, r;
	int space = 0;
	for (auto ch : str) {
		if (isdigit(ch)) {
			if (space < 2) {
				l.push_back(ch);
			}
			else {
				r.push_back(ch);
			}
		}
		else if (isspace(ch)) {
			space++;
		}
	}
	cout << stoll(l) + stoll(r);

	return 0;
}