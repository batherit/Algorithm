#include<iostream>
using namespace std;

int main(void) {
	const int* ptr1;		// �������� ������ ���� �Ұ�, ������ ������ ���� ����
	int* const ptr2;		// �������� ������ ���� ����, ������ ������ ���� �Ұ� => ����� �ʱ�ȭ ���ÿ� �� �ʿ�
	const int* const ptr3;	// �������� ������ ���� �Ұ�, ������ ������ ���� �Ұ� => ����� �ʱ�ȭ ���ÿ� �� �ʿ�
	return 0;
}