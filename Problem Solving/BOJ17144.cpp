/*미세먼지 안녕!*/
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int R, C, T;
int totalDust;
int map[51][51];
int afterMap[51][51];
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };
vector<pair<int,int>> cleaner;

void copyMap() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			map[i][j] = afterMap[i][j];
			afterMap[i][j] = 0;
		}
	}
	afterMap[cleaner[0].first][cleaner[0].second] = afterMap[cleaner[1].first][cleaner[1].second] = -1;
}

void diffusion() {
	copyMap();
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] == 0 || map[i][j] == -1)continue;
			int dust = 0;
			for (int d = 0; d < 4; d++) {
				int nr = i + dr[d];
				int nc = j + dc[d];
				if (nr < 0 || nc < 0 || nr >= R || nc >= C || map[nr][nc] == -1)continue;
				afterMap[nr][nc] += map[i][j] / 5;
				dust += map[i][j] / 5;
			}
			afterMap[i][j] += (map[i][j] - dust);
			dust = 0;
		}
	}
}

void operate() {
	diffusion();
	totalDust -= afterMap[cleaner[0].first - 1][0];
	totalDust -= afterMap[cleaner[1].first + 1][0];

	//위에 공기청정기 아래로가는거
	int i = cleaner[0].first - 1;
	while (i > 0) {
		afterMap[i][0] = afterMap[i - 1][0];
		i--;
	}
	i = 0;
	//위에 공기청정기 왼쪽으로 가는거
	while (i < C - 1) {
		afterMap[0][i] = afterMap[0][i + 1];
		i++;
	}
	i = 0;
	//위에 공기청정기 위로 가는거
	while (i < cleaner[0].first) {
		afterMap[i][C - 1] = afterMap[i + 1][C - 1];
		i++;
	}
	i = C-1;
	//위에 공기청정기 오른쪽으로 가는거
	while (i > 1) {
		afterMap[cleaner[0].first][i] = afterMap[cleaner[0].first][i - 1];
		i--;
	}
	afterMap[cleaner[0].first][1] = 0;

	i = cleaner[1].first + 1;
	//아래 공기청정기 위로가는거
	while (i < R - 1) {
		afterMap[i][0] = afterMap[i + 1][0];
		i++;
	}
	i = 0;
	//아래 공기청정기 왼쪽으로 가는거
	while (i < C - 1) {
		afterMap[R - 1][i] = afterMap[R - 1][i + 1];
		i++;
	}
	i = R - 1;
	//아래 공기청정기 아래로가는거
	while (i > cleaner[1].first) {
		afterMap[i][C - 1] = afterMap[i - 1][C - 1];
		i--;
	}
	i = C - 1;
	//아래 공기청정기 오른쪽으로 가는거
	while (i > 1) {
		afterMap[cleaner[1].first][i] = afterMap[cleaner[1].first][i - 1];
		i--;
	}
	afterMap[cleaner[1].first][1] = 0;

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> R >> C >> T;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> afterMap[i][j];
			if (afterMap[i][j] == -1)cleaner.push_back(make_pair(i, j));
			else totalDust += afterMap[i][j];
		}
	}

	for (int t = 0; t < T; t++)operate();
	cout << totalDust << "\n";
}
