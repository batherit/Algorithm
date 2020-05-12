#include<iostream>
using namespace std;

int main(void) {

	int i = 0;
START:
	cout << i << endl;
	if (i >= 3) {
		goto END;
	}
	i++;

	goto START;
END:

	return 0;
}