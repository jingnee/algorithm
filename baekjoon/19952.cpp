//인성 문제 있어??
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int T;
int H, W, O, F;
int start[2];
int goal[2];
int map[101][101];
int rest[101][101];
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;
	while (T--) {
		cin >> H >> W >> O >> F >> start[0] >> start[1] >> goal[0] >> goal[1];
		memset(map, 0, sizeof(map));
		for (int i = 0; i < O; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			map[a][b] = c;
		}
		memset(rest, 0, sizeof(rest));
		rest[start[0]][start[1]] = F;
		rest[goal[0]][goal[1]] = -1;
		queue<pair<int, int>> que;
		que.push(make_pair(start[0], start[1]));

		while (!que.empty()) {
			pair<int, int>temp = que.front();
			que.pop();
			if (temp.first == goal[0] && temp.second == goal[1]) {
				cout << "잘했어!!\n";
				break;
			}

			for (int d = 0; d < 4; d++) {
				int nr = temp.first + dr[d];
				int nc = temp.second + dc[d];
				if (nr <= 0 || nc <= 0 || nr > H || nc > W)continue;
				int power = map[nr][nc] - map[temp.first][temp.second];

				if (power <= rest[temp.first][temp.second] && rest[nr][nc] < rest[temp.first][temp.second]-1) {
					rest[nr][nc] = rest[temp.first][temp.second] - 1;
					que.push(make_pair(nr, nc));
				}
			}
		}

		if (rest[goal[0]][goal[1]] < 0)cout << "인성 문제있어??\n";
	}
}
