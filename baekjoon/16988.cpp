/*Baaaaaaaaaduk2 (Easy)*/
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int N, M, answer;
int map[21][21], visit[21][21];
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };

int BFS() {
	int ans = 0;
	queue<pair<int, int>> que;
	memset(visit, false, sizeof(visit));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 2 && !visit[i][j]) {
				visit[i][j] = true;
				que.push(make_pair(i, j));
				int cnt = 0;
				bool flag = true;

				while (!que.empty()) {
					pair<int, int> temp = que.front();
					que.pop();
					cnt++;

					for (int d = 0; d < 4; d++) {
						int nr = temp.first + dr[d];
						int nc = temp.second + dc[d];
						if (nr < 0 || nc < 0 || nr >= N || nc >= M || map[nr][nc]==1 || visit[nr][nc])continue;
						if (map[nr][nc] == 0) {
							flag = false;				//주변에 빈칸이 있으면 안됨
						}	
						visit[nr][nc] = true;
						que.push(make_pair(nr, nc));
					}
				}
				if (flag)ans += cnt;
			}
		}
	}

	return ans;
}

void DFS(int r, int idx) {
	if (idx == 2) {
		int ans = BFS();
		answer = (answer < ans) ? ans : answer;
		return;
	}

	for (int i = r; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0) {
				map[i][j] = 1;
				DFS(i, idx + 1);
				map[i][j] = 0;
			}
		}
	}

	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	DFS(0, 0);
	cout << answer;
}
