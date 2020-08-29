//거울 설치

#include <iostream>
#include <algorithm>
using namespace std;

#define INF 987654321

bool visit[50][50][4];
int mirror[2500][2];
int mirror_num;
char map[50][50];
int door[2][2];				//door[0]은 첫번째 문, door[1]은 도착지 문
int dr[4] = { 0,1,0,-1 };
int dc[4] = { -1,0,1,0 };
int N, answer;

void visit_init() {
	for (int i = 0; i < mirror_num; i++){
		for (int j = 0; j < 4; j++) {
			visit[mirror[i][0]][mirror[i][1]][j] = false;
		}
	}
}
void dfs(int r, int c, int dir, int cnt) {
	int nr, nc;
	nr = r + dr[dir];
	nc = c + dc[dir];
	if (nr == door[1][0] && nc == door[1][1]) {		//다음 좌표가 문인 경우
		answer = min(answer, cnt);
		return;
	}
	else if (map[nr][nc] == '*')return;				//다음 좌표가 벽인 경우
	else if (map[nr][nc] == '.')dfs(nr, nc, dir, cnt);		//계속 감
	else if (map[nr][nc] == '!') {		//다음 좌표가 거울일 경우
		for (int i = -1; i < 2; i++) {	//거울을 만나면 가능한 방향은 세가지
			int dd = dir;
			dd += i;
			if (dd < 0)dd = 3;
			else if (dd > 3)dd = 0;
			if (visit[nr][nc][dd] == false) {			
				visit[nr][nc][dd] = true;
				if (dd != dir) {
					dfs(nr, nc, dd, cnt + 1);
					visit[nr][nc][dd] = false;
				}
				else {
					dfs(nr, nc, dd, cnt);
					visit[nr][nc][dd] = false;
				}
			}
		}
	}
}

int main() {
	cin >> N;
	int dor = 0;
	for (int i = 0; i < N; i++) {			//map 입력받기
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == '#') {
				door[dor][0] = i;
				door[dor++][1] = j;
			}
			else if (map[i][j] == '!') {
				mirror[mirror_num][0] = i;
				mirror[mirror_num++][1] = j;
			}
		}
	}

	answer = INF;

	dfs(door[0][0], door[0][1], 1, 0);			//문이 위
	visit_init();
	dfs(door[0][0], door[0][1], 2, 0);			//문이 왼쪽
	visit_init();
	dfs(door[0][0], door[0][1], 3, 0);			//문이 아래
	visit_init();
	dfs(door[0][0], door[0][1], 0, 0);			//문이 오른쪽
	visit_init();
	//answer = INF;
	//dfs(door[0][0], door[0][1], direction, 0);
	cout << answer << endl;
}



