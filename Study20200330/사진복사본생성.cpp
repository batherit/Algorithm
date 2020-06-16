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
	// ������ ���α׷��� ���� �޸𸮿� �ӽ� �����Ѵ�.
	FILE* fpRead = nullptr;
	FILE* fpWrite = nullptr;
	errno_t err = 0;

	int iImageNameLen = strlen(_szImageName);
	char szOnlyImageName[NAME_SIZE];
	char szExtensionName[EXTENSION_NAME_SIZE] = "";

	// ���ϸ�� Ȯ���ڸ� �и�
	for (int i = iImageNameLen - 1; i >= 0 ; i--) {
		if ('.' == _szImageName[i]) {
			strncpy_s(szOnlyImageName, _szImageName, i);
			strncpy_s(szExtensionName, &_szImageName[i], iImageNameLen - i);
			break;
		}
	}

	// Ȯ���� ���� ���� üũ
	if (0 == strlen(szExtensionName)) {
		cout << "Ȯ���ڰ� �Էµ��� �ʾҽ��ϴ�!" << endl;
		system("pause");
		return false;
	}

	// ���� �б� ��Ʈ���� �����Ѵ�.
	char szDirectory[DIRECTORY_SIZE + NAME_SIZE + EXTENSION_NAME_SIZE];
	strncpy_s(szDirectory, "../CopyZone/", strlen("../CopyZone/") + 1);
	strcat_s(szDirectory, _szImageName);
	err = fopen_s(&fpRead, szDirectory, "rb");
	if (0 != err) {
		cout << "���� �о���� ����!" << endl;
		system("pause");
		return false;
	}

	// ���� ���� ��Ʈ���� �����Ѵ�.
	memset(szDirectory, 0, sizeof(szDirectory));
	strncpy_s(szDirectory, "../CopyZone/", strlen("../CopyZone/") + 1);
	strcat_s(szDirectory, szOnlyImageName);
	strcat_s(szDirectory, "_���纻");
	strcat_s(szDirectory, szExtensionName);
	err = fopen_s(&fpWrite, szDirectory, "wb");
	if (0 != err) {
		cout << "���� ���纻 ���� ����!" << endl;
		system("pause");
		return false;
	}

	// ���� �б� ��Ʈ�����κ��� ���� ������ �ִ� BUFFER_MAX_SIZE��ŭ �о�´�.
	// ���� ���� ��Ʈ���� ���� ������ �ִ� BUFFER_MAX_SIZE��ŭ ����.
	char szBuffer[BUFFER_MAX_SIZE];
	while (!feof(fpRead)) {
		fread(szBuffer, sizeof(char), BUFFER_MAX_SIZE, fpRead);
		fwrite(szBuffer, sizeof(char), BUFFER_MAX_SIZE, fpWrite);
		// fputc(fgetc(fpRead), fpWrite);
	}

	// ������ �ݴ´�.
	fclose(fpRead);
	fclose(fpWrite);

	//�Ϸ�!
	cout << "���� ���纻 ���� �Ϸ�!" << endl;
	system("pause");
	return true;
}

void RunCreateCopy(void) {
	char szImageName[NAME_SIZE + EXTENSION_NAME_SIZE];

	while (true) {
		system("cls");
		cout << "Ȯ���ڸ� �����Ͽ� ī���� ���� ���ϸ��� �Է��ϼ���. " << endl;
		cin >> szImageName;

		CreateCopy(szImageName);
	}
}

// ���� - �׸� �����ϱ� - ���̳ʸ� ������� ���� ������ �ؽ��ĸ� ���Ϻ����ϱ�. . 
// 2��° - �ؽ�Ʈ������ ���� �ҷ����� ��� ���� - 
// ����ġ ���� ����. 