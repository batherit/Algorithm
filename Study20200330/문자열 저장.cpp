#include<iostream>
using namespace std;

int main(void) {
	FILE* fp = nullptr;
	errno_t err = fopen_s(&fp, "../SaveData.txt", "wt");

	char szSave[64] = "«œ¿Ãø∞~!";
	if (!err) {
		fwrite(&szSave, sizeof(szSave), 1, fp);
		fclose(fp);
	}
	
	err = fopen_s(&fp, "../SaveData.txt", "rt");
	char szLoad[64];
	if (!err) {
		fread(&szLoad, sizeof(szLoad), 1, fp);
		fclose(fp);
	}

	cout << szLoad;

	return 0;
}
