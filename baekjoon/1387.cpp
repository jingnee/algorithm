//양치기 꿍
#include <iostream>
#include <queue>
using namespace std;

char map[260][260];
bool visit[260][260];
int R, C, wolf, sheep;
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };

//[r][c]위치에서 양과 늑대 수 세는 함수
void countWS(int r, int c) {
	queue<pair<int, int>> que;
	int sheepNum = 0; int WolfNum = 0;
	que.push(make_pair(r, c));
	if (map[r][c] == 'v')WolfNum++;
	else if (map[r][c] == 'k')sheepNum++;
	visit[r][c] = true;

	while (!que.empty()) {
		int curR = que.front().first;
		int curC = que.front().second;
		que.pop();

		for (int d = 0; d < 4; d++) {
			int nr = curR + dr[d];
			int nc = curC + dc[d];
			if (nr < 0 || nc < 0 || nr >= R || nc >= C || visit[nr][nc] || map[nr][nc]=='#')continue;
			visit[nr][nc]++;
			if (map[nr][nc] == 'v')WolfNum++;
			else if (map[nr][nc] == 'k')sheepNum++;
			que.push(make_pair(nr, nc));
		}
	}
	if (sheepNum > WolfNum)sheep += sheepNum;
	else wolf += WolfNum;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> R >> C;
	for (int i = 0; i < R; i++)cin >> map[i];
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (!visit[i][j] && map[i][j] != '#') {
				countWS(i, j);
			}
		}
	}
	cout << sheep << " " << wolf;
}