#include<iostream>
#include<cstring>
using namespace std;

#define ALL_FLAG(flags, size) (flags = (1 << (size * 8)) - 1)
#define EMPTY_FLAG(flags) (flags = 0)
#define ON_FLAG(flags, n) (flags |= (1 << (n - 1)))
#define OFF_FLAG(flags, n) (flags &= ~(1 << (n - 1)))
#define TOGGLE_FLAG(flags, n) (flags ^= (1 << (n - 1)))
#define IS_ON_FLAG(flags, n) (bool)((flags & (1 << (n - 1))) != 0)

enum CMD { ADD, REMOVE, CHECK, TOGGLE, ALL, EMPTY, NONE };

CMD Translate(char* _szInput, int& _iValue) {
	char* szTemp = nullptr;
	szTemp = strtok(_szInput, " ");
	CMD eReturn = NONE;
	if (0 == strcmp(szTemp, "add")) eReturn = ADD;
	else if (0 == strcmp(szTemp, "remove")) eReturn = REMOVE;
	else if (0 == strcmp(szTemp, "check")) eReturn = CHECK;
	else if (0 == strcmp(szTemp, "toggle")) eReturn = TOGGLE;
	else if (0 == strcmp(szTemp, "all")) eReturn = ALL;
	else if (0 == strcmp(szTemp, "empty")) eReturn = EMPTY;

	switch (eReturn)
	{
	case ADD: case REMOVE: case CHECK: case TOGGLE:
		szTemp = strtok(nullptr, " ");
		_iValue = atoi(szTemp);
		return eReturn;
	case ALL: case EMPTY:
		return eReturn;
	default:
		return eReturn;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t;
	cin >> t;
	cin.ignore();

	char szInput[15];
	CMD eCMD;
	int iValue;
	int iBitArr = 0;

	while (t--) {

		cin.getline(szInput, 15);
		eCMD = Translate(szInput, iValue);

		switch (eCMD)
		{
		case ADD:
			ON_FLAG(iBitArr, iValue);
			break;
		case REMOVE:
			OFF_FLAG(iBitArr, iValue);
			break;
		case CHECK:
			cout << (IS_ON_FLAG(iBitArr, iValue) ? 1 : 0) << '\n';
			break;
		case TOGGLE:
			TOGGLE_FLAG(iBitArr, iValue);
			break;
		case ALL:
			ALL_FLAG(iBitArr, sizeof(iBitArr));
			break;
		case EMPTY:
			EMPTY_FLAG(iBitArr);
			break;
		case NONE:
			break;
		default:
			break;
		}
	}

	return 0;
}