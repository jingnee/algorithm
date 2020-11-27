//인내의 도미노 장인 호석
#include <iostream>
using namespace std;

int N, M, R, answer;
int map[110][110];
bool isFall[110][110];
int dr[4] = { 0,0,1,-1 };
int dc[4] = { 1,-1,0,0 };

void fall(int r, int c, char dir) {
	int d = -1;
	if (dir == 'E')d = 0;
	else if (dir == 'W')d = 1;
	else if (dir == 'S')d = 2;
	else d = 3;

	if (isFall[r][c])return;

	int cnt = map[r][c];
	while (r >= 0 && c >= 0 && r < N && c < M && cnt >= 1) {
		if (!isFall[r][c]) {
			answer++;
			cnt = (cnt < map[r][c]) ? map[r][c] : cnt;
		}
		cnt--;
		isFall[r][c] = true;
		r += dr[d];
		c += dc[d];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> R;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < R; i++) {
		int r, c;
		char dir;
		cin >> r >> c >> dir;
		r--, c--;
		fall(r, c, dir);
		cin >> r >> c;
		isFall[r - 1][c - 1] = false;
	}

	cout << answer << "\n";
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (isFall[i][j])cout << "F ";
			else cout << "S ";
		}cout << "\n";
	}
	return 0;
}
