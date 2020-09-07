//경주로 건설
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#define INF 0xffffff
using namespace std;

int map[4][26][26];
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };

int solution(vector<vector<int>> board) {
	int answer = INF;
	int N = board.size();
	memset(map, 0x7f, sizeof(map));
	queue<pair<int, pair<int, int>>> que;
	//시작점을 오른쪽이랑 아래 두개 넣음
	if (board[0][1] == 0) {
		que.push(make_pair(1, make_pair(0, 1)));
		map[1][0][1] = 100;
	}
	if (board[1][0] == 0) {
		que.push(make_pair(2, make_pair(1, 0)));
		map[2][1][0] = 100;
	}
	map[0][0][0] = map[1][0][0] = map[2][0][0] = map[3][0][0] = 0;

	while (!que.empty()) {
		pair<int, pair<int, int>> temp = que.front();
		que.pop();
		if (temp.second.first == N - 1 && temp.second.second == N - 1)answer = (answer > map[temp.first][N - 1][N - 1]) ? map[temp.first][N - 1][N - 1] : answer;

		for (int d = 0; d < 4; d++) {
			int nr = temp.second.first + dr[d];
			int nc = temp.second.second + dc[d];
			if (nr < 0 || nc < 0 || nr >= N || nc >= N || board[nr][nc] == 1)continue;
			if (d == temp.first && map[d][nr][nc] > map[temp.first][temp.second.first][temp.second.second] + 100) {
				map[d][nr][nc] = map[temp.first][temp.second.first][temp.second.second] + 100;
				que.push(make_pair(d, make_pair(nr, nc)));
			}
			else if (d != temp.first && map[d][nr][nc] > map[temp.first][temp.second.first][temp.second.second] + 600) {
				map[d][nr][nc] = map[temp.first][temp.second.first][temp.second.second] + 600;
				que.push(make_pair(d, make_pair(nr, nc)));
			}
		}
	}
	return answer;
}

int main() {
	//cout << solution({{0, 0, 0, 0, 0, 0, 0, 1}, {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 1, 0, 0, 0}, {0, 0, 0, 1, 0, 0, 0, 1}, {0, 0, 1, 0, 0, 0, 1, 0}, {0, 1, 0, 0, 0, 1, 0, 0}, {1, 0, 0, 0, 0, 0, 0, 0}});
	cout << solution({ { 0, 0, 0, 0, 0, 0, 0, 1 },{ 0, 0, 0, 0, 0, 0, 0, 0 },{ 0, 0, 0, 0, 0, 1, 0, 0 },{ 0, 0, 0, 0, 1, 0, 0, 0 },{ 0, 0, 0, 1, 0, 0, 0, 1 },{ 0, 0, 1, 0, 0, 0, 1, 0 },{ 0, 1, 0, 0, 0, 1, 0, 0 },{ 1, 0, 0, 0, 0, 0, 0, 0 } });

}
