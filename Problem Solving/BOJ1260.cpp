#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

int N, M;			//N:정점의 갯수, M:간선의 갯수
int V;				//시작번호
vector<int> map[1001];
bool visit[1001];
queue<int> que;

void DFS(int x) {
	visit[x] = true;
	cout << x << " ";
	for (int i = 0; i < map[x].size(); i++) {			//sizeof(map[x])는 런타임에러.. 왜?
		int nx = map[x][i];
		if (!visit[nx])DFS(nx);
	}
}

void BFS(int x) {
	que.push(x);
	visit[x] = true;
	while (!que.empty()) {
		int nx = que.front();
		que.pop();
		cout << nx << " ";
		for (int i = 0; i < map[nx].size(); i++) {
			int n = map[nx][i];
			if (!visit[n]) {
				que.push(n);
				visit[n] = true;
			}
		}
	}
}

int main() {
	cin >> N >> M >> V;
	for (int i = 0; i < M; i++) {
		int s, e;
		cin >> s >> e;
		map[s].push_back(e);				//인접 리스트형태로 입력받음
		map[e].push_back(s);
	}

	for (int i = 0; i < N; i++)				//작은수부터 탐색하기위한 정렬
	sort(map[i].begin(), map[i].end());
	DFS(V);
	cout << endl;
	for (int i = 1; i <= N; i++)visit[i] = false;
	BFS(V);
}