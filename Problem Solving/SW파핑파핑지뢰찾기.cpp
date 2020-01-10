#include<iostream>
using namespace std;

int map[300][300];
bool visit[300][300];
int dc[8] = { -1,0,1,1,1,0,-1,-1 };
int dr[8] = { -1,-1,-1,0,1,1,1,0 };
int N;
int read, w;
int click_num;
struct pos {
	int r, c;
};
pos queue[90000];

void bfs(int r, int c) {
	queue[w].r = r;
	queue[w++].c = c;
	while (read < w) {
		pos temp;
		temp.r = queue[read].r;
		temp.c = queue[read++].c;
		visit[temp.r][temp.c] = true;
		for (int i = 0; i < 8; i++) {
			int nr = temp.r + dr[i];
			int nc = temp.c + dc[i];
			if (nr >= 0 && nc >= 0 && nr < N && nc < N && !visit[nr][nc]) {
				if (map[nr][nc] == 0) {
					queue[w].r = nr;
					queue[w++].c = nc;
					visit[nr][nc] = true;
				}
				else if (map[nr][nc] < 10)visit[nr][nc] = true;
			}
	}

	}
	/*pos temp;
	temp.r = queue[read].r;
	temp.c = queue[read++].c;
	if (read > w)return;
	if (visit[temp.r][temp.c] == false) {
		click_num++;
		bfs(temp.r, temp.c);
	}*/
}

int main() {
	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				char c;
				cin >> c;
				if (c == '*') {
					visit[i][j] = true;
					map[i][j] = 10;
					for (int k = 0; k < 8; k++) {
						int nr = i + dr[k];
						int nc = j + dc[k];
						if (nr >= 0 && nc >= 0 && nr < N && nc < N)
						map[nr][nc]++;
					}
				}
			}
		}

		for (int i = 0; i < N; i++) {			//0인 숫자 먼저 체크
			for (int j = 0; j < N; j++) {
				if (map[i][j] == 0 && !visit[i][j]) {
					click_num++;
					bfs(i, j);
				}
			}
		}

			//click_num++;
			//bfs(queue[read].r, queue[read++].c);

			for (int i = 0; i < N; i++) {			//0주위가 아닌 숫자 체크
				for (int j = 0; j < N; j++) {
					if (!visit[i][j])click_num++;
				}
			}

			cout << "#" << test_case << " " << click_num << endl;

			//초기화
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					visit[i][j] = false;
					w = read = 0;
					click_num = 0;
					map[i][j] = 0;

				}
			}
		}
	}