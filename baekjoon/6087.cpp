//레이저 통신
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

priority_queue < pair<pair<int,int>, pair<int, int>>> que;
int W, H;
char map[105][105];
int mirrors[105][105];
int s_r, s_c;
int e_r, e_c;
int dr[4] = {0,-1,0,1};		//[1]← [2]↑ [3]→ [4]↓
int dc[4] = {-1,0,1,0};	//[1]← [2]↑ [3]→ [4]↓

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> H >> W;
	int cnt = 0;
	for (int i = 0; i < W; i++) {
		for (int j = 0; j < H; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'C') {
				if (cnt == 0) {
					cnt++;
					s_r = i;
					s_c = j;
				}
				else {
					e_r = i;
					e_c = j;
				}
			}
			mirrors[i][j] = 20000;
		}
	}

	mirrors[s_r][s_c] = 0;
	que.push(make_pair(make_pair(0, 0), make_pair(s_r, s_c)));
	que.push(make_pair(make_pair(0, 1), make_pair(s_r, s_c)));
	que.push(make_pair(make_pair(0, 2), make_pair(s_r, s_c)));
	que.push(make_pair(make_pair(0, 3), make_pair(s_r, s_c)));

	while (!que.empty()) {
		int mirror_num = -que.top().first.first;
		int dir = que.top().first.second;
		int r = que.top().second.first;
		int c = que.top().second.second;
		que.pop();

		if (r == e_r && c == e_c) {
			cout << mirror_num;
			return 0;
		}

		//그대로 진행, 거울설치해서 방향의 시계 반대방향과 시계방향 이렇게 세방향을 보면 됨
		//안되는 이유 : dir가 0이나 3일때 시작값이 끝값보다 커서 아예 포문 안돎
		//네군데 봐도 되는 건 어차피 이미 지나온곳이 거울수가 더 적을테니까 한번더 본다고 값이 변하지 않는다.
//		for (int d = ((dir - 1) < 0 ? 3 : dir - 1); d <= ((dir + 1) > 3 ? 0 : dir + 1); d++) {
		for (int d = 0; d < 4; d++){
			int nr = r + dr[d];
			int nc = c + dc[d];
			int nm = mirror_num;
			if (nr < 0 || nc < 0 || nr >= W || nc >= H || map[nr][nc] == '*')continue;
			if (dir != d)nm++;
			if (mirrors[nr][nc] >= nm) {
				mirrors[nr][nc] = nm;
				que.push(make_pair(make_pair(-nm, d), make_pair(nr, nc)));
			}
		}
	}
}