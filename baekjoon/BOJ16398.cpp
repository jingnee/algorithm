/*행성 연결*/
#include <iostream>
#include <queue>
using namespace std;

priority_queue<pair<int, pair<int, int>>> que;
int map[1001][1001];
int N;
int parent[1001];

int GetParent(int x) {
	if (parent[x] == x)return parent[x];
	else return parent[x] = GetParent(parent[x]);
}
int UnionParent(int a, int b) {
	a = GetParent(a);
	b = GetParent(b);
	if (a < b) {
		parent[b] = a;
		return a;
	}
	else {
		parent[a] = b;
		return b;
	}
}
bool FindParent(int a, int b) {
	a = GetParent(a);
	b = GetParent(b);
	if (a == b)return true;
	else return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)parent[i] = i;
	int n;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> n;
			if (i == j)continue;
			que.push(make_pair(-n, make_pair(i, j)));
		}
	}

	long long sum = 0;
	while (!que.empty()) {
		pair<int, pair<int, int>> temp;
		temp = que.top();
		int num = -temp.first;
		que.pop();
		if (!FindParent(temp.second.first, temp.second.second)) {
			sum += num;
			UnionParent(temp.second.first, temp.second.second);
		}
	}
	cout << sum << "\n";
}
