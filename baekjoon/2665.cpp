//미로 만들기
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int map[51][51];
int doorNum[51][51];
int N;
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };

int main() {
	memset(doorNum, 0x7f, sizeof(doorNum));
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	queue<pair<pair<int, int>, int>> que;
	que.push(make_pair(make_pair(0, 0), 0));
	while (!que.empty()) {
		int r = que.front().first.first;
		int c = que.front().first.second;
		int cnt = que.front().second;
		que.pop();

		for (int d = 0; d < 4; d++) {
			int nr = r + dr[d];
			int nc = c + dc[d];
			if (nr < 0 || nc < 0 || nr >= N || nc >= N )continue;
			//다음 방이 검은색이면
			if (map[nr][nc] == 0) {
				//지금 가는 경우가 문을 조금 연 상태
				if (doorNum[nr][nc] > cnt + 1) {
					doorNum[nr][nc] = cnt + 1;
					que.push(make_pair(make_pair(nr, nc), cnt + 1));
				}
			}
			else {
				//지금 가는 경우가 문을 조금 연 상태
				if (doorNum[nr][nc] > cnt) {
					doorNum[nr][nc] = cnt;
					que.push(make_pair(make_pair(nr, nc), cnt));
				}
			}
		}
	}
	cout << doorNum[N - 1][N - 1];
}
