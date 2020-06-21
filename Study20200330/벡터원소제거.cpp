#include<iostream>
#include<vector>
using namespace std;

class CFirst {

};

int main(void) {
	vector<CFirst*> v;
	CFirst* search = new CFirst;
	v.push_back(new CFirst);
	v.push_back(search);
	v.push_back(new CFirst);

	vector<CFirst*>::iterator iter = find(v.begin(), v.end(), search);
	if (iter != v.end()) {
		*iter = nullptr;
		v.erase(iter);
	}

	for (auto elem : v) {
		cout << elem << endl;
	}

	return 0;
}