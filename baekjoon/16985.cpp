/*Maaaaaaaaaze*/
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int map[5][5][5], map2[5][5][5];
bool visit[5];
bool mapCheck[5][5][5];
int dx[6] = { -1,0,1,0,0,0 };
int dy[6] = { 0,1,0,-1,0,0 };
int dz[6] = { 0,0,0,0,-1,1 };
int answer = 2e9;

//floor층에 있는 큐브를 시계방향으로 돌림
void rotate(int floor) {
	int temp[5][5];
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			temp[j][4-i] = map2[floor][i][j];
		}
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			map2[floor][i][j] = temp[i][j];
		}
	}
}

//경로 찾기
int BFS() {
	queue<pair<int,pair<int,int>>> que;
	int ans = 0;
	que.push(make_pair(0,make_pair(0,0)));
	memset(mapCheck, false, sizeof(mapCheck));
	mapCheck[0][0][0] = true;
	
	while (!que.empty()) {
		int ssize = que.size();
		for (int i = 0; i < ssize; i++) {
			int x = que.front().second.first;
			int y = que.front().second.second;
			int z = que.front().first;
			if (x == 4 && y == 4 && z == 4)return ans;
			que.pop();

			for (int d = 0; d < 6; d++) {
				int nx = x + dx[d];
				int ny = y + dy[d];
				int nz = z + dz[d];
				if (nx < 0 || ny < 0 || nz < 0 || nx >= 5 || ny >= 5 || nz >= 5 || map2[nz][nx][ny] == 0 || mapCheck[nz][nx][ny])continue;
				mapCheck[nz][nx][ny] = true;
				que.push(make_pair(nz, make_pair(nx, ny)));
			}
		}		
		ans++;
	}
	return -1;
}

//첫번째 큐브부터 마지막큐브까지 돌려보기
void simul() {
	int ans = 0;

	for (int i = 0; i < 4; i++) {
		rotate(0);
		for (int j = 0; j < 4; j++) {
			rotate(1);
			for (int k = 0; k < 4; k++) {
				rotate(2);
				for (int l = 0; l < 4; l++) {
					rotate(3);
					for (int p = 0; p < 4; p++) {
						rotate(4);
						if (map2[0][0][0] == 0 || map2[4][4][4] == 0)continue;
						ans = BFS();
						if (ans != -1 && answer > ans)answer = ans;
						if (answer == 12)return;
					}
				}
			}
		}
	}
}

//순열조합으로 큐브쌓을 방법 나열
void combi(int idx, int cnt) {
	if (cnt == 5) {
		simul();
	}
	for (int i = 0; i < 5; i++) {
		if (visit[i])continue;
		visit[i] = true;
		for (int r = 0; r < 5; r++) {
			for (int c = 0; c < 5; c++) {
				map2[idx][r][c] = map[i][r][c];
			}
		}
		combi(idx + 1, cnt + 1);
		visit[i] = false;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 5; k++) {
				cin >> map[i][j][k];
			}
		}
	}

	combi(0, 0);

	if (answer == 2e9)cout << "-1";
	else cout << answer;
}
