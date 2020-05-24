#include<iostream>
using namespace std;

typedef struct _inner {
	int c;
	int d;
}INNER;

typedef struct _test1 {
	char a;
	char b;
	
	INNER inner;
}TEST;

int main(void) {
	cout << sizeof(TEST) << endl;
	return 0;
}