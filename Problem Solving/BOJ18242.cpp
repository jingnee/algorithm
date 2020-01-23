/*
[백준] 네모네모 시력검사
1. 오른쪽(0), 아래쪽(1), 왼쪽(2), 위쪽(3) 순서로 탐색
2. #이 나타날때마다 주변 #의 갯수를 체크-->BFS()
	주변 #의 갯수가 1개이면 그 방향을 리턴
	만약 다음 이동해야할 장소가 .이거나 범위를 벗어나면 방향을 바꾸어줌
--------------------------------------------------------------------------
	이동은 시계방향
	오른쪽으로 이동중에 구멍이있으면 위에가 뚫린거
	아래쪽으로 이동중에 구멍이 있으면 오른쪽이 뚫린거
	왼쪽으로 이동중에 구멍이 있으면 아래쪽이 뚫린거
	위쪽으로 이동중에 구멍이 있으면 외쪽이 뚫린거
*/

#include<iostream>
#include<string>
using namespace std;

char map[101][101];
string direction[4] = { "UP", "RIGHT", "DOWN", "LEFT" };
int dr[4] = { 0,1,0,-1 };
int dc[4] = { 1,0,-1,0 };
int N, M;

void BFS(int r, int c, int d) {
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];
		if (map[nr][nc] == '#')cnt++;
	}
	if (cnt >= 2) {
		int nr = r + dr[d];
		int nc = c + dc[d];
		if (nr >= 0 && nc >= 0 && nr < N && nc < M && map[nr][nc] == '#')BFS(nr, nc, d);
		else {
			int nr = r + dr[d + 1];
			int nc = c + dc[d + 1];
			BFS(nr, nc, d + 1);
		}
	}
	else if (cnt == 1) {
		cout << direction[d];
		return;
	}
}
int main() {
	cin >> N >> M;
	int sr, sc, flag = 0;				//sr,sc는 가장왼쪽 위에있는 #
	for (int i = 0; i < N; i++)cin >> map[i];

	for (int i = 0; i < N; i++) {
		if (flag == 1)break;
		for (int j = 0; j < M; j++) {
			if (map[i][j] == '#') {
				sr = i;
				sc = j;
				flag = 1;
				break;
			}
		}
	}
	BFS(sr, sc, 0);
	return 0;
}