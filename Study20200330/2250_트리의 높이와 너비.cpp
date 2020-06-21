#include<iostream>
#include<cstring>
using namespace std;

struct _node {
	_node() 
		:
		left(nullptr), 
		right(nullptr) 
	{}
	_node* left;
	_node* right;
};

_node* arr[10001];
int mn[10001];
int mx[10001]; 
int parent[10001];

int col = 1;
int level = 0;

void dfs(_node* root, int depth) {
	if (!root) return;

	dfs(root->left, depth + 1);
	if (mn[depth] == -1) mn[depth] = col;
	// col은 증가만 하므로 새로이 해당 depth에 방문할 경우 mx[depth]는 매번 재갱신.
	mx[depth] = col;
	if (depth > level) level = depth;
	col++;
	dfs(root->right, depth + 1);
}

int main(void) {
	memset(mn, -1, sizeof(mn));
	memset(mx, -1, sizeof(mx));

	int n;
	cin >> n;

	int self, left, right;
	for (int i = 1; i <= n; i++) {
		cin >> self >> left >> right;
		if (!arr[self])		
			arr[self] = new _node;
		if (-1 != left) {
			if (!arr[left]) arr[left] = new _node;
			arr[self]->left = arr[left];
			parent[left] = self;
		}
		if (-1 != right) {
			if (!arr[right]) arr[right] = new _node;
			arr[self]->right = arr[right];
			parent[right] = self;
		}
	}

	int root_idx;
	for (int i = 1; i <= n; i++) {
		if (parent[i] == 0) {
			root_idx = i;
			break;
		}
	}

	dfs(arr[root_idx], 1);

	int ret_depth = 1, ret_width = mx[1] - mn[1] + 1;
	for (int i = 2; i <= level; i++) {
		if (ret_width < mx[i] - mn[i] + 1) {
			ret_depth = i;
			ret_width = mx[i] - mn[i] + 1;
		}
	}

	cout << ret_depth << ' ' << ret_width;

	return 0;
}