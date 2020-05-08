#include<iostream>
#include<string>
using namespace std;

int main(void) {
	string str;

	while (getline(cin, str)) {
		int lower = 0;
		int upper = 0;
		int digit = 0;
		int space = 0;
		for (auto ch : str) {
			if (islower(ch)) lower++;
			else if (isupper(ch)) upper++;
			else if (isdigit(ch)) digit++;
			else if (isspace(ch)) space++;
		}

		cout << lower << ' ' << upper << 
			' ' << digit << ' ' << space << '\n';
	}

	return 0;
}