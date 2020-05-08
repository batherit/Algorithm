#include<iostream>
#include<string>
using namespace std;

int main(void) {
	string str;
	str = "abcde";

	cout << str.substr(0, 3) << '\n';	// abc
	cout << str.substr(4, 2) << '\n';	// e?
	cout << str.substr(-1, 1) << '\n';	// abort -> runtime error
	cout << str.substr(5, 1) << '\n';	// ?

	return 0;
}