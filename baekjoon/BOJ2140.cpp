/*지뢰찾기*/
#include <iostream>
using namespace std;

//지뢰가 있으면 9, 없으면 -1
int map[100][100];
int N;
int dr[8] = { -1,-1,-1,0,1,1,1,0 };
int dc[8] = { -1,0,1,1,1,0,-1,-1 };

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			char c;
			cin >> c;
			if (c == '#')map[i][j] = 9;
			else map[i][j] = c - '0';
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int flag = 0;
			if (map[i][j] == 9) {
				for (int d = 0; d < 8; d++) {
					int nr = i + dr[d];
					int nc = j + dc[d];
					if (nr < 0 || nc < 0 || nr >= N || nc >= N)continue;
					if (map[nr][nc] == 0) {
						map[i][j] = -1;
						flag = 1;
						break;
					}
				}
				if (flag != 1) {
					for (int d = 0; d < 8; d++) {
						int nr = i + dr[d];
						int nc = j + dc[d];
						if (nr < 0 || nc < 0 || nr >= N || nc >= N)continue;
						if (map[nr][nc] > 0 && map[nr][nc] < 9)map[nr][nc]--;
					}
				}
			}
		}
	}

	int answer = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 9)answer++;
		}
	}
	cout << answer << "\n";
}