/*µµ½Ã ºĞÇÒ °èÈ¹*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<pair<int, pair<int, int>>> edge;
vector<int> roads;
int parent[100001];
int getParent(int x) {
	if (parent[x] == x)return x;
	else return parent[x] = getParent(parent[x]);
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
	int answer = 0;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		edge.push_back(make_pair(c, make_pair(a, b)));
	}
	sort(edge.begin(), edge.end());

	int cnt = 1;			//°£¼±ÀÇ °¹¼ö¸¦ ¼À
	for (int i = 0; i < edge.size(); i++) {
		if (!Find(edge[i].second.first, edge[i].second.second)) {
			Union(edge[i].second.first, edge[i].second.second);
			if (cnt < N - 1) {
				answer += edge[i].first;
				cnt++;
			}
		}
	}
	cout << answer << endl;
}