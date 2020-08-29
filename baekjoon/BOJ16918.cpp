//º½¹ö¸Ç
#include<iostream>
using namespace std;

int R, C, N;
char map[201][201];
int BombTime[200][200];
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };
void install(int time) {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] == '.') {
				map[i][j] = 'O';
				BombTime[i][j] = time + 3;
			}
		}
	}
}
void Bomb(int time) {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (BombTime[i][j] == time) {
				for (int d = 0; d < 4; d++) {
					int ni = i + dr[d];
					int nj = j + dc[d];
					if (ni < 0 || nj < 0 || ni >= R || nj >= C)continue;
					map[ni][nj] = '.';
				}
				map[i][j] = '.';
				BombTime[i][j] = 0;
			}
		}
	}
}

void print() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++)cout << map[i][j];
		cout << "\n";
	}
}
int main() {
	cin >> R >> C >> N;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'O')BombTime[i][j] = 3;
		}
	}
	int time = 2;
	while (time < N + 1) {
		if (time % 2 == 0)install(time);
		else Bomb(time);
		time++;
	}
	print();
}