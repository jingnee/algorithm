/*최소 스패닝 트리 풀고*/ 
#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;

int V, E;
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
		int64_t answer = 0;
		int cnt = 0;
		int a, b, c;
		cin >> V >> E;
		int *parent = new int[V + 1];
		for (int i = 1; i <= V; i++)parent[i] = i;
		vector<pair<int, pair<int, int>>> edges;

		for (int i = 0; i < E; i++) {
			cin >> a >> b >> c;
			edges.push_back(make_pair(c, make_pair(a, b)));
		}
		sort(edges.begin(), edges.end());

		for (int i = 0; i < edges.size(); i++) {
			if (!Find(parent, edges[i].second.first, edges[i].second.second)) {
				answer += edges[i].first;
				Union(parent, edges[i].second.first, edges[i].second.second);
				cnt++;
				if (cnt == V - 1)break;
			}
		}
		cout << "#" << test_case << " " << answer << endl;
				
	}
}