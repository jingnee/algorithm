//욕심쟁이 판다
#include <iostream>
#include <algorithm>
using namespace std;

int DP[500][500];
int map[500][500];
int N, answer;
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };

int DFS(int r, int c) {
	if (DP[r][c] != 0)return DP[r][c];
	DP[r][c] = 1;

	for (int d = 0; d < 4; d++) {
		int nr = r + dr[d];
		int nc = c + dc[d];
		if (nr < 0 || nc < 0 || nr >= N || nc >= N)continue;
		else if (map[nr][nc] > map[r][c]) {
			DP[r][c] = max(DP[r][c], DFS(nr, nc) + 1);
		}
	}
	return DP[r][c];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)cin >> map[i][j];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			answer = max(answer, DFS(i, j));
		}
	}
	cout << answer;
}
