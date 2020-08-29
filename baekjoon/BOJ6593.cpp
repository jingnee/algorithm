/*상범 빌딩*/
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int L, R, C;
char building[30][31][31];
int visit[30][30][30];
int start_idx[3], end_idx[3];
int dr[6] = { -1,0,1,0,0,0 };
int dc[6] = { 0,1,0,-1,0,0 };
int dl[6] = { 0,0,0,0,-1,1 };

bool BFS(int l, int r, int c) {
	queue<pair<int, pair<int, int>>> que;
	que.push(make_pair(l, make_pair(r, c)));
	visit[l][r][c] = 0;
	while (!que.empty()) {
		pair<int, pair<int, int>> cur = que.front();
		que.pop();
		if (cur.first == end_idx[0] && cur.second.first == end_idx[1] && cur.second.second == end_idx[2])return true;

		for (int d = 0; d < 6; d++) {
			int nl = cur.first + dl[d];
			int nr = cur.second.first + dr[d];
			int nc = cur.second.second + dc[d];
			if (nl < 0 || nr < 0 || nc < 0 || nl >= L || nr >= R || nc >= C)continue;
			if (visit[nl][nr][nc] != -1 || building[nl][nr][nc] == '#') continue;
			visit[nl][nr][nc] = visit[cur.first][cur.second.first][cur.second.second] + 1;
			que.push(make_pair(nl, make_pair(nr, nc)));
		}
	}
	return false;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (1) {
		cin >> L >> R >> C;
		if (L == 0 && R == 0 && C == 0)break;
		memset(building, 0, sizeof(building));
		memset(visit, -1, sizeof(visit));

		for (int l = 0; l < L; l++) {
			for (int r = 0; r < R; r++) {
				for (int c = 0; c < C; c++) {
					cin >> building[l][r][c];
					if (building[l][r][c] == 'S') {
						start_idx[0] = l;
						start_idx[1] = r;
						start_idx[2] = c;
					}
					if (building[l][r][c] == 'E') {
						end_idx[0] = l;
						end_idx[1] = r;
						end_idx[2] = c;
					}
				}
			}
		}
			
		bool answer = BFS(start_idx[0], start_idx[1], start_idx[2]);
		if (!answer)cout << "Trapped!\n";
		else cout << "Escaped in " << visit[end_idx[0]][end_idx[1]][end_idx[2]] << " minute(s).\n";
	}
	
}
