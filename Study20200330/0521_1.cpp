#include<iostream>
#include<string>
#include<cstring>
using namespace std;

void Input_Student(char* pStudentName) {
	char szInputName[32] = "";
	cout << "�Է� : ";
	cin >> szInputName;
	strcpy_s(pStudentName, strlen(szInputName) + 1, szInputName);
}

int main(void) {
	char szStudentName[32];
	Input_Student(szStudentName);
	cout << szStudentName << endl;

	char szName1[64] = "Hello C";
	char szName2[64] = "++ World";

	strcat_s(szName1, szName2);
	cout << szName1 << endl;

	char szStr[32] = "���ΰ���!";
	string strStr;

	strStr = szStr;				// ����
	//szStr = strStr;				// �Ұ��� 1. �迭 �̸� szStr�� �迭 �ּҷμ� ������ ���x, 2. Ÿ���� �ٸ���. 
	//szStr = strStr.c_str();		// �Ұ��� 1. �迭 �̸� szStr�� �迭 �ּҷμ� ������ ���x, 2. szStr = "���ΰ���!"�� ���� ǥ��
	strcpy_s(szStr, strStr.length() + 1, strStr.c_str());
}