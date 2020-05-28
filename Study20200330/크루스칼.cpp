// ���� ���� ������� ��� ��带 ����
// �ּ� ��� ���� Ʈ�� -> ���� �� == ��� �� - 1
// ����Ʈ1 : ������ �Ÿ��� ª�� ������� �׷����� ����
// ���� ������ ������������ ������ �ڿ� ����� ���� ��������
// �������� �׷����� ���Խ�Ų��.!
// ����Ʈ2 : ����Ŭ�� �����ϴ� ������ ���Խ�Ű�� �ʴ´�. (���Ͼ����ε� �̿�)

#include<iostream>
#include<vector>
#include<algorithm>
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

class Edge {
public:
	int node[2];
	int cost;
	Edge(int a, int b, int cost) {
		this->node[0] = a;
		this->node[1] = b;
		this->cost = cost;
	}
	bool operator< (Edge& edge) {
		// �������� ����
		return this->cost < edge.cost;
	}
};

int main(void) {
	int n = 7;
	int m = 11;

	vector<Edge> v;
	v.push_back(Edge(1, 7, 12));
	v.push_back(Edge(1, 4, 28));
	v.push_back(Edge(1, 2, 67));
	v.push_back(Edge(1, 5, 17));
	v.push_back(Edge(2, 4, 24));
	v.push_back(Edge(2, 5, 62));
	v.push_back(Edge(3, 5, 20));
	v.push_back(Edge(3, 6, 37));
	v.push_back(Edge(4, 7, 13));
	v.push_back(Edge(5, 6, 45));
	v.push_back(Edge(5, 7, 73));

	// ������ ����� �������� �������� ����
	sort(v.begin(), v.end());

	// �� ������ ���Ե� �׷����� ������� ����
	int parent[10];
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	int sum = 0;
	for (int i = 0; i < v.size(); i++) {
		// ����Ŭ�� �߻����� �ʴ� ��� �׷����� ����
		if (!find_parent(parent, v[i].node[0], v[i].node[1])) {
			sum += v[i].cost;
			// ��� ����
			union_parent(parent, v[i].node[0], v[i].node[1]);
		}
	}

	cout << sum;
}