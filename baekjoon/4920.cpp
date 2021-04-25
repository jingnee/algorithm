//테트리스 게임
#include <iostream>
#include <vector>
using namespace std;

int N, answer;
int tetris[][4][2] = {
	{{0,0},{0,1},{0,2},{0,3}},
	{{0,0},{1,0},{2,0},{3,0}},
	{{0,0},{0,1},{1,1},{1,2}},
	{{0,1},{1,1},{1,0},{2,0}},
	{{0,0},{0,1},{0,2},{1,2}},
	{{0,1},{1,1},{2,1},{2,0}},
	{{0,0},{1,0},{1,1},{1,2}},
	{{0,0},{0,1},{1,0},{2,0}},
	{{0,0},{0,1},{0,2},{1,1}},
	{{0,1},{1,1},{2,1},{1,0}},
	{{0,0},{1,0},{2,0},{1,1}},
	{{1,0},{1,1},{1,2},{0,1}},
	{{0,0},{0,1},{1,0},{1,1}}
};

int count_score(int r, int c, vector<vector<int>> &board) {
	int ret = -987654321;
	for (int b = 0; b < 13; b++) {
		bool flag = true;
		int tot = 0;
		for (int i = 0; i < 4; i++) {
			int nr = r + tetris[b][i][0];
			int nc = c + tetris[b][i][1];
			if (nr < 0 || nc < 0 || nr >= N || nc >= N) {
				flag = false;
				break;
			}
			tot += board[nr][nc];
		}
		if(flag) ret = (ret < tot) ? tot : ret;
	}
	return ret;
}

int main() {
	int test_case = 1;
	while (1) {
		answer = -987654321;
		int tot = 0;
		cin >> N;
		if (N == 0)break;

		vector<vector<int>> board(N,vector<int>(N,0));

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> board[i][j];
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				tot = count_score(i, j, board);
				answer = (answer < tot) ? tot : answer;
			}
		}
		cout << test_case++ << ". " << answer << endl;
	}
}
