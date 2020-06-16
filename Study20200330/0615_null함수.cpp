#include<iostream>
using namespace std;

class CFirst {
public:
	virtual void Print() {
		cout << "CFirst" << endl;
	}
};

class CSecond : public CFirst {
public:
	void Print() {
		cout << "CSecond" << endl;
	}
};

int main(void) {
	CFirst* pSecond1 = new CSecond();
	CFirst* pSecond2 = new CSecond();
	pSecond1->Print();
	pSecond2->Print();

	return 0;
}