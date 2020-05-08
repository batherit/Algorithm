#include<iostream>
#include<ctime>
using namespace std;

void process(void) {
	int res = 0;
	for (int i = 0; i < 10000; i++) {
		for (int j = 0; j < 100000; j++) {
			res = i * j;
		}
	}
}

int main(void) {
	clock_t s, e;
	double res1, res2;

	s = clock();
	process();
	e = clock();
	res1 = (double)(e - s);
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	s = clock();
	process();
	e = clock();
	res2 = (double)(e - s);

	cout << "\n\n\n\n\n\n";
	cout << res1 << ' ' << res2;

	return 0;
}