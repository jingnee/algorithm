/*불 켜기*/
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int N, M, ans;
queue<pair<int,int>> map[101][101];
queue<pair<int, int>> que;
bool light[101][101];
bool check[101][101];
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	int x, y, a, b;
	for (int i = 0; i < M; i++) {
		cin >> x >> y >> a >> b;
		map[x][y].push(make_pair(a, b));
	}

	while (1) {
		bool flag = false;
		memset(check, false, sizeof(check));
		que.push(make_pair(1, 1));
		light[1][1] = true;
		check[1][1] = true;

		while (!que.empty()) {
			int r = que.front().first;
			int c = que.front().second;
			que.pop();

			while (!map[r][c].empty()) {
				pair<int, int> temp = map[r][c].front();
				map[r][c].pop();
				light[temp.first][temp.second] = true;
				flag = true;
			}
			for (int d = 0; d < 4; d++) {
				int nr = r + dr[d];
				int nc = c + dc[d];
				if (nr<1 || nc<1 || nr>N || nc>N)continue;
				if (light[nr][nc] && !check[nr][nc]) {
					que.push(make_pair(nr, nc));
					check[nr][nc] = true;
				}
			}
		}
		
			if (!flag)break;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (light[i][j])ans++;
		}
	}

	cout << ans << "\n";
}
