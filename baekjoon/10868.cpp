/*최솟값*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int N, M;
int num[100001];
vector<int> tree;

int makeTree(int node, int s, int e) {
	if (s == e)return tree[node] = num[s];

	int mid = (s + e) / 2;
	/*int left = makeTree(node * 2, s, mid);
	int right = makeTree(node * 2 + 1, mid + 1, e);
	return tree[node] = min(left, right);*/
	return tree[node] = min(makeTree(node * 2, s, mid), makeTree(node * 2 + 1, mid + 1, e));
}

int findMin(int node, int s, int e, int l, int r) {
	if (l > e || r < s)return 1000000000;
	if (l <= s && r >= e)return tree[node];

	int mid = (s + e) / 2;
	return min(findMin(node * 2, s, mid, l, r), findMin(node * 2 + 1 , mid + 1, e, l, r));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++)cin >> num[i];
	int height = (int)ceil(log2(N));
	int tree_size = (1 << (height + 1));
	tree.resize(tree_size);
	makeTree(1, 0, N - 1);

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		cout << findMin(1, 0, N - 1, a - 1, b - 1) << "\n";
	}
}
