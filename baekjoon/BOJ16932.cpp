/*모양 만들기*/
#include <iostream>
#include <set>
#include <cstring>
#include <queue>
using namespace std;

int answer, N, M;
int map[1000][1000];
bool visit[1000][1000];
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };
vector<pair<int, int>> groupSize;

void BFS(int r, int c, int num) {
	int cnt = 1;
	map[r][c] = num;
	visit[r][c] = true;
	queue<pair<int, int>>que;
	que.push(make_pair(r, c));

	while (!que.empty()) {
		pair<int, int>temp = que.front();
		que.pop();

		for (int d = 0; d < 4; d++) {
			int nr = temp.first + dr[d];
			int nc = temp.second + dc[d];
			if (nr < 0 || nc < 0 || nr >= N || nc >= M)continue;
			if (map[nr][nc] == 1 && !visit[nr][nc]) {
				visit[nr][nc] = true;
				cnt++;
				map[nr][nc] = num;
				que.push(make_pair(nr, nc));
			}
		}
	}
	groupSize.push_back(make_pair(num, cnt));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];

	//그룹화
	int idx = 1;
	groupSize.push_back(make_pair(0, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 1 && !visit[i][j]) {
				BFS(i, j, idx++);
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0) {
				set<int> s;
				int num = 1;
				for (int d = 0; d < 4; d++) {
					int nr = i + dr[d];
					int nc = j + dc[d];
					if (nr < 0 || nc < 0 || nr >= N || nc >= M)continue;
					if (map[nr][nc] != 0)s.insert(map[nr][nc]);
				}
				for (auto itr : s) 
					num += groupSize[itr].second;
				
				answer = (answer < num) ? num : answer;
			}
		}
	}

	cout << answer << "\n";
}
