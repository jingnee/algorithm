//동방 프로젝트(Small)
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int parent[101];
int N, M, ans;
vector<pair<int, int>> vec;

int getParent(int x) {
	if (parent[x] == x)return x;
	return parent[x] = getParent(parent[x]);
}

void Union(int a, int b) {

	for (int i = a; i < b; i++) {
		if (getParent(i) != getParent(i + 1)) {
			parent[getParent(i+1)] = getParent(i);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	
	for (int i = 1; i <= N; i++)parent[i] = i;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		vec.push_back(make_pair(a, b));
	}
	sort(vec.begin(), vec.end());
	for (auto v : vec)Union(v.first, v.second);

	int check = 0;
	for (int i = 1; i <= N; i++) {
		if (parent[i]!=check) {
			check = parent[i];
			ans++;
		}
	}
	cout << ans;
}
