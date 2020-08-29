#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define INF 987654321

int N;
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };
int main() {
	int problem_num = 1;

	while(1) {
		cin >> N;
		if (N == 0)break;
		vector<vector<int>> map(N, vector<int>(N, 0));
		vector<vector<int>> map2(N, vector<int>(N, INF));

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
			}
		}

		map2[0][0] = map[0][0];
		priority_queue<pair<int, pair<int, int>>> pq;
		pq.push(make_pair(-map[0][0], make_pair(0, 0)));

		while (!pq.empty()) {
			int r = pq.top().second.first;
			int c = pq.top().second.second;
			int cost = -pq.top().first;
			pq.pop();

			for (int dir = 0; dir < 4; dir++) {
				int nr = r + dr[dir];
				int nc = c + dc[dir];
				if (nr >= 0 && nc >= 0 && nr < N && nc < N) {
					if (map2[nr][nc] < cost)continue;
					int ncost = cost + map[nr][nc];
					if (map2[nr][nc] > ncost) {
						map2[nr][nc] = ncost;
						pq.push(make_pair(-ncost, make_pair(nr, nc)));
					}
				}
			}
		}
		cout << "Problem " << problem_num++ << ": " << map2[N - 1][N - 1] << endl;
	}

}