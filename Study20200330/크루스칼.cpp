// 가장 적은 비용으로 모든 노드를 연결
// 최소 비용 신장 트리 -> 간선 수 == 노드 수 - 1
// 포인트1 : 간선을 거리가 짧은 순서대로 그래프에 포함
// 간선 정보를 오름차순으로 정렬한 뒤에 비용이 적은 간선부터
// 차근차근 그래프에 포함시킨다.!
// 포인트2 : 사이클을 형성하는 간선은 포함시키지 않는다. (유니언파인드 이용)

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// 부모 노드를 찾는 함수
int get_parent(int parent[], int x) {
	if (parent[x] == x) return x;
	return parent[x] = get_parent(parent, parent[x]); // 최종 부모를 찾아 위로 올라간다.
}

// 두 부모 노드를 합치는 함수
void union_parent(int parent[], int a, int b) {
	a = get_parent(parent, a);
	b = get_parent(parent, b);

	if (a < b) parent[b] = a;
	else parent[a] = b;
}

// 같은 부모를 가지는지 확인
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
		// 오름차순 정렬
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

	// 간선의 비용을 기준으로 오름차순 정렬
	sort(v.begin(), v.end());

	// 각 정점이 포함된 그래프가 어디인지 저장
	int parent[10];
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	int sum = 0;
	for (int i = 0; i < v.size(); i++) {
		// 사이클이 발생하지 않는 경우 그래프에 포함
		if (!find_parent(parent, v[i].node[0], v[i].node[1])) {
			sum += v[i].cost;
			// 노드 연결
			union_parent(parent, v[i].node[0], v[i].node[1]);
		}
	}

	cout << sum;
}