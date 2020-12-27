//오목
#include <iostream>
using namespace std;

int board[21][21];

bool isWin(int r, int c) {
	int color = board[r][c];
	int cnt = 0;
	//가로확인
	for (int i = c; i < c + 5 && i < 19; i++) {
		if (board[r][i] != color)break;
		cnt++;
	}
	if (cnt == 5 && (c==0 || (c > 0 && board[r][c - 1] != color)) && (c+5>=19 || (c + 5 < 19 && board[r][c + 5] != color)))return true;
	cnt = 0;

	//세로 확인
	for (int i = r; i < r + 5 && i < 19; i++) {
		if (board[i][c] != color)break;
		cnt++;
	}
	if (cnt == 5 && (r==0 || (r > 0 && board[r - 1][c] != color)) && (r+5>=19 || (r + 5 < 19 && board[r + 5][c] != color)))return true;
	cnt = 0;

	//우측위 대각선 확인
	for (int i = 0; i < 5 && r - i >= 0 && c + i < 19; i++) {
		if (board[r - i][c + i] != color)break;
		cnt++;
	}
	if (cnt == 5 && (r < 5 || c + 5 >= 19 || (r >= 5 && c + 5 < 19 && board[r - 5][c + 5] != color)) && (r == 18 || c == 0 || (r < 19 && c > 0 && board[r + 1][c - 1] != color)))return true;
	cnt = 0;

	//우측아래 대각선 확인
	for (int i = 0; i < 5 && r + i < 19 && c + i < 19; i++) {
		if (board[r + i][c + i] != color)break;
		cnt++;
	}
	if (cnt == 5 && (r + 5 >= 19 || c + 5 >= 19 || (r + 5 < 19 && c + 5 < 19 && board[r + 5][c + 5] != color)) && (r == 0 || c == 0 || (r > 0 && c > 0 && board[r - 1][c - 1] != color)))return true;
	cnt = 0;

	return false;
}

int main() {
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			if (board[i][j] != 0) {
				if (isWin(i, j)) {
					if (board[i][j] == 1) {
						cout << "1\n";
					}
					else cout << "2\n";
					cout << i+1 << " " << j+1;
					return 0;
				}
			}
		}
	}
	cout << "0";
}