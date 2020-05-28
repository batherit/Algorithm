// 서로소 집합 알고리즘이라고도 함.
// 여러 개의 노드가 존재할 때 두 개의 노드를 선택해서 현재 이 두 노드가
// 서로 같은 그래프에 속하는지 판별하는 알고리즘
// Union -> 합침 : 같은 부모로 합침
// Find -> 찾음 : 같은 부모에 속하는지 찾음 == 같은 그래프에 속하는지 찾음


#include<iostream>
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

int main(void) {
	int parent[11];
	for (int i = 1; i <= 10; i++) {
		// 개별적인 원소들로 있다고 가정
		parent[i] = i;
	}

	union_parent(parent, 1, 2);
	union_parent(parent, 2, 3);
	union_parent(parent, 3, 4);
	union_parent(parent, 5, 6);
	union_parent(parent, 6, 7);
	union_parent(parent, 7, 8);
	
	cout << "1과 5는 연결되어 있습니까? " << find_parent(parent, 1, 5) << endl;
	union_parent(parent, 1, 5);
	cout << "1과 5는 연결되어 있습니까? " << find_parent(parent, 1, 5) << endl;
}