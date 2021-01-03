//화살표 미로(easy)
#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <map>
using namespace std;

struct paper {
	int r;
	int c;
	int l_cnt;
	int r_cnt;
};
int R, C, K;
char maze[51][51];
int pcount[51][51][151][151];
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };
queue<paper> que;    //사용한 주문서 갯수,r,c좌표
map<char, int> m;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> R >> C >> K;
	for (int i = 0; i<R; i++)cin >> maze[i];

	m['U'] = 0;
	m['R'] = 1;
	m['D'] = 2;
	m['L'] = 3;

	que.push({ 0,0,0,0 });
	pcount[0][0][0][0] = true;

	while (!que.empty()) {
		int r = que.front().r;
		int c = que.front().c;
		int l_cnt = que.front().l_cnt;
		int r_cnt = que.front().r_cnt;
		que.pop();
		if (r == R - 1 && c == C - 1 && max(l_cnt, r_cnt) <= K) {
			cout << "Yes";
			return 0;
		}

		int dir = m[maze[r][c]];
		int nr = r + dr[dir];
		int nc = c + dc[dir];
		//방향 바꾸지 않고
		if (nr >= 0 && nc >= 0 && nr<R && nc<C && !pcount[nr][nc][l_cnt][r_cnt]) {
			pcount[nr][nc][l_cnt][r_cnt] = true;
			que.push({ nr,nc,l_cnt,r_cnt });
		}
		//오른쪽으로 방향 바꿈
		for (int d = 1; d <= 3; d++) {
			if (r_cnt + d > K)break;
			int nd = (dir + d) % 4;
			nr = r + dr[nd];
			nc = c + dc[nd];
			if (nr >= 0 && nc >= 0 && nr<R && nc<C && !pcount[nr][nc][l_cnt][r_cnt + d]) {
				pcount[nr][nc][l_cnt][r_cnt + d] = true;
				que.push({ nr,nc,l_cnt,r_cnt + d });
			}
		}
		//왼쪽으로 방향 바꿈
		for (int d = 3, i = 1; d >= 1; d--, i++) {
			if (l_cnt + i > K)break;
			int nd = (dir + d) % 4;
			nr = r + dr[nd];
			nc = c + dc[nd];
			if (nr >= 0 && nc >= 0 && nr<R && nc<C && !pcount[nr][nc][l_cnt + i][r_cnt]) {
				pcount[nr][nc][l_cnt + i][r_cnt] = true;
				que.push({ nr,nc,l_cnt + i,r_cnt });
			}
		}
	}

	cout << "No";
}