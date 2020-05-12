#include<iostream>
using namespace std;

#define ON_FLAG(flags, n)		(flags |= (1 << (n - 1)))
#define OFF_FLAG(flags, n)		(flags &= ~(1 << (n - 1)))
#define TOGGLE_FLAG(flags, n)	(flags ^= (1 << (n - 1)))
#define IS_ON_FLAG(flags, n)	(bool)((flags & (1 << (n - 1))) != 0)

void prt(int data, int byte) {
	for (int i = 8 * byte - 1; i >= 0; i--) {
		cout << ((data & (1 << i)) >> i);
		if (i % 4 == 0) cout << ' ';
	}
}

int main(void) {
	short nFlags = 0;

	ON_FLAG(nFlags, 3);
	ON_FLAG(nFlags, 4);
	prt(nFlags, 2);

	cout << endl;
	cout << IS_ON_FLAG(nFlags, 3);
	cout << endl;

	OFF_FLAG(nFlags, 3);
	OFF_FLAG(nFlags, 5);
	prt(nFlags, 2);

	cout << endl;
	cout << IS_ON_FLAG(nFlags, 3);
	cout << endl;

	// toggle
	TOGGLE_FLAG(nFlags, 5);
	prt(nFlags, 2);
	cout << endl;

	TOGGLE_FLAG(nFlags, 5);
	prt(nFlags, 2);
	cout << endl;

	TOGGLE_FLAG(nFlags, 4);
	prt(nFlags, 2);
	cout << endl;

	TOGGLE_FLAG(nFlags, 4);
	prt(nFlags, 2);
	cout << endl;

	prt(10 << 1, 2);

	return 0;
}