#include<iostream>
#include<cstring>
using namespace std;

#define DIRECTORY_SIZE 10
#define EXTENSION_NAME_SIZE 10
#define NAME_SIZE 128
#define BUFFER_MAX_SIZE 256


bool CreateCopy(const char* _szImageName);
void RunCreateCopy(void);
	

int main(void) {
	RunCreateCopy();

	return 0;
}











bool CreateCopy(const char* _szImageName) {
	// 사진을 프로그램을 통해 메모리에 임시 저장한다.
	FILE* fpRead = nullptr;
	FILE* fpWrite = nullptr;
	errno_t err = 0;

	int iImageNameLen = strlen(_szImageName);
	char szOnlyImageName[NAME_SIZE];
	char szExtensionName[EXTENSION_NAME_SIZE] = "";

	// 파일명과 확장자를 분리
	for (int i = iImageNameLen - 1; i >= 0 ; i--) {
		if ('.' == _szImageName[i]) {
			strncpy_s(szOnlyImageName, _szImageName, i);
			strncpy_s(szExtensionName, &_szImageName[i], iImageNameLen - i);
			break;
		}
	}

	// 확장자 존재 여부 체크
	if (0 == strlen(szExtensionName)) {
		cout << "확장자가 입력되지 않았습니다!" << endl;
		system("pause");
		return false;
	}

	// 사진 읽기 스트림을 생성한다.
	char szDirectory[DIRECTORY_SIZE + NAME_SIZE + EXTENSION_NAME_SIZE];
	strncpy_s(szDirectory, "../CopyZone/", strlen("../CopyZone/") + 1);
	strcat_s(szDirectory, _szImageName);
	err = fopen_s(&fpRead, szDirectory, "rb");
	if (0 != err) {
		cout << "사진 읽어오기 실패!" << endl;
		system("pause");
		return false;
	}

	// 사진 쓰기 스트림을 생성한다.
	memset(szDirectory, 0, sizeof(szDirectory));
	strncpy_s(szDirectory, "../CopyZone/", strlen("../CopyZone/") + 1);
	strcat_s(szDirectory, szOnlyImageName);
	strcat_s(szDirectory, "_복사본");
	strcat_s(szDirectory, szExtensionName);
	err = fopen_s(&fpWrite, szDirectory, "wb");
	if (0 != err) {
		cout << "사진 복사본 생성 실패!" << endl;
		system("pause");
		return false;
	}

	// 사진 읽기 스트림으로부터 사진 파일을 최대 BUFFER_MAX_SIZE만큼 읽어온다.
	// 사진 쓰기 스트림에 사진 파일을 최대 BUFFER_MAX_SIZE만큼 쓴다.
	char szBuffer[BUFFER_MAX_SIZE];
	while (!feof(fpRead)) {
		fread(szBuffer, sizeof(char), BUFFER_MAX_SIZE, fpRead);
		fwrite(szBuffer, sizeof(char), BUFFER_MAX_SIZE, fpWrite);
		// fputc(fgetc(fpRead), fpWrite);
	}

	// 파일을 닫는다.
	fclose(fpRead);
	fclose(fpWrite);

	//완료!
	cout << "사진 복사본 생성 완료!" << endl;
	system("pause");
	return true;
}

void RunCreateCopy(void) {
	char szImageName[NAME_SIZE + EXTENSION_NAME_SIZE];

	while (true) {
		system("cls");
		cout << "확장자를 포함하여 카피할 사진 파일명을 입력하세요. " << endl;
		cin >> szImageName;

		CreateCopy(szImageName);
	}
}

// 숙제 - 그림 복붙하기 - 바이너리 입출력을 통해 임의의 텍스쳐를 파일복사하기. . 
// 2번째 - 텍스트알피지 저장 불러오기 기능 구현 - 
// 경험치 레벨 구현. 