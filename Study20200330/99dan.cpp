#include<iostream>
using namespace std;

int main(void) {
	int i = 1;
	int j = 1;

	// 9�ܱ��� ���
	while (10 > i) {
		j = 1;
		while (10 > j) {
			cout << i << " * " << j << " = " << i * j << endl;
			j++;
		}
		cout << endl;
		i++;
	}

	return 0;
}