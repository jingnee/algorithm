//음식물 피하기
#include<iostream>
#include <queue>
using namespace std;

int map[100][100];
int N, M, K, answer;
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K;
	for (int i = 0; i < K; i++) {
		int a, b;
		cin >> a >> b;
		map[a - 1][b - 1] = -1;
	}
	int number = 1;
	queue<pair<int, int>> que;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int temp_ans = 0;
			if (map[i][j] == -1) {
				map[i][j] = number;
				temp_ans++;
				que.push(make_pair(i, j));

				while (!que.empty()) {
					int r = que.front().first;
					int c = que.front().second;
					que.pop();

					for (int d = 0; d < 4; d++) {
						int nr = r + dr[d];
						int nc = c + dc[d];
						if (nr < 0 || nc < 0 || nr >= N || nc >= M || map[nr][nc] != -1)continue;
						que.push(make_pair(nr, nc));
						temp_ans++;
						map[nr][nc] = number;
					}
				}
				answer = (answer < temp_ans) ? temp_ans : answer;
				number++;
			}
		}
	}
	cout << answer;
}