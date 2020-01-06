// 다오의 데이트
#include<iostream>
using namespace std;

char map[21][21];
int H, W, N;
char answer[20];
char marid[20][2];
int dao[2][2];			//dao[0]에는 dao위치, dao[1]에는 dizney위치
int w;

bool search(int y, int x, int n) {
	if (n == N)return false;
	if (map[y][x] == 'Z')return true;
	//for (int i = 0; i < 2; i++) {
		char ch = marid[n][i];
		int ny, nx;
		switch (ch) {
		case 'A':
			ny = y;
			nx = x - 1;
			answer[w] = 'A';
			break;
		case 'W':
			ny = y - 1;
			nx = x;
			answer[w] = 'W';
			break;
		case 'S':
			ny = y + 1;
			nx = x;
			answer[w] = 'S';
			break;
		case 'D':
			ny = y;
			nx = x + 1;
			answer[w] = 'D';
			break;
		}
		if (ny < 0 || nx < 0 || ny >= N || nx >= N || map[ny][nx] == '@') {
			//search(y, x, n);
			//continue;
		}

		else {
			w++;
			search(ny, nx, n + 1);
		}

//	}
}
int main() {
	cin >> H >> W;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'D') {
				dao[0][0] = i;
				dao[0][1] = j;
			}
			else if (map[i][j] == 'Z') {
				dao[1][0] = i;
				dao[1][1] = j;
			}
		}
	}
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> marid[i][0];
		cin >> marid[i][1];
	}
	
	bool ans = search(dao[0][0], dao[0][1], 0);
	if (ans == 0)cout << "NO";
	else {
		cout << "YES" << endl;
		for (int r = 0; r < w; r++)
			cout << answer[r];
	}

}