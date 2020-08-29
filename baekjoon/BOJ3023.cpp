#include <iostream>
using namespace std;

char map[101][101];
int main() {
	int R, C;
	int error_r, error_c;
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
		}
	}
	cin >> error_r >> error_c;

	for (int r = 0; r < R; r++) {		// 오른쪽 채우기
		for (int i = 0; i < C; i++) {
			map[r][C + i] = map[r][C - 1 - i];
		}
	}
	for (int c = 0; c < 2*C; c++) {		// 아래쪽 채우기
		for (int i = 0; i < R; i++) {
			map[R + i][c] = map[R - 1 - i][c];
		}
	}

	if (map[error_r-1][error_c-1] == '.') map[error_r-1][error_c-1] = '#';
	else map[error_r-1][error_c-1] = '.';

	for (int i = 0; i < 2*R; i++) {
		for (int j = 0; j < 2*C; j++)
			cout << map[i][j];
		cout << endl;
	}
}