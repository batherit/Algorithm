#include<iostream>
using namespace std;

void Swap(int* iN1, int* iN2) {
	int temp = *iN1;
	*iN1 = *iN2;
	*iN2 = temp;
}

int main(void) {
	int iN1, iN2;
	cin >> iN1 >> iN2;
	
	Swap(&iN1, &iN2);

	cout << iN1 << ' ' << iN2;
	
	return 0;
}