/*로봇 청소기
벽과 청소한부분 구분해야함*/
#include <iostream>
using namespace std;

int N, M;
bool flag = true;
int map[51][51];
int curR, curC, curDir, ans;
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };

void clear(int r, int c, int dir) {
	if (!flag)return;

	if (!map[r][c]) {
		ans++;
		map[r][c] = 2;
		//cout << "[" << r << "][" << c << "], 방향: " << dir << "\n";
	}

	//4방향 청소
	for (int nd = (dir+3)%4, i = 0; i < 4; nd = (nd + 3) % 4, i++) {
		int nr = r + dr[nd];
		int nc = c + dc[nd];
		if (nr < 0 || nc < 0 || nr >= N || nc >= M)continue;
		if (map[nr][nc]!=0)continue;
		clear(nr, nc, nd);
	}
	//4방향 모두 막혀있을때 뒤로 한칸
	int nd = (dir + 2) % 4;
	int nr = r + dr[nd];
	int nc = c + dc[nd];
	if (nr < 0 || nc < 0 || nr >= N || nc >= M || map[nr][nc]==1) {
		flag = false;
		return;
	}
	clear(nr, nc, dir);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	cin >> curR >> curC >> curDir;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	clear(curR, curC, curDir);
	//for (int i = 0; i < N; i++) {
	//	for (int j = 0; j < M; j++) {
	//		//cout << map[i][j] << " ";
	//		printf("%2d ", map[i][j]);
	//	}cout << endl;
	//}
	cout << ans << "\n";
}
