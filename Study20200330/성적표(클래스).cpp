// �л� 3��� ����ǥ 1. �Է�, 2. ��ü ��� 3. �˻� 4. ����(����üx, ����üo ����)

#include<iostream>
#include<cstring>
using namespace std;

inline void ShowDebugMessage(const char* szMessage) {
#ifdef _DEBUG
	cout << "[SYSTEM_DEBUG] " << szMessage << endl;
#endif
}

#define DEBUG_MESSAGE(str) ShowDebugMessage(str);

class CStudentGradeManager {
private:
	// "������ ��� ������ Ư�� ��ü�� ������̾�� �մϴ�" ������ �����Ͽ�
	// ��ũ�� ����� ����� �������־���.
	//const int ciNameSize = 50;
	//const int ciMaxStudentNum = 3;

#define NAME_SIZE				50
#define MAX_STUDENT_NUM			3
#define SUBJECTS_NUM			3
#define SAVE_DATA_DIRECTORY		"../SaveData/StudentGradeInfos.dat"

	enum E_MENU { INPUT = 1, ALL_PRINT, SEARCH, SAVE, END, ERROR = -1 };

	typedef struct _student {
		char szName[NAME_SIZE];
		int iKorGrade;
		int iEngGrade;
		int iMathGrade;
		double dAvg;
	}STUDENT;
	
	// "this"�� ����Ŀ� ����� �� �����ϴ�. ������ ����
	// �������� ����Ͽ���.
	/*const int INPUT = 1;
	const int ALL_PRINT = 2;
	const int SEARCH = 3;
	const int END = 4;
	const int ERROR = -1;*/

public:
	void PrintMenu() {
		cout << "���� " << m_iStudentsCnt << "���� �л� ������ �ԷµǾ����ϴ�." << endl;
		cout << "1. �Է�, 2. ��ü ���, 3. �˻�, 4. ����, 5. ����" << endl;
	}

	int GetMySelect(void) {
		int iSelect;
		cin >> iSelect;
		return iSelect;
	}

	void PrintStudentInfo(int _i) {
		cout << "-----" << _i + 1 << "��° �л� ����" << "-----" << endl;
		cout << "�̸� : \t" << m_pStudentInfos[_i].szName << endl;
		cout << "���� ���� : " << m_pStudentInfos[_i].iKorGrade << endl;
		cout << "���� ���� : " << m_pStudentInfos[_i].iEngGrade << endl;
		cout << "���� ���� : " << m_pStudentInfos[_i].iMathGrade << endl;
		cout << "��� : " << m_pStudentInfos[_i].dAvg << endl << endl;
	}

	bool IsCorrectInput(void) {
		// �߸��� �Է� üũ
		if (cin.fail()) {
			// ������Ʈ�� �ʱ�ȭ
			cin.clear();
			// �Է¹��� ����
			cin.ignore(NAME_SIZE + 1, '\n');
			cout << "�߸��� �Է��Դϴ�!" << endl;
			return false;
		}
		return true;
	}

	void InputGrade(const char* _pSubjectName, int* _pSubjectValue) {
		while (true) {
			cout << _pSubjectName <<" ������ �Է��ϼ���. : ";
			cin >> *_pSubjectValue;
			if (IsCorrectInput()) break;
		}
	}

	void InputStudentInfos(void) {
		int StudentInfosNumToInput = 0;

		while (true) {
			cout << "�Է��� �л� ������ ���� �Է��ϼ���. :";
			cin >> StudentInfosNumToInput;
			if (IsCorrectInput()) break;
		}
		
		if (StudentInfosNumToInput <= 0) {
			cout << "0 ���ϰ� �� ���� �����ϴ�!" << endl;
			system("pause");
			return;
		}

		DEBUG_MESSAGE("���� �Ҵ�")
		STUDENT* pNewStudentInfos = new STUDENT[m_iStudentsCnt + StudentInfosNumToInput];

		if (m_pStudentInfos) {
			DEBUG_MESSAGE("�� ����")
			memcpy(pNewStudentInfos, m_pStudentInfos, sizeof(STUDENT) * m_iStudentsCnt);
		}

		int iIndex = 0;
		for (int i = 0; i < StudentInfosNumToInput; i++) {
			cout << "----------" << i + 1 << "��° �л� ���� �Է�----------" << endl;
			iIndex = m_iStudentsCnt + i;
			// �Է�
			cout << "�л��� �̸��� �Է��ϼ���. : ";
			cin >> pNewStudentInfos[iIndex].szName;

			InputGrade("����", &pNewStudentInfos[iIndex].iKorGrade);
			InputGrade("����", &pNewStudentInfos[iIndex].iEngGrade);
			InputGrade("����", &pNewStudentInfos[iIndex].iMathGrade);

			pNewStudentInfos[iIndex].dAvg =
				(pNewStudentInfos[iIndex].iKorGrade +
				pNewStudentInfos[iIndex].iEngGrade +
				pNewStudentInfos[iIndex].iMathGrade) / double(SUBJECTS_NUM);

		}
		m_iStudentsCnt += StudentInfosNumToInput;
		
		if (m_pStudentInfos) {
			DEBUG_MESSAGE("���� ���� ����")
			DeleteStudentInfos();
		}

		DEBUG_MESSAGE("��ũ")
		m_pStudentInfos = pNewStudentInfos;

		cout << "�л��� ������ �ԷµǾ����ϴ�.";
	}

