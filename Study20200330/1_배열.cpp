/*
1.1차원 배열을 마치 2차원 배열 처럼 다루기. 25개짜리 배열을 선언하여 2중 for문으로 1부터 25까지 값으로 초기화 하고 다음과 같이 출력하기
단, if문 사용 금지 오로지 for문으로만
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