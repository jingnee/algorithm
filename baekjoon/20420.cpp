//화살표 미로(Normal)
#include <iostream>
#include <cstring>
#include <queue>
#include <string>
#include <map>
using namespace std;

struct paper {
	int r, c, l_cnt, r_cnt;
};
//왼쪽 회전 갯수로 정렬
bool operator < (paper p1, paper p2) {
	return p1.l_cnt > p2.l_cnt;
}

int R, C, K;
char maze[51][51];
int usedR[51][51];  //오른쪽 회전 갯수를 넣어 놓는 곳
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };
priority_queue<paper> que;    //사용한 주문서 갯수,r,c좌표
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

	memset(usedR, 0x7f, sizeof(usedR));
	que.push({ 0,0,0,0 });

	while (!que.empty()) {
		int r = que.top().r;
		int c = que.top().c;
		int l_cnt = que.top().l_cnt;
		int r_cnt = que.top().r_cnt;
		que.pop();
		if (l_cnt > K || r_cnt > K)continue;
		if (usedR[r][c] <= r_cnt)continue;
		usedR[r][c] = r_cnt;
		if (r == R - 1 && c == C - 1) {
			cout << "Yes";
			return 0;
		}

		int dir = m[maze[r][c]];
		int nr = r + dr[dir];
		int nc = c + dc[dir];
		//방향 바꾸지 않고
		if (nr >= 0 && nc >= 0 && nr<R && nc<C && usedR[nr][nc] > r_cnt) {
			que.push({ nr,nc,l_cnt,r_cnt });
		}
		//오른쪽으로 방향 바꿈
		for (int i = 1; i <= 3; i++) {
			int nd = (dir + i) % 4;
			nr = r + dr[nd];
			nc = c + dc[nd];
			if (nr >= 0 && nc >= 0 && nr<R && nc<C && usedR[nr][nc] > r_cnt + i) {
				que.push({ nr,nc,l_cnt,r_cnt + i });
			}
		}
		//왼쪽으로 방향 바꿈
		for (int d = 3, i = 1; d >= 1; d--, i++) {
			int nd = (dir + d) % 4;
			nr = r + dr[nd];
			nc = c + dc[nd];
			if (nr >= 0 && nc >= 0 && nr<R && nc<C && usedR[nr][nc] > r_cnt) {
				que.push({ nr,nc,l_cnt + i,r_cnt });
			}
		}
	}

	cout << "No";

}