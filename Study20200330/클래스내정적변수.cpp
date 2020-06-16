#include<iostream>
using namespace std;

// ID 재정의 에러
int CParent::ID = 0;
int CChild1::ID = 10;
int CChild2::ID = 20;

class CParent {
public:
	virtual void Up(void) {
		ID += 1;
	}
public:
	static int ID;
};

class CChild1 {
public:
	virtual void Up(void) {
		ID += 10;
	}
public:
	static int ID;
};

class CChild2 {
public:
	virtual void Up(void) {
		ID += 100;
	}
public:
	static int ID;
};

int main(void) {
	return 0;

	CParent p1;
	p1.Up();
	CParent p2;
	p2.Up();
	CChild1 c11;
	c11.Up();
	CChild1 c12;
	c12.Up();
	CChild2 c21;
	c21.Up();
	CChild2 c22;
	c22.Up();

	cout << CParent::ID << endl;
	cout << CChild1::ID << endl;
	cout << CChild2::ID << endl;
}