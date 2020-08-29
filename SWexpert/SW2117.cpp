/* 홈 방범 서비스*/

#include <iostream>
#include <queue>
using namespace std;

int N, M;
int map[20][20];
int visit[20][20];
int answer;
struct pos {
	int r;
	int c;
};
queue<pos> que;
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };

void init() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visit[i][j] = 0;
		}
	}
}
int main() {
	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		cin >> N >> M;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
			}
		}
		
		answer = 1;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				init();
				pos p;
				p.r = i;
				p.c = j;
				que.push(p);
				int idx = 1;
				int home = 0;
				if (map[i][j] == 1)home=1;
				visit[i][j] = 1;

				while (!que.empty()) {
					int size = que.size();
					idx++;
					
					for (int k = 0; k < size; k++) {
						pos temp = que.front();
						que.pop();
						//visit[temp.r][temp.c] = 1;

						for (int dir = 0; dir < 4; dir++) {
							int nr = temp.r + dr[dir];
							int nc = temp.c + dc[dir];
							if (nr >= 0 && nc >= 0 && nr < N && nc < N && !visit[nr][nc]) {
								visit[nr][nc] = 1;
								pos p;
								p.r = nr;
								p.c = nc;
								que.push(p);
								if (map[nr][nc] == 1)home++;
							}
						}
					}
					if ((M*home - (idx*idx + (idx - 1)*(idx - 1))) >= 0)answer = (answer < home) ? home : answer;
				}
			}
		}
		cout << "#" << test_case << ' ' << answer << endl;

	}
}