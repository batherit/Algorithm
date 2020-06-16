// 학생 3명분 성적표 1. 입력, 2. 전체 출력 3. 검색 4. 종료(구조체x, 구조체o 버젼)

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
	// "비정적 멤버 참조는 특정 개체에 상대적이어야 합니다" 에러가 존재하여
	// 매크로 상수로 사이즈를 지정해주었다.
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
	
	// "this"는 상수식에 사용할 수 없습니다. 에러가 나서
	// 열거형을 사용하였다.
	/*const int INPUT = 1;
	const int ALL_PRINT = 2;
	const int SEARCH = 3;
	const int END = 4;
	const int ERROR = -1;*/

public:
	void PrintMenu() {
		cout << "현재 " << m_iStudentsCnt << "명의 학생 정보가 입력되었습니다." << endl;
		cout << "1. 입력, 2. 전체 출력, 3. 검색, 4. 저장, 5. 종료" << endl;
	}

	int GetMySelect(void) {
		int iSelect;
		cin >> iSelect;
		return iSelect;
	}

	void PrintStudentInfo(int _i) {
		cout << "-----" << _i + 1 << "번째 학생 정보" << "-----" << endl;
		cout << "이름 : \t" << m_pStudentInfos[_i].szName << endl;
		cout << "국어 성적 : " << m_pStudentInfos[_i].iKorGrade << endl;
		cout << "영어 성적 : " << m_pStudentInfos[_i].iEngGrade << endl;
		cout << "수학 성적 : " << m_pStudentInfos[_i].iMathGrade << endl;
		cout << "평균 : " << m_pStudentInfos[_i].dAvg << endl << endl;
	}

	bool IsCorrectInput(void) {
		// 잘못된 입력 체크
		if (cin.fail()) {
			// 오류스트림 초기화
			cin.clear();
			// 입력버퍼 비우기
			cin.ignore(NAME_SIZE + 1, '\n');
			cout << "잘못된 입력입니다!" << endl;
			return false;
		}
		return true;
	}

	void InputGrade(const char* _pSubjectName, int* _pSubjectValue) {
		while (true) {
			cout << _pSubjectName <<" 성적을 입력하세요. : ";
			cin >> *_pSubjectValue;
			if (IsCorrectInput()) break;
		}
	}

	void InputStudentInfos(void) {
		int StudentInfosNumToInput = 0;

		while (true) {
			cout << "입력할 학생 정보의 수를 입력하세요. :";
			cin >> StudentInfosNumToInput;
			if (IsCorrectInput()) break;
		}
		
		if (StudentInfosNumToInput <= 0) {
			cout << "0 이하가 될 수는 없습니다!" << endl;
			system("pause");
			return;
		}

		DEBUG_MESSAGE("동적 할당")
		STUDENT* pNewStudentInfos = new STUDENT[m_iStudentsCnt + StudentInfosNumToInput];

		if (m_pStudentInfos) {
			DEBUG_MESSAGE("값 복사")
			memcpy(pNewStudentInfos, m_pStudentInfos, sizeof(STUDENT) * m_iStudentsCnt);
		}

		int iIndex = 0;
		for (int i = 0; i < StudentInfosNumToInput; i++) {
			cout << "----------" << i + 1 << "번째 학생 정보 입력----------" << endl;
			iIndex = m_iStudentsCnt + i;
			// 입력
			cout << "학생의 이름을 입력하세요. : ";
			cin >> pNewStudentInfos[iIndex].szName;

			InputGrade("국어", &pNewStudentInfos[iIndex].iKorGrade);
			InputGrade("영어", &pNewStudentInfos[iIndex].iEngGrade);
			InputGrade("수학", &pNewStudentInfos[iIndex].iMathGrade);

			pNewStudentInfos[iIndex].dAvg =
				(pNewStudentInfos[iIndex].iKorGrade +
				pNewStudentInfos[iIndex].iEngGrade +
				pNewStudentInfos[iIndex].iMathGrade) / double(SUBJECTS_NUM);

		}
		m_iStudentsCnt += StudentInfosNumToInput;
		
		if (m_pStudentInfos) {
			DEBUG_MESSAGE("기존 공간 삭제")
			DeleteStudentInfos();
		}

		DEBUG_MESSAGE("링크")
		m_pStudentInfos = pNewStudentInfos;

		cout << "학생의 정보가 입력되었습니다.";
	}

	void PrintAllStudent() {
		if (m_iStudentsCnt > 0) {
			for (int i = 0; i < m_iStudentsCnt; i++) {
				PrintStudentInfo(i);
			}
		}
		else {
			cout << "등록된 학생이 없습니다.";
		}
	}

	int GetIndexByName() {
		if (m_iStudentsCnt > 0) {
			char szNameToSearch[NAME_SIZE];
			cout << "검색할 학생의 이름을 입력하세요. :";
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
			cout << "성공적으로 불러왔습니다." << endl;
			system("pause");
		}
		else {
			cout << "불러오기를 실패하였습니다." << endl;
			DEBUG_MESSAGE("저장 폴더가 없는지 확인하십시오.")
		}
	}

	void SaveDatas(void) {
		FILE* fp = nullptr;
		errno_t err = fopen_s(&fp, SAVE_DATA_DIRECTORY, "wb");

		if (0 == err) {
			fwrite(&m_iStudentsCnt, sizeof(int), 1, fp);
			fwrite(m_pStudentInfos, sizeof(STUDENT), m_iStudentsCnt, fp);
			fclose(fp);
			cout << "성공적으로 저장하였습니다.";
		}
		else {
			cout << "저장을 실패하였습니다." << endl;
			DEBUG_MESSAGE("저장 폴더가 없는지 확인하십시오.")
		}
	}

	bool CheckContinue(void) {
		if (IsSaveDatasExist()) {
			int iSelect;

			while (true) {
				system("cls");
				cout << "세이브 파일이 존재합니다. 이어서 작업하시겠습니까? (1-YES, 2-NO)" << endl;
				cin >> iSelect;

				switch (iSelect) {
				case 1: return true;
				case 2: return false;
				default:
					cout << "잘못된 입력입니다!" << endl;
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
				// 전체 출력
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
						cout << "등록되지 않은 학생입니다.";
					}
				}
				else cout << "등록된 학생이 없습니다.";
			}
			break;
			case SAVE:
				SaveDatas();
				break;
			case END:
				DeleteStudentInfos();
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
private:
	int m_iStudentsCnt = 0;
	STUDENT* m_pStudentInfos = nullptr;
};

int main(void) {
	CStudentGradeManager tStudentGradeManager;
	tStudentGradeManager.Run();

	return 0;
}










