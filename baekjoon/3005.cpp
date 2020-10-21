//크로스워드 퍼즐 쳐다보기
#include <iostream>
#include <string>
using namespace std;

int R, C;
char puzzle[25][25];
string ans = "zzzzzzzzzzzzzzzzzzzz";

string findWord(int r, int c, int d) {
	string str = "";
	//세로
	if (d == 0) {
		while (r < R && puzzle[r][c] != '#')str += puzzle[r++][c];
	}
	//가로
	else {
		while (c < C && puzzle[r][c] != '#')str += puzzle[r][c++];
	}
	return str;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> R >> C;
	for (int i = 0; i < R; i++)cin >> puzzle[i];
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (puzzle[i][j] == '#')continue;
			if (i==0 || puzzle[i - 1][j] == '#') {
				string ret = findWord(i, j, 0);
				if (ret.length() < 2)continue;
				ans = (ans > ret) ? ret : ans;
			}
			if (j == 0 || puzzle[i][j - 1] == '#') {
				string ret = findWord(i, j, 1);
				if (ret.length() < 2)continue;
				ans = (ans > ret) ? ret : ans;
			}
		}
	}
	cout << ans;
}
