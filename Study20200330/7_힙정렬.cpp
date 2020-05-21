// O(NlogN)
// 힙 트리 구조를 이용한다.
// 힙 트리 구조 => 완전 이진 트리 구조 이용
// 최대힙 : 부모노드가 자식노드보다 큰 값을 지님. <-> 최소힙
/*
힙 생성 알고리즘(Heapify) 
// O(logN) => 한 번 수행하면 최대 높이까지 진행
// N개의 노드에 대해 실행하므로, 전체 최대힙을 구성하는데 O(NlogN)의 시간이 걸린다.
- 단 하나의 노드에서만 실행
- 단 하나의 노드를 제외하고는 최대/최소 힙이 구성되어 있는 상태
- 최대힙일 경우, 자식이 본인보다 큰 값을 지니면 서로 교체한다.
*/
/*
힙 정렬
- 힙은 다음의 과정을 거쳐 정렬한다.
1. 힙 생성 알고리즘을 각 원소마다 진행
2. 루트노드와 마지막 노드를 교환한다.
3. 마지막 노드를 제외하고 힙 생성 알고리즘을 진행한다.
4. 루트노드까지 정렬될 때까지 2와 3을 반복한다.
=> 최대힙일 경우, 오름차순 정렬이 된다.
*/

#include <iostream>
using namespace std;

int num = 9;
int heap[9] = { 7, 6, 5, 8, 3, 5, 9, 1, 6 };

int main(void) {
	// Max Heapify 
	for (int i = 1; i < num; i++) {
		int child = i;
		do {
			int parent = (child - 1) / 2;	// 자식의 부모 찾기
			// 하향식 방식으로 힙구조 구성 (상향식도 가능)
			if (heap[parent] < heap[child]) {
				swap(heap[parent], heap[child]);
			}
			child = parent; // 위로 올라간다.
		} while (child != 0);
	}
	// 크기를 줄여가며 반복적으로 힙을 구성
	for (int i = num - 1; i >= 0; i--) {
		swap(heap[0], heap[i]);	// 가장 큰 값을 맨 뒤로 보낸다.
		int parent = 0; // root부터 시작한다.
		int child = 1;
		do {
			child = 2 * parent + 1; // 왼쪽 자식을 찾는다.
			// 자식 중에 더 큰 값을 찾기
			// child + 1 < i : 오른쪽 자식 노드가 범위 내 존재함을 보장.
			if (heap[child] < heap[child + 1] && child + 1 < i) {
				child++;
			}
			// 루트보다 자식이 더 크다면 교환
			if (heap[parent] < heap[child] && child < i) {
				swap(heap[child], heap[parent]);
			}
			parent = child; // 아래로 내려간다.
		} while (child < i);
	}
	for (int i = 0; i < num; i++) {
		cout << heap[i] << ' ';
	}
}