	void PrintAllStudent() {
		if (m_iStudentsCnt > 0) {
			for (int i = 0; i < m_iStudentsCnt; i++) {
				PrintStudentInfo(i);
			}
		}
		else {
			cout << "��ϵ� �л��� �����ϴ�.";
		}
	}

	int GetIndexByName() {
		if (m_iStudentsCnt > 0) {
			char szNameToSearch[NAME_SIZE];
			cout << "�˻��� �л��� �̸��� �Է��ϼ���. :";
			cin >> szNameToSearch;

			for (int i = 0; i < m_iStudentsCnt; i++) {
				if (0 == strcmp(szNameToSearch, m_pStudentInfos[i].szName)) {
					return i;
				}
			}
		}
		return ERROR;
	}

	/*void DeleteStudentInfos(STUDENT* _ppStudentInfos[]) {
		if (*_ppStudentInfos) {
			delete[] *_ppStudentInfos;
			*_ppStudentInfos = nullptr;
		}
	}*/

	void DeleteStudentInfos(void) {
		if (m_pStudentInfos) {
			delete[] m_pStudentInfos;
			m_pStudentInfos = nullptr;
		}
	}

	bool IsSaveDatasExist(void) {
		FILE* fp = nullptr;
		errno_t err = fopen_s(&fp, SAVE_DATA_DIRECTORY, "rb");
		if (fp) fclose(fp);
		
		if (0 == err) return true;
		else return false;
	}

	void LoadDatas(void) {
		FILE* fp = nullptr;
		errno_t err = fopen_s(&fp, SAVE_DATA_DIRECTORY, "rb");

		if (0 == err) {
			fread(&m_iStudentsCnt, sizeof(int), 1, fp);
			m_pStudentInfos = new STUDENT[m_iStudentsCnt];
			fread(m_pStudentInfos, sizeof(STUDENT), m_iStudentsCnt, fp);
			fclose(fp);
			cout << "���������� �ҷ��Խ��ϴ�." << endl;
			system("pause");
		}
		else {
			cout << "�ҷ����⸦ �����Ͽ����ϴ�." << endl;
			DEBUG_MESSAGE("���� ������ ������ Ȯ���Ͻʽÿ�.")
		}
	}

	void SaveDatas(void) {
		FILE* fp = nullptr;
		errno_t err = fopen_s(&fp, SAVE_DATA_DIRECTORY, "wb");

		if (0 == err) {
			fwrite(&m_iStudentsCnt, sizeof(int), 1, fp);
			fwrite(m_pStudentInfos, sizeof(STUDENT), m_iStudentsCnt, fp);
			fclose(fp);
			cout << "���������� �����Ͽ����ϴ�.";
		}
		else {
			cout << "������ �����Ͽ����ϴ�." << endl;
			DEBUG_MESSAGE("���� ������ ������ Ȯ���Ͻʽÿ�.")
		}
	}

	bool CheckContinue(void) {
		if (IsSaveDatasExist()) {
			int iSelect;

			while (true) {
				system("cls");
				cout << "���̺� ������ �����մϴ�. �̾ �۾��Ͻðڽ��ϱ�? (1-YES, 2-NO)" << endl;
				cin >> iSelect;

				switch (iSelect) {
				case 1: return true;
				case 2: return false;
				default:
					cout << "�߸��� �Է��Դϴ�!" << endl;
					system("pause");
					break;
				}
			}
		}
		return false;
	}

	void Run() {
		if (CheckContinue()) {
			LoadDatas();
		}

		while (true) {
			system("cls");
			PrintMenu();

			switch (GetMySelect())
			{
			case INPUT:
				InputStudentInfos();
				break;
			case ALL_PRINT:
				// ��ü ���
				PrintAllStudent();
				break;
			case SEARCH:
			{
				int iIndex = GetIndexByName();
				if (m_iStudentsCnt > 0) {
					if (ERROR != iIndex) {
						PrintStudentInfo(iIndex);
					}
					else {
						cout << "��ϵ��� ���� �л��Դϴ�.";
					}
				}
				else cout << "��ϵ� �л��� �����ϴ�.";
			}
			break;
			case SAVE:
				SaveDatas();
				break;
			case END:
				DeleteStudentInfos();
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
private:
	int m_iStudentsCnt = 0;
	STUDENT* m_pStudentInfos = nullptr;
};

int main(void) {
	CStudentGradeManager tStudentGradeManager;
	tStudentGradeManager.Run();

	return 0;
}










