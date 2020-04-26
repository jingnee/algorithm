/*다리 만들기*/
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int N, answer = 2e9;
int map[100][100];
bool visit[100][100];
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };

void Indexing(int r, int c, int num) {
	queue<pair<int, int>> que;
	que.push(make_pair(r, c));
	map[r][c] = num;

	while (!que.empty()) {
		pair<int, int> cur = que.front();
		que.pop();

		for (int d = 0; d < 4; d++) {
			int nr = cur.first + dr[d];
			int nc = cur.second + dc[d];
			if (nr < 0 || nc < 0 || nr >= N || nc >= N)continue;
			if (map[nr][nc] != 0)continue;
			que.push(make_pair(nr, nc));
			map[nr][nc] = num;
		}
	}
}

int findBridge(int idx) {
	int ans = 0;

	queue<pair<int, int>> que;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == idx) {
				que.push(make_pair(i, j));
				visit[i][j] = true;
			}
		}
	}

	while (!que.empty()) {
		int size = que.size();
		for (int s = 0; s < size; s++) {
			pair<int, int> cur = que.front();
			que.pop();
			for (int d = 0; d < 4; d++) {
				int nr = cur.first + dr[d];
				int nc = cur.second + dc[d];
				if (nr < 0 || nc < 0 || nr >= N || nc >= N)continue;
				if (visit[nr][nc])continue;
				if (map[nr][nc] != -1 && map[nr][nc] != idx) return ans;
				visit[nr][nc] = true;
				que.push(make_pair(nr, nc));
			}
		}
		ans++;		
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int num;
			cin >> num;
			if (num == 0)map[i][j] = -1;
			else map[i][j] = 0;
		}
	}

	int index = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 0)Indexing(i, j, index++);
		}
	}

	for (int i = 1; i < index; i++) {
		memset(visit, false, sizeof(visit));
		int ans = findBridge(i);
		if (ans < answer)answer = ans;
	}

	cout << answer << "\n";
}
