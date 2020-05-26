// ���μ� ���� �˰����̶�� ��.
// ���� ���� ��尡 ������ �� �� ���� ��带 �����ؼ� ���� �� �� ��尡
// ���� ���� �׷����� ���ϴ��� �Ǻ��ϴ� �˰���
// Union -> ��ħ : ���� �θ�� ��ħ
// Find -> ã�� : ���� �θ� ���ϴ��� ã�� == ���� �׷����� ���ϴ��� ã��


#include<iostream>
using namespace std;

// �θ� ��带 ã�� �Լ�
int get_parent(int parent[], int x) {
	if (parent[x] == x) return x;
	return parent[x] = get_parent(parent, parent[x]); // ���� �θ� ã�� ���� �ö󰣴�.
}

// �� �θ� ��带 ��ġ�� �Լ�
void union_parent(int parent[], int a, int b) {
	a = get_parent(parent, a);
	b = get_parent(parent, b);

	if (a < b) parent[b] = a;
	else parent[a] = b;
}

// ���� �θ� �������� Ȯ��
bool find_parent(int parent[], int a, int b) {
	a = get_parent(parent, a);
	b = get_parent(parent, b);
	
	if (a == b) return true;
	return false;
}

int main(void) {
	int parent[11];
	for (int i = 1; i <= 10; i++) {
		// �������� ���ҵ�� �ִٰ� ����
		parent[i] = i;
	}

	union_parent(parent, 1, 2);
	union_parent(parent, 2, 3);
	union_parent(parent, 3, 4);
	union_parent(parent, 5, 6);
	union_parent(parent, 6, 7);
	union_parent(parent, 7, 8);
	
	cout << "1�� 5�� ����Ǿ� �ֽ��ϱ�? " << find_parent(parent, 1, 5) << endl;
	union_parent(parent, 1, 5);
	cout << "1�� 5�� ����Ǿ� �ֽ��ϱ�? " << find_parent(parent, 1, 5) << endl;
}