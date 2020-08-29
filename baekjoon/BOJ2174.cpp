#include <iostream>
#include <vector>
using namespace std;
#define MAX 100

struct robot {
	int r, c, dir;
};
struct command {
	int num;
	char cmd;
	int cnt;
};
robot Robots[MAX];
vector<command> Command;

int map[MAX][MAX];
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };
int A, B, N, M;
int changeDir(char c) {
	if (c == 'N')return 0;
	else if (c == 'E')return 1;
	else if (c == 'S')return 2;
	else return 3;
}
int main() {
	cin >> A >> B >> N >> M;
	for (int i = 1; i <= N; i++){
		int x, y;
		char dir;
		cin >> x >> y >> dir;
		int d = changeDir(dir);
		Robots[i] = { B - y,x - 1,d };
		map[B - y][x - 1] = i;
	}
	for (int i = 0; i < M; i++) {
		int num, cnt;
		char cmd;
		cin >> num >> cmd >> cnt;
		Command.push_back({ num,cmd,cnt });
	}

	for (int i = 0; i < M; i++) {
		int rep = Command[i].cnt;
		while (rep--) {
			if (Command[i].cmd == 'F') {
				int r = Robots[Command[i].num].r;
				int c = Robots[Command[i].num].c;
				int dir = Robots[Command[i].num].dir;
				int nr = r + dr[dir];
				int nc = c + dc[dir];
				if (nr < 0 || nc < 0 || nr >= B || nc >= A) {
					printf("Robot %d crashes into the wall\n", Command[i].num);
					return 0;
				}
				if (map[nr][nc] != 0) {
					printf("Robot %d crashes into robot %d\n", Command[i].num, map[nr][nc]);
					return 0;
				}
				else {
					map[nr][nc] = map[r][c];
					map[r][c] = 0;
					Robots[Command[i].num] = { nr,nc,dir };
				}
			}
			else if (Command[i].cmd == 'L') {
				int dir = Robots[Command[i].num].dir;
				Robots[Command[i].num].dir = (dir + 3) % 4;
			}
			else if (Command[i].cmd == 'R') {
				int dir = Robots[Command[i].num].dir;
				Robots[Command[i].num].dir = (dir + 1) % 4;
			}
		}
	}
	cout << "OK\n";
}