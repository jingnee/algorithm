/*파이프 옮기기1*/
#include <iostream>
using namespace std;

int N, answer;
int dr[3] = { 0,1,1 };
int dc[3] = { 1,1,0 };
int map[16][16];
void DFS(int r, int c, int dir) {
	if (r == N - 1 && c == N - 1) {
		answer++;
		return;
	}
	//visit[r][c] = true;
	for (int d = 0; d < 3; d++) {
		//가로일때 세로방향 못가
		if (dir == 0 && d == 2)continue;
		//세로일때 가로방향 못가
		if (dir == 2 && d == 0)continue;
		int nr = r + dr[d];
		int nc = c + dc[d];
		//범위 벗어나거나 벽만나면 안돼
		if (nr >= N || nc >= N || map[nr][nc] == 1)continue;
		//대각선일때 범위체크
		if (d == 1) 
			if (map[r + dr[0]][c + dc[0]] == 1 || map[r + dr[2]][c + dc[2]] == 1)continue;
		
		DFS(nr, nc, d);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	//dir이 0이면 가로, 2이면 세로
	DFS(0, 1, 0);
	cout << answer << "\n";
}
