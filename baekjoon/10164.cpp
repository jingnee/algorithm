//격자상의 경로
#include <iostream>
using namespace std;

int N, M, num, answer;
int grid[16][16];

int main() {
	cin >> N >> M >> num;
	int r, c;
	if (num != 0) {
		r = (num - 1) / M;
		c = (num - 1) % M;
	}
	else {
		r = N - 1;
		c = M - 1;
	}

	grid[0][0] = 1;

	for (int i = 0; i <= r; i++) {
		for (int j = 0; j <= c; j++) {
			if (i == 0 || j == 0)grid[i][j] = 1;
			else 
				grid[i][j] = grid[i - 1][j] + grid[i][j - 1];
		}
	}
	answer = grid[r][c];
	for (int i = r; i < N; i++) {
		for (int j = c; j < M; j++) {
			if (i == r || j == c)grid[i][j] = 1;
			else grid[i][j] = grid[i - 1][j] + grid[i][j - 1];
		}
	}
	answer *= grid[N - 1][M - 1];

	cout << answer;
}