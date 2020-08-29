/*수지의 수지 맞는 여행*/
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int map[20][20];
bool visit[26];
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };
int T, R, C, answer;

void DFS(int r, int c, int cnt) {

	for (int d = 0; d < 4; d++) {
		int nr = r + dr[d];
		int nc = c + dc[d];
		if (nr < 0 || nc < 0 || nr >= R || nc >= C)continue;
		if (!visit[map[nr][nc]]) {
			visit[map[nr][nc]] = true;
			DFS(nr, nc, cnt + 1);
			visit[map[nr][nc]] = false;
		}
	}
	answer = (answer < cnt) ? cnt : answer;
}

int main() {
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		cin >> R >> C;
		//char -> int로
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				char ch;
				cin >> ch;
				map[i][j] = ch - 'A';
			}
		}
		answer = 0;
		memset(visit, false, sizeof(visit));
		visit[map[0][0]] = true;
		DFS(0,0,1);

		cout << "#" << test_case << " " << answer << "\n";
	}
}