/*
1.1���� �迭�� ��ġ 2���� �迭 ó�� �ٷ��. 25��¥�� �迭�� �����Ͽ� 2�� for������ 1���� 25���� ������ �ʱ�ȭ �ϰ� ������ ���� ����ϱ�
��, if�� ��� ���� ������ for�����θ�
1	2	3	4	5
6	7	8	9	10
11	12	13	14	15
16	17	18	19	20
21	22	23	24	25
*/

#include<iostream>
using namespace std;

int main(void) {
	int arr[25];

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			arr[i * 5 + j] = i * 5 + j + 1;
		}
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cout << arr[i * 5 + j] << '\t';
		}
		cout << endl;
	}

	return 0;
}