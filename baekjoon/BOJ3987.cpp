/*보이저 1호*/
#include <iostream>
#include <cstring>
using namespace std;

char map[501][501];
int visit[501][501];
int N, M, PR, PC;
int max_num;
char max_dir;
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };
char dir[4] = { 'U','R','D','L' };

int simulation(int r, int c, int d) {
	int cnt = 1;
	visit[r][c] = d;
	while (1) {
		r += dr[d];
		c += dc[d];
		if (r < 0 || r >= N || c < 0 || c >= M || map[r][c] == 'C')return cnt;
		if (d == visit[r][c])return 0;
		
		if (map[r][c] == '/') {
			if (d == 0)d = 1;
			else if (d == 1)d = 0;
			else if (d == 2)d = 3;
			else d = 2;
		}

		else if (map[r][c] == '\\') {
			if (d == 0)d = 3;
			else if (d == 1)d = 2;
			else if (d == 2)d = 1;
			else d = 0;
		}
		cnt++;
		visit[r][c] = d;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	cin >> PR >> PC;
	PR--, PC--;
	for (int d = 0; d < 4; d++) {
		memset(visit, -1, sizeof(visit));
		int ans = simulation(PR, PC, d);
		if (ans == 0) {
			cout << dir[d] << "\nVoyager\n";
			return 0;
		}
		if (ans > max_num) {
			max_num = ans;
			max_dir = dir[d];
		}
		
	}
	cout << max_dir << "\n";
	cout << max_num << "\n";

}
