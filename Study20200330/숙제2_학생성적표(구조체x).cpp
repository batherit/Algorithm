// �л� 3��� ����ǥ 1. �Է�, 2. ��ü ��� 3. �˻� 4. ����(����üx, ����üo ����)

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
	cout << "���� " << iStudentCnt << "���� �л� ������ �ԷµǾ����ϴ�." << endl;
	cout << "1. �Է�, 2. ��ü ���, 3. �˻�, 4. ����" << endl;
}

int GetMySelect(void) {
	int iSelect;
	cin >> iSelect;
	return iSelect;
}

void PrintStudentInfo(int i, char szName[][ciNameSize], int iKorGrade[], int iEngGrade[], int iMathGrade[]) {
	cout << "-----" << i + 1 << "��° �л� ����" << "-----" << endl;
	cout << "�̸� : \t" << szName[i] << endl;
	cout << "���� ���� : " << iKorGrade[i] << endl;
	cout << "���� ���� : " << iEngGrade[i] << endl;
	cout << "���� ���� : " << iMathGrade[i] << endl << endl;
}

void InputStudent(int* iStudentCnt, char szName[][ciNameSize], int iKorGrade[], int iEngGrade[], int iMathGrade[]) {
	// �Է�
	if (*iStudentCnt < ciMaxStudentNum) {
		cout << "�л��� �̸��� �Է��ϼ���.";
		cin >> szName[*iStudentCnt];

		cout << "���� ������ �Է��ϼ���.";
		cin >> iKorGrade[*iStudentCnt];

		cout << "���� ������ �Է��ϼ���.";
		cin >> iEngGrade[*iStudentCnt];

		cout << "���� ������ �Է��ϼ���.";
		cin >> iMathGrade[*iStudentCnt];

		(*iStudentCnt)++;

		cout << "�л��� ������ �ԷµǾ����ϴ�.";
	}
	else {
		cout << "�� �̻� �л��� ������ �Է��� �� �����ϴ�.";
	}
}

void PrintAllStudent(int iStudentCnt, char szName[][ciNameSize], int iKorGrade[], int iEngGrade[], int iMathGrade[]) {
	if (iStudentCnt > 0) {
		for (int i = 0; i < iStudentCnt; i++) {
			PrintStudentInfo(i, szName, iKorGrade, iEngGrade, iMathGrade);
		}
	}
	else {
		cout << "��ϵ� �л��� �����ϴ�.";
	}
}

int GetIndexByName(int iStudentCnt, char szName[][ciNameSize]) {
	if (iStudentCnt > 0) {
		char szNameToSearch[ciNameSize];
		cout << "�˻��� �л��� �̸��� �Է��ϼ���. :";
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
			// ��ü ���
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
					cout << "��ϵ��� ���� �л��Դϴ�.";
				}
			}
			else cout << "��ϵ� �л��� �����ϴ�.";
		}
		break;
		case END:
			cout << "���α׷��� �����մϴ�.";
			return;
		default:
			cout << "�߸��� �Է��Դϴ�.";
			break;
		}
		cout << endl;
		system("pause");
	}
}