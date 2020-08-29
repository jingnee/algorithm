/*재밌는 오셀로 게임
1: 검
2: 흰*/
#include <iostream>
#include <cstring>
using namespace std;

int map[9][9];
int N, M;
int blackNum, whiteNum;
int dr[8] = { -1,-1,-1,0,1,1,1,0 };
int dc[8] = { -1,0,1,1,1,0,-1,-1 };

void game(int r, int c, int d) {
	map[r][c] = d;
	int other = (d == 1) ? 2 : 1;				//현재돌이 2(흰돌이면) 상대돌은 1(검은돌)
	for (int dir = 0; dir < 8; dir++) {
		int count = 0;

		int nr = r + dr[dir];
		int nc = c + dc[dir];
		if (nr < 1 || nc < 1 || nr > N || nc > N || map[nr][nc] != other)continue;
		while (map[nr][nc] == other) {
			count++;
			nr += dr[dir];
			nc += dc[dir];
		}
		if (nr >= 1 && nc >= 1 && nr <= N && nc <= N && map[nr][nc] == d) {
			for (int rr = r + dr[dir], cc = c + dc[dir], i=0; i < count; i++) {
				map[rr][cc] = d;
				rr += dr[dir];
				cc += dc[dir];
			}
		}
	}
}

void count() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (map[i][j] == 1)blackNum++;
			else if(map[i][j]==2)whiteNum++;
		}
	}
}

int main() {
	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		cin >> N >> M;
		//초깃값 설정
		memset(map, 0, sizeof(map));			//초깃값!!

		map[N / 2][N / 2] = 2;
		map[N / 2][N / 2 + 1] = 1;
		map[N / 2 + 1][N / 2] = 1;
		map[N / 2 + 1][N / 2 + 1] = 2;
		
		for (int i = 0; i < M; i++) {
			int r, c, d;
			cin >> r >> c >> d;
			game(r, c, d);
		}
		count();
		cout << "#" << test_case << " " << blackNum << " " << whiteNum << endl;
		blackNum = 0;
		whiteNum = 0;

	}
}