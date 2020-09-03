/*점프왕 쩰리 (Large) */
#include <iostream>
#include <queue>
using namespace std;

int N;
int map[65][65];
bool visit[65][65];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	queue<pair<int, int>> que;
	que.push(make_pair(0, 0));
	visit[0][0] = true;

	while (!que.empty()) {
		pair<int, int> temp = que.front();
		if (map[temp.first][temp.second] == -1) {
			cout << "HaruHaru\n";
			return 0;
		}
		que.pop();

		//오른쪽으로 이동
		int nr = temp.first + map[temp.first][temp.second];
		int nc = temp.second;
		if ((nr < N && nc < N) && !visit[nr][nc]) {
			visit[nr][nc] = true;
			que.push(make_pair(nr, nc));
		}
		//아래로 이동
		nr = temp.first;
		nc = temp.second + map[temp.first][temp.second];
		if ((nr < N && nc < N) && !visit[nr][nc]) {
			visit[nr][nc] = true;
			que.push(make_pair(nr, nc));
		}
	}

	cout << "Hing\n";
	return 0;
}
