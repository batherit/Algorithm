#include<iostream>
using namespace std;

int main(void) {
	// 국영수 총점 평균 학점 100-90 에이 89-80 비 ..시 ..디 그외 에프
	// 국어점수는 몇 점입니다. ...
	// 총점은 몇 점이고 평균은 몇 점이고
	// 학점은 땡땡 학점입니다.

	// 점수 입력부
	int iKor = 0, iEng = 0, iMath = 0;
	cout << "국어 점수를 입력하세요. :";
	cin >> iKor;

	cout << "영어 점수를 입력하세요. :";
	cin >> iEng;

	cout << "수학 점수를 입력하세요. :";
	cin >> iMath;

	cout << "-----[결과]-----" << endl;

	// 총점 및 평균 계산부
	int iTotal = iKor + iEng + iMath;
	float fAvg = iTotal / 3.f;

	// 결과 출력부
	cout << "국어 점수는 " << iKor << "입니다." << endl;
	cout << "영어 점수는 " << iEng << "입니다." << endl;
	cout << "수학 점수는 " << iMath << "입니다." << endl;
	cout << "총점은 " << iTotal << "이며, 평균은 " << fAvg << "입니다." << endl;
	cout << "평균을 따져볼 때, 학점은 ";

	if (fAvg >= 90.f) cout << "'A'";
	else if (fAvg >= 80.f) cout << "'B'";
	else if (fAvg >= 70.f) cout << "'C'";
	else if (fAvg >= 60.f) cout << "'D'";
	else cout << "'F'";

	cout << "입니다.";
	return 0;
}