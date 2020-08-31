/*십자가 2개 놓기*/
#include <iostream>
#include <algorithm>
using namespace std;

int N, M, ans;
char map[15][15];

bool putCross(int r, int c, int len) {
	for (int i = c - len; i <= c + len; i++)if (map[r][i] == '.')return false;
	for (int i = r - len; i <= r + len; i++)if (map[i][c] == '.')return false;
	return true;
}

void cross(int r, int c, int len, char ch) {
	for (int i = c - len; i <= c + len; i++)if (map[r][i] = ch);
	for (int i = r - len; i <= r + len; i++)if (map[i][c] = ch);
}

void DFS(int len, int cnt, int tot) {
	if (cnt == 2) {
		ans = (ans < tot) ? tot : ans;
		return;
	}

	for (; len >= 0; len--) {
		for (int r = len; r < N - len; r++) {
			for (int c = len; c < M - len; c++) {
				if (putCross(r, c, len)) {
					cross(r, c, len, '.');
					DFS(len, cnt + 1, tot * ((len * 4) + 1));
					cross(r, c, len, '#');
				}
			}
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
	int maxL = min(N, M);
	maxL /= 2;			//최대 길이가 될 수 있는 십자가
	DFS(maxL, 0, 1);
	cout << ans;	
}