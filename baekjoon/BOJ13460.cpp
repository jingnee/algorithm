///*구슬 탈출2*/
#include <iostream>
#include <queue>
#include <math.h>
using namespace std;

int red[2];
int blue[2];
char map[11][11];
bool visit[11][11][11][11];
int N, M;
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };
struct bead {
	int rr, rc, br, bc, cnt;
};

int BFS() {
	queue<bead> que;
	que.push({ red[0],red[1],blue[0],blue[1],0 });
	visit[red[0]][red[1]][blue[0]][blue[1]] = true;

	while (!que.empty()) {
		bead temp = que.front();
		que.pop();

		if (temp.cnt > 10)return -1;
		if (map[temp.rr][temp.rc] == 'O')return temp.cnt;

		for (int d = 0; d < 4; d++) {
			//빨간색 구슬 이동
			int red_nr = temp.rr;
			int red_nc = temp.rc;
			while (map[red_nr+dr[d]][red_nc+dc[d]]!='#' && map[red_nr][red_nc] != 'O') {
				red_nr += dr[d];
				red_nc += dc[d];
			}
			//파란색 구슬 이동
			int blue_nr = temp.br;
			int blue_nc = temp.bc;
			while (map[blue_nr+dr[d]][blue_nc+dc[d]] != '#' && map[blue_nr][blue_nc] != 'O') {
				blue_nr += dr[d];
				blue_nc += dc[d];
			}

			//겹치는지 확인
			if (red_nr == blue_nr && red_nc == blue_nc) {
				if (map[red_nr][red_nc] == 'O')continue;
				//빨간색 이동거리가 더 큼 -> 같은 칸에 도달하기 위해 더 이전위치부터 간거니까 파란색보다 이전에있어야함
				if (abs(red_nr - temp.rr) + abs(red_nc - temp.rc) > abs(blue_nr - temp.br) + abs(blue_nc - temp.bc)) {
					red_nr -= dr[d];
					red_nc -= dc[d];
				}
				
				else {
					blue_nr -= dr[d];
					blue_nc -= dc[d];
				}
			}

			//방문한적이 없으면 que에 추가
			if (!visit[red_nr][red_nc][blue_nr][blue_nc]) {
				que.push({ red_nr,red_nc,blue_nr,blue_nc,temp.cnt + 1 });
				visit[red_nr][red_nc][blue_nr][blue_nc] = true;
			}
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

		cin >> N >> M;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> map[i][j];
				if (map[i][j] == 'R') {
					red[0] = i;
					red[1] = j;
				}
				else if (map[i][j] == 'B') {
					blue[0] = i;
					blue[1] = j;
				}
			}
		}
		cout << BFS() << "\n";
}
