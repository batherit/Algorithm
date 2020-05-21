#include<iostream>
#include<string>
#include<cstring>
using namespace std;

void Input_Student(char* pStudentName) {
	char szInputName[32] = "";
	cout << "입력 : ";
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

	char szStr[32] = "공부공부!";
	string strStr;

	strStr = szStr;				// 가능
	//szStr = strStr;				// 불가능 1. 배열 이름 szStr은 배열 주소로서 대입의 대상x, 2. 타입이 다르다. 
	//szStr = strStr.c_str();		// 불가능 1. 배열 이름 szStr은 배열 주소로서 대입의 대상x, 2. szStr = "공부공부!"와 같은 표현
	strcpy_s(szStr, strStr.length() + 1, strStr.c_str());
}