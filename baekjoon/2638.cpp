//치즈
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, time;
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };
int map[100][100];
bool visit[100][100];
vector<pair<int, int>>cheeses;
queue<pair<int, int>>que;

void outside() {
	while (!que.empty()) {
		int r = que.front().first;
		int c = que.front().second;
		que.pop();

		for (int d = 0; d < 4; d++) {
			int nr = r + dr[d];
			int nc = c + dc[d];
			if (nr >= 0 && nc >= 0 && nr < N && nc < M && !visit[nr][nc] && map[nr][nc] != 1) {
				map[nr][nc] = -1;
				visit[nr][nc] = true;
				que.push(make_pair(nr, nc));
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1)cheeses.push_back(make_pair(i, j));
		}
	}
	if (cheeses.size() == 0)cout << "0";
	else {
		map[0][0] = -1;
		que.push(make_pair(0, 0));
		outside();
		while (cheeses.size() > 0) {
			vector<pair<int, int>> removable;
			vector<pair<int, int>>temp;
			for (auto cheese : cheeses) {
				int r = cheese.first;
				int c = cheese.second;
				int cnt = 0;
				if (map[r - 1][c] == -1)cnt++;
				if (map[r][c - 1] == -1)cnt++;
				if (map[r + 1][c] == -1)cnt++;
				if (map[r][c + 1] == -1)cnt++;

				if (cnt >= 2) {
					removable.push_back(make_pair(r, c));
				}
				else {
					temp.push_back(make_pair(r, c));
				}
			}
			cheeses.erase(cheeses.begin(), cheeses.end());
			cheeses = temp;
			for (auto r : removable) {
				map[r.first][r.second] = -1;
				que.push(make_pair(r.first, r.second));
			}
			outside();
			time++;
		}
		cout << time;
	}
}
