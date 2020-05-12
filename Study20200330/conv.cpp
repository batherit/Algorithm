#include<iostream>
#include<string>
using namespace std;

// n������ ���� 10������ ��ȯ, �ִ� 16����
int ch2int(char ch) {
	if ('A' <= ch && ch <= 'F') return (ch - 'A') + 10;
	else if (isdigit(ch)) return ch - '0';
	else return -1;
}

int conv2dec(string data, int n) {
	int res = 0;
	for (char ch : data) {
		try {
			int tmp;
			tmp = ch2int(ch);
			if (tmp == -1) throw tmp;
		}
		catch (int error) {
			cout << "���� !" << endl;
			return error;
		}
		res = n * res + ch2int(ch);
	}
	return res;
}

int main(void) {
	int n;
	string data;
	cin >> n >> data;

	cout << conv2dec(data, n);

	return 0;
}