/*안정적인 네트워크*/
#include <iostream>
#include <queue>
#include <vector>
#include <utility>
using namespace std;
int parent[1000];
int n, m, miniMum;
priority_queue<pair<int,pair<int, int>>> computers;
vector<pair<int, int>> answer;

int getParent(int x) {
	if (parent[x] == x)return x;
	else return getParent(parent[x]);
}
void Union(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a > b)parent[a] = b;
	else parent[b] = a;
}
bool Find(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a != b)return true;
	else return false;
}

int main() {
	cin >> n >> m;
	for (int i = 1; i < n; i++)parent[i] = i;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		//입력받으면서 연결됨을 표시
		if (Find(a, b)) {
			Union(a, b);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int com;
			cin >> com;
			if (i > 0 && j > i)computers.push(make_pair(-com,make_pair(i, j)));
		}
	}

	while (!computers.empty()) {
		int value = -computers.top().first;
		int v1 = computers.top().second.first;
		int v2 = computers.top().second.second;
		computers.pop();
		if (Find(v1, v2)) {
			Union(v1, v2);
			miniMum += value;
			answer.push_back(make_pair(v1, v2));
		}
	}
	cout << miniMum << " " << answer.size() << "\n";
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i].first+1 << " " << answer[i].second+1 << "\n";
	}
}