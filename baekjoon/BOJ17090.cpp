/*미로 탈출하기*/
#include <iostream>
using namespace std;

char map[501][501];
int DP[501][501];
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };
int N, M, ans;

int dir(char d) {
	if (d == 'U')return 0;
	else if (d == 'R')return 1;
	else if (d == 'D')return 2;
	else return 3;
}
int DFS(int r, int c) {
	if (r < 0 || c < 0 || r >= N || c >= M)return 1;
	if (DP[r][c] != 0)return DP[r][c];
	
	DP[r][c] = -1;

	int d = dir(map[r][c]);

	DP[r][c] = DFS(r + dr[d], c + dc[d]);
	return DP[r][c];	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) 
		cin >> map[i];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (DFS(i, j) == 1)ans++;
		}
	}

	cout << ans << "\n";
}
