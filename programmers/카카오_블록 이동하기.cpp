#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

int map[2][101][101];
int moveD[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };

int solution(vector<vector<int>> board) {
	int answer = 0;
	int N = board.size();
	memset(map, 0x7f, sizeof(map));
	queue<pair<int, pair<int, int>>> que;
	que.push(make_pair(0, make_pair(0, 0)));
	map[0][0][0] = 0;

	while (!que.empty()) {
			int dir = que.front().first;
			int r = que.front().second.first;
			int c = que.front().second.second;
			que.pop();
			if ((r == N - 1 && c == N - 2 && dir == 0) || (r == N - 2 && c == N - 1 && dir == 1)) {
				answer = map[dir][r][c];
				break;
			}

			// ㅡ 모양일때
			if (dir == 0) {
				//이동
				for (int d = 0; d < 4; d++) {
					int nr = r + moveD[d][0];
					int nc = c + moveD[d][1];
					if (nr < 0 || nc < 0 || nr >= N || nc >= N - 1 || board[nr][nc] == 1 || board[nr][nc + 1] == 1)continue;
					if (map[0][nr][nc] > map[0][r][c] + 1) {
						map[0][nr][nc] = map[0][r][c] + 1;
  						que.push(make_pair(0, make_pair(nr, nc)));
					}
				}
				//위로 돌리기
				if ((r - 1 >= 0 && c + 1 < N )&& (board[r - 1][c] == 0 && board[r - 1][c + 1] == 0)) {
					if (map[1][r - 1][c] > map[0][r][c] + 1) {
						map[1][r - 1][c] = map[0][r][c] + 1;
						que.push(make_pair(1, make_pair(r - 1, c)));
					}
					if (map[1][r - 1][c + 1] > map[0][r][c] + 1) {
						map[1][r - 1][c + 1] = map[0][r][c] + 1;
						que.push(make_pair(1, make_pair(r - 1, c + 1)));
					}
				}
				//아래로 돌리기
				if ((r + 1 < N && c + 1 < N) && (board[r + 1][c] == 0 && board[r + 1][c + 1] == 0)) {
					if (map[1][r][c] > map[0][r][c] + 1) {
						map[1][r][c] = map[0][r][c] + 1;
						que.push(make_pair(1, make_pair(r, c)));
					}
					if (map[1][r][c + 1] > map[0][r][c] + 1) {
						map[1][r][c + 1] = map[0][r][c] + 1;
						que.push(make_pair(1, make_pair(r, c + 1)));
					}
				}
			}
			// | 모양일때
			else if (dir == 1) {
				//이동
				for (int d = 0; d < 4; d++) {
					int nr = r + moveD[d][0];
					int nc = c + moveD[d][1];
					if (nr < 0 || nc < 0 || nr >= N - 1 || nc >= N || board[nr][nc] == 1 || board[nr + 1][nc] == 1)continue;
					if (map[1][nr][nc] > map[1][r][c] + 1) {
						map[1][nr][nc] = map[1][r][c] + 1;
						que.push(make_pair(1, make_pair(nr, nc)));
					}
				}
				//왼쪽으로 돌리기
				if ((r + 1 < N && c - 1 >= 0) && (board[r][c - 1] == 0 && board[r + 1][c - 1] == 0)) {
					if (map[0][r][c - 1] > map[1][r][c] + 1) {
						map[0][r][c - 1] = map[1][r][c] + 1;
						que.push(make_pair(0, make_pair(r, c - 1)));
					}
					if (map[0][r + 1][c - 1] > map[1][r][c] + 1) {
						map[0][r + 1][c - 1] = map[1][r][c] + 1;
						que.push(make_pair(1, make_pair(r + 1, c - 1)));
					}
				}
				//오른쪽으로 돌리기
				if ((r + 1 < N && c + 1 < N) && (board[r][c + 1] == 0 && board[r + 1][c + 1] == 0)) {
					if (map[0][r][c] > map[1][r][c] + 1) {
						map[0][r][c] = map[1][r][c] + 1;
						que.push(make_pair(0, make_pair(r, c)));
					}
					if (map[0][r + 1][c] > map[1][r][c] + 1) {
						map[0][r + 1][c] = map[1][r][c] + 1;
						que.push(make_pair(0, make_pair(r + 1, c)));
					}
				}
			}
	}
	return answer;
}

int main() {
	//cout << solution({{0, 0, 0, 1, 1}, {0, 0, 0, 1, 0}, {0, 1, 0, 1, 1}, {1, 1, 0, 0, 1}, {0, 0, 0, 0, 0}});
	//cout << solution({ {0, 0, 0, 0, 0, 0, 1},{1, 1, 1, 1, 0, 0, 1},{0, 0, 0, 0, 0, 0, 0},{0, 0, 1, 1, 1, 1, 0},{0, 1, 1, 1, 1, 1, 0},{0, 0, 0, 0, 0, 1, 1},{0, 0, 1, 0, 0, 0, 0} });
	//cout << solution({ { 0, 0, 0, 0, 0, 0, 1 },{ 1, 1, 1, 1, 0, 0, 1 },{ 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 1, 1, 1, 0, 0 },{ 0, 1, 1, 1, 1, 1, 0 },{ 0, 0, 0, 0, 0, 1, 0 },{ 0, 0, 1, 0, 0, 0, 0 } });
	cout << solution({ { 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 1, 1, 1, 1, 1, 1, 1, 0, 0 },{ 1, 1, 1, 1, 1, 1, 1, 1, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 1, 1, 1, 1, 1, 0, 0 },{ 0, 1, 1, 1, 1, 1, 1, 1, 1 },{ 0, 0, 1, 1, 1, 1, 1, 0, 0 },{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },{ 1, 1, 1, 1, 1, 1, 1, 1, 0 } });
}
