#include<iostream>
#include<string>
#include<cstring>	//memset
using namespace std;

int pos[30];

int main(void) {
	string str;
	cin >> str;

	memset(pos, -1, sizeof(pos));
	
	for (int i = 0; i < str.size(); i++) {
		if (pos[str[i] - 'a'] == -1) {
			pos[str[i] - 'a'] = i;
		}
		
	}

	for (int i = 0; i < 'z' - 'a' + 1; i++) {
		cout << pos[i] << ' ';
	}

	return 0;
}