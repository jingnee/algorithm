/*구간 합 구하기 5*/
#include<iostream>
using namespace std;

int N, M;
int map[1024][1024];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = N - 2; i >= 0; i--) {
		map[N - 1][i] += map[N - 1][i + 1];
		map[i][N - 1] += map[i + 1][N - 1];
	}
	for (int i = N - 2; i >= 0; i--) {
		for (int j = N - 2; j >= 0; j--) {
			map[i][j] = map[i][j] + map[i][j + 1] + map[i + 1][j] - map[i + 1][j + 1];
		}
	}

	for (int i = 0; i < M; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		x1--, y1--, x2--, y2--;
		int ans = map[x1][y1];
		int d = 0;
		if (x2 < N - 1) {
			ans -= map[x2 + 1][y1];
			d++;
		}
		if (y2 < N - 1) {
			ans -= map[x1][y2 + 1];
			d++;
		}
		if (d == 2)ans += map[x2 + 1][y2 + 1];
		cout << ans << "\n";
	}
}
