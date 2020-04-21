/*문자판*/
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

char map[101][101];
int DP[100][100][80];
string words;
int N, M, K, answer;
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };


int DFS(int index, int r, int c) {
	if (index >= words.length())return 1;
	if (DP[r][c][index] != -1)return DP[r][c][index];
	DP[r][c][index] = 0;

	for (int d = 0; d < 4; d++) {
		for (int k = 1; k <= K; k++) {
			int nr = r + dr[d] * k;
			int nc = c + dc[d] * k;
			if (nr < 0 || nc < 0 || nr >= N || nc >= M)continue;
			if (map[nr][nc] == words[index]) 
				DP[r][c][index] += DFS(index + 1, nr, nc);	
		}
	}
	return DP[r][c][index];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K;
	for (int i = 0; i < N; i++)
		cin >> map[i];
	cin >> words;

	memset(DP, -1, sizeof(DP));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == words[0]) {
				answer += DFS(1, i, j);
			}
		}
	}
	cout << answer << "\n";
}
