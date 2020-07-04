/*윌리암슨수액빨이딱따구리가 정보섬에 올라온 이유*/
#include <iostream>
#include <queue>
using namespace std;

int n, m;
char map[3005][3005];
int dr[4] = { -1,1,0,0 };
int dc[4] = { 0,0,-1,1 };
bool visit[3005][3005];
queue<pair<pair<int, int>,int>> que;

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> map[i];

	bool flag = false;
	for (int i = 0; i < n; i++) {
		if (flag)break;
		for (int j = 0; j < m; j++) {
			if (map[i][j] == '2') {
				que.push(make_pair(make_pair(i, j), 0));
				visit[i][j] = true;
				map[i][j] = '0';
				flag = true;
				break;
			}
		}
	}

	while (!que.empty()) {
		pair<pair<int, int>, int> temp;
		temp = que.front();
		que.pop();
		int r = temp.first.first;
		int c = temp.first.second;
		int cnt = temp.second;
		if (map[r][c] != '0') {
			cout << "TAK\n";
			cout << cnt << "\n";
			return 0;
		}

		for (int d = 0; d < 4; d++) {
			int nr = r + dr[d];
			int nc = c + dc[d];
			if (nr < 0 || nc < 0 || nr >= n || nc >= m || visit[nr][nc])continue;
			if (map[nr][nc] == '1')continue;
			visit[nr][nc] = true;
			que.push(make_pair(make_pair(nr, nc), cnt + 1));
		}
	}
	cout << "NIE\n";
	return 0;
}
