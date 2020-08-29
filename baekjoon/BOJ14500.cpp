//테트로미노
//DFS만으로는 ㅗ,ㅜ,ㅓ,ㅏ를 찾을 수 없으므로 따로 탐색해주어야함

#include<iostream>
using namespace std;

int N, M;
int map[500][500];
bool visit[500][500];
int maximum;
int dr[4] = { 0,1,0,-1 };
int dc[4] = { 1,0,-1,0 };
void DFS(int r, int c, int cnt, int sum) {
	if (cnt == 4) {
		maximum = (maximum < sum) ? sum : maximum;
		return;
	}
	for (int dir = 0; dir < 4; dir++) {
		int nr = r + dr[dir];
		int nc = c + dc[dir];
		if (visit[nr][nc] == true)continue;
		if (nr >= 0 && nc >= 0 && nr < N && nc < M) {
			visit[nr][nc] = true;
			DFS(nr, nc, cnt + 1, sum + map[nr][nc]);
			visit[nr][nc] = false;
		}
	}
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visit[i][j] = true;
			DFS(i, j, 1, map[i][j]);
			visit[i][j] = false;
			int temp = 0;
			if (j + 2 < M) {
				temp = map[i][j] + map[i][j + 1] + map[i][j + 2];
				if (i - 1 >= 0)			//ㅗ
					maximum = (maximum < temp + map[i - 1][j + 1]) ? temp + map[i - 1][j + 1] : maximum;
				if (i + 1 < N)			//ㅜ
					maximum = (maximum < temp + map[i + 1][j + 1]) ? temp + map[i + 1][j + 1] : maximum;
			}
			if (i + 2 < N) {
				temp = map[i][j] + map[i+1][j] + map[i+2][j];
				if (j - 1 >= 0)			//ㅓ
					maximum = (maximum < temp + map[i + 1][j - 1]) ? temp + map[i + 1][j - 1] : maximum;
				if (j + 1 < M)			//ㅜ
					maximum = (maximum < temp + map[i + 1][j + 1]) ? temp + map[i + 1][j + 1] : maximum;
			}
		}
	}

	cout << maximum << endl;

}