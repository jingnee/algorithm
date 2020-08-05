/*나이트의 이동*/
#include <iostream>
#include <queue>
using namespace std;

int N;
int knight[2];
int goal[2];
int dr[8] = { -1,-2,-2,-1,1,2,2,1 };
int dc[8] = { -2,-1,1,2,2,1,-1,-2 };
bool visit[301][301];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	
	cin >> T;
	for (int test_case = 0; test_case < T; test_case++) {
		cin >> N >> knight[0] >> knight[1] >> goal[0] >> goal[1];
		queue<pair<int,pair<int, int>>> que;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				visit[i][j] = false;
			}
		}
		que.push(make_pair(0,make_pair(knight[0], knight[1])));
		visit[knight[0]][knight[1]] = true;

		while (!que.empty()) {
			pair<int, pair<int, int>> temp = que.front();
			que.pop();
			if (temp.second.first == goal[0] && temp.second.second == goal[1]) {
				cout << temp.first << "\n";
				break;
			}

			for (int d = 0; d < 8; d++) {
				int nr = temp.second.first + dr[d];
				int nc = temp.second.second + dc[d];
				if (nr < 0 || nc < 0 || nr >= N || nc >= N)continue;
				if (visit[nr][nc])continue;
				visit[nr][nc] = true;
				que.push(make_pair(temp.first + 1, make_pair(nr, nc)));
			}
		}
	}
}
