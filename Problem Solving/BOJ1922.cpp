/*네트워크연결*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, C;
int parent[1001];
vector<pair<int, pair<int, int>>> networks;
int getParent(int x) {
	if (parent[x] == x)return x;
	else return getParent(parent[x]);
}
int Union(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a < b) {
		parent[b] = a;
		return a;
	}
	else {
		parent[a] = b;
		return b;
	}
}
int Find(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a == b)return 1;
	else return 0;
}

int main() {
	int sum = 0;
	cin >> N >> M;
	for (int i = 1; i <= N; i++)parent[i] = i;

	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		networks.push_back(make_pair(c, make_pair(a, b)));
	}
	sort(networks.begin(), networks.end());

	for (int i = 0; i < networks.size(); i++) {
		if (!Find(networks[i].second.first, networks[i].second.second)) {
			sum += networks[i].first;
			Union(networks[i].second.first, networks[i].second.second);
		}
	}
	cout << sum << endl;
}