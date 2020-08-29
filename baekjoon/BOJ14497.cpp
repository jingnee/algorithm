/*주난의 난*/
#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int N, M, answer;
char map[300][300];
bool visit[300][300];
pair<int, int> choco;
pair<int, int>junan;
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };
queue<pair<int, int>> que;

void DFS(int r, int c) {
	for (int d = 0; d < 4; d++) {
		int nr = r + dr[d];
		int nc = c + dc[d];
		if (nr < 0 || nc < 0 || nr >= N || nc >= M) continue;
		if (map[nr][nc] != '0' || visit[nr][nc])continue;
		que.push(make_pair(nr, nc));
		visit[nr][nc] = true;
		DFS(nr, nc);
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	cin >> junan.first >> junan.second >> choco.first >> choco.second;
	junan.first--; junan.second--; choco.first--; choco.second--;

	for (int i = 0; i < N; i++)cin >> map[i];

	visit[junan.first][junan.second] = true;
	
	que.push(make_pair(junan.first,junan.second));

	//DFS(junan.first, junan.second);
	bool flag = false;

	while (!que.empty()) {
		//if (flag)break;
		int size = que.size();
		for (int j = 0; j < size; j++) {
			pair<int, int> qq = que.front();
			que.pop();
			DFS(qq.first, qq.second);
			que.push(qq);
		}
		size = que.size();

		for (int i = 0; i < size; i++) {
			pair<int, int>temp = que.front();
			if (temp.first == choco.first && temp.second == choco.second) {
				cout << answer << "\n";
				return 0;
			}
			que.pop();

			for (int d = 0; d < 4; d++) {
				int nr = temp.first + dr[d];
				int nc = temp.second + dc[d];
				if (nr < 0 || nc < 0 || nr >= N || nc >= M)continue;
				if (visit[nr][nc])continue;
				visit[nr][nc] = true;
				que.push(make_pair(nr, nc));
				map[nr][nc] = '0';
			}
		}
		answer++;
	}

	//cout << answer-- << "\n";
}
