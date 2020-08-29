/*무기 공학*/
#include <iostream>
using namespace std;

int N, M, answer;
int map[5][5];
int visit[5][5];
int dr[4][2] = { { 0,1 },{ -1,0 },{ -1,0 },{ 0,1 } };
int dc[4][2] = { { -1,0 },{ 0,-1 },{ 0,1 },{ 1,0 } };

bool range(int r, int c, int nr1, int nc1, int nr2, int nc2) {
	if (nr1 < 0 || nc1 < 0 || nr2 < 0 || nc2 < 0 || nr1 >= N || nc1 >= M || nr2 >= N || nc2 >= M) return false;
	else {
		if (visit[r][c] != 1 && visit[nr1][nc1] != 1 && visit[nr2][nc2] != 1) return true;
		else return false;
	}
}

void DFS(int r, int c, int sum) {
	if (c == M) {
		r++;
		c = 0;
	}
	if (r == N) {
		answer = (answer < sum) ? sum : answer;
		return;
	}

	for (int d = 0; d < 4; d++) {
		int nr1 = r + dr[d][0];
		int nc1 = c + dc[d][0];
		int nr2 = r + dr[d][1];
		int nc2 = c + dc[d][1];
		//경계안에 있고, 방문하지 않았는지 체크
		if (range(r, c, nr1, nc1, nr2, nc2)) {
			visit[r][c] = 1;
			visit[nr1][nc1] = 1;
			visit[nr2][nc2] = 1;
			int value = map[r][c] * 2 + map[nr1][nc1] + map[nr2][nc2];
			DFS(r, c + 1, sum + value);
			visit[r][c] = 0;
			visit[nr1][nc1] = 0;
			visit[nr2][nc2] = 0;
		}
	}
		//방문하지 않는 경우
		DFS(r, c + 1, sum);
		

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)cin >> map[i][j];
	}
	if (N < 2 && M < 2) {
		cout << "0\n";
		return 0;
	}
	DFS(0, 0, 0);
	cout << answer << "\n";
}