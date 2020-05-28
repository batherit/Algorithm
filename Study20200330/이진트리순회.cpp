// ���� �ڷᱸ��
// �������� Ž�� �ӵ� ������ ���� ����ϴ� ����
#include<iostream>
using namespace std;

const int ciNumber = 15;

// �ϳ��� ��� ������ ����.
typedef struct node *treePointer;
typedef struct node {
	int data;
	treePointer leftChild, rightChild;
} node;

// ���� ��ȸ ����
void preorder(treePointer ptr) {
	if (ptr) {
		cout << ptr->data << ' ';
		preorder(ptr->leftChild);
		preorder(ptr->rightChild);
	}
}

// ���� ��ȸ ����
void inorder(treePointer ptr) {
	if (ptr) {
		inorder(ptr->leftChild);
		cout << ptr->data << ' ';
		inorder(ptr->rightChild);
	}
}

// ���� ��ȸ ����
void postorder(treePointer ptr) {
	if (ptr) {
		postorder(ptr->leftChild);
		postorder(ptr->rightChild);
		cout << ptr->data << ' ';
	}
}

int main(void) {
	node nodes[ciNumber + 1];
	for (int i = 1; i <= ciNumber; i++) {
		nodes[i].data = i;
		nodes[i].leftChild = nullptr;
		nodes[i].rightChild = nullptr;
	}

	for (int i = 1; i <= ciNumber; i++) {
		if (i % 2 == 0) {
			nodes[i / 2].leftChild = &nodes[i];
		}
		else {
			nodes[i / 2].rightChild = &nodes[i];
		}
	}

	preorder(&nodes[1]);
	cout << endl;
	inorder(&nodes[1]);
	cout << endl;
	postorder(&nodes[1]);
}