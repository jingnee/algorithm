/*치즈 도둑*/
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int map[100][100];
int visit[100][100];
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };
int N, answer;
void eatChees(int eat) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == eat)visit[i][j] = -1;
		}
	}
}

int count(int eat) {
	queue<pair<int, int>> pos;
	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visit[i][j] != eat && map[i][j] > eat) {
				visit[i][j] = eat;
				pos.push(make_pair(i, j));
				while (!pos.empty()) {
					pair<int, int> temp = pos.front();
					pos.pop();
					for (int d = 0; d < 4; d++) {
						int nr = temp.first + dr[d];
						int nc = temp.second + dc[d];
						//범위안에 들고
						if (nr >= 0 && nc >= 0 && nr < N && nc < N) {
							if (visit[nr][nc] != -1 && visit[nr][nc] != eat) {	//먹지 않고, 방문하지 않았으면
								visit[nr][nc] = eat;
								pos.push(make_pair(nr, nc));
							}
						}
					}
				}
				ans++;
			}
		}
	}
	return ans;
}

int main() {
	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		cin >> N;
		int maxNum = 0;
		answer = 1;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
				if (maxNum < map[i][j])maxNum = map[i][j];
			}
		}
		for (int eat = 1; eat < maxNum; eat++) {
			eatChees(eat);
			int num = count(eat);
			answer = (answer < num) ? num : answer;
		}
		cout << "#" << test_case << " " << answer << "\n";
		answer = 0;
		memset(visit, 0, sizeof(visit));
	}
}