#include<iostream>
using namespace std;

struct _node {
	_node(char _data) 
		: 
		data(_data),
		left(nullptr),
		right(nullptr)
	{}
	char data;
	_node* left;
	_node* right;
};

_node* arr[30];

void preorder(_node* root) {
	if (root == nullptr) return;
	cout << root->data;
	preorder(root->left);
	preorder(root->right);
}

void inorder(_node* root) {
	if (root == nullptr) return;
	inorder(root->left);
	cout << root->data;
	inorder(root->right);
}

void postorder(_node* root) {
	if (root == nullptr) return;
	postorder(root->left);
	postorder(root->right);
	cout << root->data;
}

int main(void) {
	int n;
	cin >> n;

	char data, left, right;
	for (int i = 0; i < n; i++) {
		cin >> data >> left >> right;
		if (!arr[data - 'A'])
			arr[data - 'A'] = new _node(data);
		if (left != '.') {
			if (!arr[left - 'A']) arr[left - 'A'] = new _node(left);
			arr[data - 'A']->left = arr[left - 'A'];
		}
		if (right != '.') {
			if (!arr[right - 'A']) arr[right - 'A'] = new _node(right);
			arr[data - 'A']->right = arr[right - 'A'];
		}
	}

	preorder(arr[0]);
	cout << endl;
	inorder(arr[0]);
	cout << endl;
	postorder(arr[0]);

	return 0;
}