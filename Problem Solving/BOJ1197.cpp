//최소스패닝트리 (크루스칼 알고리즘)
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int getParent(int parent[], int x) {
	if (parent[x] == x)return x;
	else return parent[x] = getParent(parent,parent[x]);
}

int UnionParent(int parent[], int a, int b) {
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

int FindParent(int parent[], int a, int b) {
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a == b)return 1;
	else return 0;
}

class Edge {
public:
	int node[2];
	int distance;
	Edge(int x, int y, int distance) {
		this->node[0] = x;
		this->node[1] = y;
		this->distance = distance;
	}
	bool operator < (Edge &edge) {
		return this->distance < edge.distance;
	}
};

int V, E;
int main(void) {
	vector<Edge> v;

	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back(Edge(a, b, c));
	}

	sort(v.begin(), v.end());
	int *parent = new int[V];
	for (int i = 0; i < V; i++)
		parent[i] = i;

	int sum = 0;
	for (int i = 0; i < v.size(); i++) {
		if (!FindParent(parent, v[i].node[0]-1, v[i].node[1]-1)) {
			sum += v[i].distance;
			UnionParent(parent, v[i].node[0]-1, v[i].node[1]-1);
		}
	}
	cout << sum;
	return 0;
}
