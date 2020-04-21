#include<iostream>
using namespace std;

int main(void) {
	int e, s, m;
	cin >> e >> s >> m;

	int e_i = 0, s_i = 0, m_i = 0;
	int y = 1;
	while (true) {
		e_i = (y - 1) % 15 + 1;
		s_i = (y - 1) % 28 + 1;
		m_i = (y - 1) % 19 + 1;

		if (e == e_i && s == s_i && m == m_i) break;
		
		y++;
	}
	cout << y;

	return 0;
}