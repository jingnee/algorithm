/*Two Dots*/
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int N, M;
bool ans = false;
char map[51][51];
int visit[51][51];
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };
queue<pair<int, int>> que;

void DFS(int sr, int sc, int r, int c, char ch, bool flag) {
	if (flag)return;

	for (int d = 0; d < 4; d++) {
		int nr = r + dr[d];
		int nc = c + dc[d];
		if (nr < 0 || nc < 0 || nr >= N || nc >= M)continue;
		if ((nr == sr && nc == sc) && visit[r][c]!=2) {
			flag = true;
			ans = true;
			return;
		}
		if (visit[nr][nc]!=0 || map[nr][nc] != ch)continue;

		visit[nr][nc] = visit[r][c]+1;
		DFS(sr, sc, nr, nc, ch,flag);
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++)cin >> map[i];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			memset(visit, 0, sizeof(visit));
			visit[i][j] = 1;
			DFS(i, j, i, j, map[i][j], false);
			if(ans){
				cout << "Yes\n";
				return 0;
			}
		}
	}
	cout << "No\n";
	return 0;
}
