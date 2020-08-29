/*구간 합 구하기*/
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N, M, K;
long long arr[1000001];
vector<long long> treeV;

long long makeT(int node, int s, int e) {
	if (s == e)return treeV[node] = arr[s];

	int mid = (s + e) / 2;
	return treeV[node] = makeT(node * 2, s, mid) + makeT(node * 2 + 1, mid + 1, e);
}

void updateT(int node, int s, int e, int idx, long long diff) {
	if (idx<s || idx>e)return;
	treeV[node] += diff;

	if (s != e) {
		int mid = (s + e) / 2;
		updateT(node * 2, s, mid, idx, diff);
		updateT(node * 2 + 1, mid + 1, e, idx, diff);
	}
}

long long sumT(int node, int s, int e, int l, int r) {
	if (l > e || s > r)return 0;
	if (l <= s && r >= e)return treeV[node];

	int mid = (s + e) / 2;
	return sumT(node * 2, s, mid, l, r) + sumT(node * 2 + 1, mid+1, e, l, r);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K;
	for (int i = 0; i < N; i++)cin >> arr[i];
	int tree_height = (int)ceil(log2(N));
	int tree_size = (1 << (tree_height + 1));
	treeV.resize(tree_size);
	makeT(1, 0, N - 1);

	for (int i = 0; i < M + K; i++) {
		int a;
		long long b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			updateT(1, 0, N - 1, b - 1, c - arr[b - 1]);
			arr[b - 1] = c;
		}
		else cout << sumT(1, 0, N - 1, b - 1, c - 1) << "\n";
	}
}
