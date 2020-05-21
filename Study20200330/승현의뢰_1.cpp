#include<iostream>
using namespace std;

char* str = "Hello C world";

bool read_cpy(char* read_data) {
	*((char**)read_data) = str;
	return true;
}

int main(void) {
	char* str1 = nullptr;

	read_cpy((char*)&str1);
	
	cout << str1;

	return 0;
}