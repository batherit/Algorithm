// �л� 3��� ����ǥ 1. �Է�, 2. ��ü ��� 3. �˻� 4. ����(����üx, ����üo ����)

#include<iostream>
#include<string>
using namespace std;

const int ciNameSize = 50;
const int ciMaxStudentNum = 3;

typedef struct _student {
	char szName[ciNameSize];
	int iKorGrade;
	int iEngGrade;
	int iMathGrade;
}STUDENT;


const int INPUT = 1;
const int ALL_PRINT = 2;
const int SEARCH = 3;
const int END = 4;
const int ERROR = -1;

void PrintMenu(int iStudentCnt);
int GetMySelect(void);
void PrintStudentInfo(int i, STUDENT sStudents[]);
void InputStudent(int* iStudentCnt, STUDENT sStudents[]);
void PrintAllStudent(int iStudentCnt, STUDENT sStudents[]);
int GetIndexByName(int iStudentCnt, STUDENT sStudents[]);
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

void PrintStudentInfo(int i, STUDENT sStudents[]) {
	cout << "-----" << i + 1 << "��° �л� ����" << "-----" << endl;
	cout << "�̸� : \t" << sStudents[i].szName << endl;
	cout << "���� ���� : " << sStudents[i].iKorGrade << endl;
	cout << "���� ���� : " << sStudents[i].iEngGrade << endl;
	cout << "���� ���� : " << sStudents[i].iMathGrade << endl << endl;
}

void InputStudent(int* iStudentCnt, STUDENT sStudents[]) {
	// �Է�
	if (*iStudentCnt < ciMaxStudentNum) {
		cout << "�л��� �̸��� �Է��ϼ���.";
		cin >> sStudents[*iStudentCnt].szName;

		cout << "���� ������ �Է��ϼ���.";
		cin >> sStudents[*iStudentCnt].iKorGrade;

		cout << "���� ������ �Է��ϼ���.";
		cin >> sStudents[*iStudentCnt].iEngGrade;

		cout << "���� ������ �Է��ϼ���.";
		cin >> sStudents[*iStudentCnt].iMathGrade;

		(*iStudentCnt)++;

		cout << "�л��� ������ �ԷµǾ����ϴ�.";
	}
	else {
		cout << "�� �̻� �л��� ������ �Է��� �� �����ϴ�.";
	}
}

void PrintAllStudent(int iStudentCnt, STUDENT sStudents[]) {
	if (iStudentCnt > 0) {
		for (int i = 0; i < iStudentCnt; i++) {
			PrintStudentInfo(i, sStudents);
		}
	}
	else {
		cout << "��ϵ� �л��� �����ϴ�.";
	}
}

int GetIndexByName(int iStudentCnt, STUDENT sStudents[]) {
	if (iStudentCnt > 0) {
		char szNameToSearch[ciNameSize];
		cout << "�˻��� �л��� �̸��� �Է��ϼ���. :";
		cin >> szNameToSearch;

		for (int i = 0; i < iStudentCnt; i++) {
			if (0 == strcmp(szNameToSearch, sStudents[i].szName)) {
				return i;
			}
		}
	}
	return ERROR;
}

void RunStudentGrade(void) {
	int iStudentCnt = 0;
	STUDENT sStudents[ciMaxStudentNum];

	while (true) {
		system("cls");
		PrintMenu(iStudentCnt);

		switch (GetMySelect())
		{
		case INPUT:
			InputStudent(&iStudentCnt, sStudents);
			break;

		case ALL_PRINT:
			// ��ü ���
			PrintAllStudent(iStudentCnt, sStudents);
			break;
		case SEARCH:
		{
			int iIndex = GetIndexByName(iStudentCnt, sStudents);
			if (iStudentCnt > 0) {
				if (ERROR != iIndex) {
					PrintStudentInfo(iIndex, sStudents);
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
