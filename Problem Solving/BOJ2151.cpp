/*거울 설치*/
#include<iostream>
#include<queue>
using namespace std;

int N, answer;
char map[50][50];
//int visit[50][50];
int dr[4] = { 0,1,0,-1 };				//왼 아래 오른쪽 위쪽
int dc[4] = { -1,0,1,0 };
struct MIRROR {
	int count, r, c, dir;
};

bool operator<(MIRROR a, MIRROR b) {
	return a.count > b.count;
}

priority_queue<MIRROR> mirrors;
int door[2][2];

void BFS() {
	while (!mirrors.empty()) {

		MIRROR m = mirrors.top();
		mirrors.pop();

		int nr = m.r + dr[m.dir];
		int nc = m.c + dc[m.dir];
		if (nr<0 || nc<0 || nr>N || nc>N)continue;
		while (map[nr][nc] == '.') {
			nr += dr[m.dir];
			nc += dc[m.dir];
		}

		if (nr == door[1][0] && nc == door[1][1]) {
			answer = m.count;
			return;
		}

		if (nr >= 0 && nc >= 0 && nr < N && nc < N && map[nr][nc] == '!') {
			//visit[nr][nc] = 1;
			MIRROR temp;
			temp.r = nr;
			temp.c = nc;
			temp.count = m.count + 1;
			int dir = m.dir - 1;
			if (dir < 0)dir = 3;			//거울위치에서 갈 수 있는 두방향다 큐에 넣어줌
			temp.dir = dir;
			mirrors.push(temp);
			dir = m.dir + 1;
			if (dir > 3)dir = 0;
			temp.dir = dir;
			mirrors.push(temp);
			//설치 안하는 경우도 있음
			temp.dir = m.dir;
			temp.count = m.count;
			mirrors.push(temp);
		}
	}
}
int main() {
	cin >> N;
	int index = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == '#') {
				door[index][0] = i;
				door[index++][1] = j;
			}
		}
	}
	MIRROR mirror;
	mirror.count = 0;
	mirror.r = door[0][0];
	mirror.c = door[0][1];
	for (int i = 0; i < 4; i++) {
		mirror.dir = i;
		mirrors.push(mirror);
	}
	//visit[door[0][0]][door[0][1]] = 1;
	BFS();
	cout << answer << endl;

}