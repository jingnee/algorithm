//벽 부수고 이동하기 2
#include <iostream>
#include <queue>
using namespace std;

struct pos {
	int r, c, k_use, cnt;
};
bool operator<(pos p1, pos p2) {
	if (p1.cnt != p2.cnt)return p1.cnt > p2.cnt;
	else return p1.k_use > p2.k_use;
}
int N, M, K;
char map[1005][1005];
bool check[1005][1005][11];
priority_queue<pos>que;
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> K;
	for (int i = 0; i < N; i++)cin >> map[i];
	que.push({ 0,0,0,1 });
	check[0][0][0] = true;

	while (!que.empty()) {
		int r = que.top().r;
		int c = que.top().c;
		int used = que.top().k_use;
		int cnt = que.top().cnt;
		que.pop();

		if (r == N - 1 && c == M - 1) {
			cout << cnt;
			return 0;
		}

		for (int d = 0; d < 4; d++) {
			int nr = r + dr[d];
			int nc = c + dc[d];
			if (nr < 0 || nc < 0 || nr >= N || nc >= M || (map[nr][nc] == '1'&& used == K))continue;
			if (!check[nr][nc][used] && map[nr][nc]=='0') {
				que.push({ nr,nc,used,cnt + 1 });
				check[nr][nc][used] = true;
			}
			else if(!check[nr][nc][used+1] && map[nr][nc]=='1') {
				que.push({ nr,nc,used + 1,cnt + 1 });
				check[nr][nc][used + 1] = true;
			}
		}
	}
	cout << "-1";
}
