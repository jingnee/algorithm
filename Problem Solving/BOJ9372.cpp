/*상근이의 여행*/
#include<iostream>
#include<vector>
using namespace std;

int N, M;
int getParent(int parent[], int x) {
	if (parent[x] == x)return x;
	else return parent[x] = getParent(parent, parent[x]);
}

int Union(int parent[], int a, int b) {
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a < b) {
		parent[b] = a;
		return a;
	}
	else {
		parent[a] = b;
		return b;
	}
}

int Find(int parent[], int a, int b) {
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a == b)return 1;
	else return 0;
}

int main() {
	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		cin >> N >> M;
		vector<pair<int, int>> bridges;
		int *parent = new int[N+1];
		int sum = 0;
		for (int i = 1; i <= N; i++) {
			parent[i] = i;
		}

		for (int i = 0; i < M; i++) {
			int a, b;
			cin >> a >> b;
			bridges.push_back(make_pair(a, b));
		}

		for (int i = 0; i < bridges.size(); i++) {
			if (!Find(parent, bridges[i].first, bridges[i].second)) {
				Union(parent, bridges[i].first, bridges[i].second);
				sum++;
			}
		}

		cout << sum << endl;

	}
}
