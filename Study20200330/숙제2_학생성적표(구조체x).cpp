// 학생 3명분 성적표 1. 입력, 2. 전체 출력 3. 검색 4. 종료(구조체x, 구조체o 버젼)

#include<iostream>
#include<string>
using namespace std;

const int ciNameSize = 50;
const int ciMaxStudentNum = 3;

const int INPUT = 1;
const int ALL_PRINT = 2;
const int SEARCH = 3;
const int END = 4;
const int ERROR = -1;

void PrintMenu(int iStudentCnt);
int GetMySelect(void);
void PrintStudentInfo(int i, char szName[][ciNameSize], int iKorGrade[], int iEngGrade[], int iMathGrade[]);
void InputStudent(int* iStudentCnt, char szName[][ciNameSize], int iKorGrade[], int iEngGrade[], int iMathGrade[]);
void PrintAllStudent(int iStudentCnt, char szName[][ciNameSize], int iKorGrade[], int iEngGrade[], int iMathGrade[]);
int GetIndexByName(int iStudentCnt, char szName[][ciNameSize]);
void RunStudentGrade(void);

int main(void) {
	RunStudentGrade();

	return 0;
}




















void PrintMenu(int iStudentCnt) {
	cout << "현재 " << iStudentCnt << "명의 학생 정보가 입력되었습니다." << endl;
	cout << "1. 입력, 2. 전체 출력, 3. 검색, 4. 종료" << endl;
}

int GetMySelect(void) {
	int iSelect;
	cin >> iSelect;
	return iSelect;
}

void PrintStudentInfo(int i, char szName[][ciNameSize], int iKorGrade[], int iEngGrade[], int iMathGrade[]) {
	cout << "-----" << i + 1 << "번째 학생 정보" << "-----" << endl;
	cout << "이름 : \t" << szName[i] << endl;
	cout << "국어 성적 : " << iKorGrade[i] << endl;
	cout << "영어 성적 : " << iEngGrade[i] << endl;
	cout << "수학 성적 : " << iMathGrade[i] << endl << endl;
}

void InputStudent(int* iStudentCnt, char szName[][ciNameSize], int iKorGrade[], int iEngGrade[], int iMathGrade[]) {
	// 입력
	if (*iStudentCnt < ciMaxStudentNum) {
		cout << "학생의 이름을 입력하세요.";
		cin >> szName[*iStudentCnt];

		cout << "국어 성적을 입력하세요.";
		cin >> iKorGrade[*iStudentCnt];

		cout << "영어 성적을 입력하세요.";
		cin >> iEngGrade[*iStudentCnt];

		cout << "수학 성적을 입력하세요.";
		cin >> iMathGrade[*iStudentCnt];

		(*iStudentCnt)++;

		cout << "학생의 정보가 입력되었습니다.";
	}
	else {
		cout << "더 이상 학생의 정보를 입력할 수 없습니다.";
	}
}

void PrintAllStudent(int iStudentCnt, char szName[][ciNameSize], int iKorGrade[], int iEngGrade[], int iMathGrade[]) {
	if (iStudentCnt > 0) {
		for (int i = 0; i < iStudentCnt; i++) {
			PrintStudentInfo(i, szName, iKorGrade, iEngGrade, iMathGrade);
		}
	}
	else {
		cout << "등록된 학생이 없습니다.";
	}
}

int GetIndexByName(int iStudentCnt, char szName[][ciNameSize]) {
	if (iStudentCnt > 0) {
		char szNameToSearch[ciNameSize];
		cout << "검색할 학생의 이름을 입력하세요. :";
		cin >> szNameToSearch;

		for (int i = 0; i < iStudentCnt; i++) {
			if (0 == strcmp(szNameToSearch, szName[i])) {
				return i;
			}
		}
	}
	return ERROR;
}

void RunStudentGrade(void) {
	int iStudentCnt = 0;
	char szName[ciMaxStudentNum][ciNameSize];
	int iKorGrade[ciMaxStudentNum];
	int iEngGrade[ciMaxStudentNum];
	int iMathGrade[ciMaxStudentNum];

	while (true) {
		system("cls");
		PrintMenu(iStudentCnt);

		switch (GetMySelect())
		{
		case INPUT:
			InputStudent(&iStudentCnt, szName, iKorGrade, iEngGrade, iMathGrade);
			break;

		case ALL_PRINT:
			// 전체 출력
			PrintAllStudent(iStudentCnt, szName, iKorGrade, iEngGrade, iMathGrade);
			break;
		case SEARCH:
		{
			int iIndex = GetIndexByName(iStudentCnt, szName);
			if (iStudentCnt > 0) {
				if (ERROR != iIndex) {
					PrintStudentInfo(iIndex, szName, iKorGrade, iEngGrade, iMathGrade);
				}
				else {
					cout << "등록되지 않은 학생입니다.";
				}
			}
			else cout << "등록된 학생이 없습니다.";
		}
		break;
		case END:
			cout << "프로그램을 종료합니다.";
			return;
		default:
			cout << "잘못된 입력입니다.";
			break;
		}
		cout << endl;
		system("pause");
	}
}