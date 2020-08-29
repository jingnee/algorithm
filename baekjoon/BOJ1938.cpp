/*통나무 옮기기*/
#include <iostream>
#include <cstring>
#include <queue>
#include <utility>
using namespace std;

int N;
char map[51][51];
int visit[51][51][2];
pair<int, int> start[3], endd[3];
queue<pair<pair<int, int>, int>> que;
int dr[8] = { -1,0,1,0,-1,-1,1,1 };
int dc[8] = { 0,1,0,-1,-1,1,1,-1 };
int end_dir;

int BFS() {
	while (!que.empty()) {
		pair<pair<int, int>,int> cur = que.front();
		que.pop();
		int r = cur.first.first;
		int c = cur.first.second;
		int dir = cur.second;

		if (map[r][c] == 'E' && dir == end_dir)return visit[r][c][dir];

		for (int d = 0; d < 4; d++) {
			switch (d) {				
			case 0:		//U
				if (dir == 0) {			//세로일 경우
					if (r - 2 < 0)continue;
					if (map[r-2][c]!= '1' && visit[r-1][c][0] == -1) {
						que.push(make_pair(make_pair(r - 1, c), dir));
						visit[r - 1][c][0] = visit[r][c][0] + 1;
					}
				}
				else if (dir == 1) {		//가로일 경우
					if (r - 1 < 0)continue;
					if (map[r - 1][c - 1] == '1' || map[r - 1][c] == '1' || map[r - 1][c + 1] == '1' || visit[r-1][c][1] != -1)continue;
						que.push(make_pair(make_pair(r - 1, c), dir));
						visit[r - 1][c][1] = visit[r][c][1] + 1;
				}
				break;
			case 1:		//R
				if (dir == 0) {		//세로일 경우
					if (c + 1>= N)continue;
					if (map[r - 1][c + 1] == '1' || map[r][c + 1] == '1' || map[r + 1][c + 1] == '1' || visit[r][c + 1][0] != -1)continue;
					que.push(make_pair(make_pair(r, c + 1), dir));
					visit[r][c + 1][0] = visit[r][c][0] + 1;
				}
				
				else if (dir == 1) {		//가로일 경우
					if (c + 2 >= N)continue;
					if (map[r][c+2] != '1' && visit[r][c+1][1] == -1) {
						que.push(make_pair(make_pair(r, c+1), dir));
						visit[r][c + 1][1] = visit[r][c][1] + 1;
					}
				}
				break;
			case 2:		//D
				if (dir == 0) {
					if (r + 2 >= N)continue;
					if (map[r + 2][c] != '1' && visit[r + 1][c][0] == -1) {
						que.push(make_pair(make_pair(r + 1, c), dir));
						visit[r + 1][c][0] = visit[r][c][0] + 1;
					}
				}
				else if (dir == 1) {
					if (r + 1 >= N)continue;
					if (map[r + 1][c - 1] == '1' || map[r + 1][c] == '1' || map[r + 1][c + 1] == '1' || visit[r + 1][c][1] != -1)continue;
					que.push(make_pair(make_pair(r + 1, c), dir));
					visit[r + 1][c][1] = visit[r][c][1] + 1;
				}
				break;
			case 3:		//L
				if (dir == 0) {
					if (c - 1 < 0)continue;
					if (map[r - 1][c - 1] == '1' || map[r][c - 1] == '1' || map[r + 1][c - 1] == '1' || visit[r][c - 1][0] != -1)continue;
					que.push(make_pair(make_pair(r, c - 1), dir));
					visit[r][c - 1][0] = visit[r][c][0] + 1;
				}
				else if (dir == 1) {
					if (c - 2 < 0)continue;
					if (map[r][c - 2] != '1' && visit[r][c - 1][1] == -1) {
						que.push(make_pair(make_pair(r, c - 1), dir));
						visit[r][c - 1][1] = visit[r][c][1] + 1;
					}
				}
				break;
			}
		}
		//회전 가능한지 
		bool flag = true;
		for (int d = 0; d < 8; d++) {
			if (r + dr[d] < 0 || r + dr[d] >= N || c + dc[d] < 0 || c + dc[d] >= N || map[r + dr[d]][c + dc[d]] == '1') {
				flag = false;
				break;
			}
		}
		//회전 가능하다면
		if (flag) {
			if (dir == 0 && visit[r][c][1] == -1) {
				visit[r][c][1] = visit[r][c][0] + 1;
				que.push(make_pair(make_pair(r, c), 1));
			}
			else if (dir == 1 && visit[r][c][0] == -1) {
				visit[r][c][0] = visit[r][c][1] + 1;
				que.push(make_pair(make_pair(r, c), 0));
			}
		}
	}
	return 0;
}

int main() {
	cin >> N;
	int idx_s = 0;
	int idx_e = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'B') {
				start[idx_s].first = i;
				start[idx_s++].second = j;
			}
			if (map[i][j] == 'E') {
				if (idx_e != 1) 
					map[i][j] = '0';
				
				endd[idx_e].first = i;
				endd[idx_e++].second = j;
			}
		}
	}

	memset(visit,-1, sizeof(visit));

	//세로인 경우
	if (start[0].second == start[1].second && start[1].second == start[2].second) {
		que.push(make_pair(make_pair(start[1].first, start[1].second), 0));
		visit[start[1].first][start[1].second][0] = 0;
	}
	//가로인 경우
	else if (start[0].first == start[1].first && start[1].first == start[2].first) {
		que.push(make_pair(make_pair(start[1].first, start[1].second), 1));
		visit[start[1].first][start[1].second][1] = 0;
	}

	//세로인 경우
	if (endd[0].second == endd[1].second && endd[1].second == endd[2].second) end_dir = 0;
	//가로인 경우
	else if (endd[0].first == endd[1].first && endd[1].first == endd[2].first) end_dir = 1;


	cout << BFS() << "\n";
	
}
