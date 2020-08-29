#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

int N, M;			//N:������ ����, M:������ ����
int V;				//���۹�ȣ
vector<int> map[1001];
bool visit[1001];
queue<int> que;

void DFS(int x) {
	visit[x] = true;
	cout << x << " ";
	for (int i = 0; i < map[x].size(); i++) {			//sizeof(map[x])�� ��Ÿ�ӿ���.. ��?
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
		map[s].push_back(e);				//���� ����Ʈ���·� �Է¹���
		map[e].push_back(s);
	}

	for (int i = 0; i < N; i++)				//���������� Ž���ϱ����� ����
	sort(map[i].begin(), map[i].end());
	DFS(V);
	cout << endl;
	for (int i = 1; i <= N; i++)visit[i] = false;
	BFS(V);
}