//class
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

class Student {
public:
	string name;
	int score;
	Student(string name, int score) {
		this->name = name;
		this->score = score;
	}
	bool operator < (Student& student) {
		return this->score < student.score;
	}
};

int main(void) {
	Student students[] = {
		Student("A", 90),
		Student("B", 87),
		Student("C", 90),
		Student("D", 60),
		Student("E", 100)
	};
	sort(students, students + 5);
	for (int i = 0; i < 5; i++) {
		cout << students[i].name << ' ';
	}

	return 0;
}