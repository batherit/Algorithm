#include<iostream>
#include<ctime>
using namespace std;

int main(void) {
	srand(unsigned(time(nullptr))); // �ð� ������ �θ� ȣ���ϸ� �� ���� ���� ������ �� ���� ����.
	int iRandVal = rand();

	// srand() ȣ��Ǵ� ����, n������ 0���� ����(refresh) !!
	// �ƹ��� �ð��̶� ��ǻ�Ͱ� ���� ������ ������ 1�� ���� ª�� �ֱ��
	// srand()�� ȣ���ϸ� ū ȿ���� ���� ���� ��.

	return 0;
}