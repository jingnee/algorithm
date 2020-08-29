/*미로에 갇힌 건우*/
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int N, M;
int map[501][501];
bool visit[501][501][11][2];
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };

struct walk {
	int r, c, cnt, day;
};

int dayNight(int n) {
	//낮
	if (n % (M * 2) < M)return 0;
	//밤
	else return 1;
}

int BFS() {
	queue<walk> que;
	que.push({ 0,0,0,0 });
	visit[0][0][0][0] = true;

	while (!que.empty()) {

		walk temp = que.front();
		que.pop();
		int r = temp.r;
		int c = temp.c;
		int cnt = temp.cnt;
		int day = temp.day;

		if (r == N - 1 && c == N - 1) return cnt;


		for (int d = 0; d < 4; d++) {
			int nr = r + dr[d];
			int nc = c + dc[d];
			int ncnt = (cnt + 1) % M;
			int nday = dayNight(cnt + 1);
			if (nr < 0 || nc < 0 || nr >= N || nc >= N || visit[nr][nc][ncnt][nday])continue;

			if (map[nr][nc] == 1) {
				if (day == 0) continue;
				while (1) {
					nr += dr[d];
					nc += dc[d];
					if (nr < 0 || nc < 0 || nr >= N || nc >= N || visit[nr][nc][ncnt][nday])break;
					else if (map[nr][nc] != 1) {
						visit[nr][nc][ncnt][nday] = true;
						que.push({ nr,nc,cnt + 1,nday });
						break;
					}
				}
			}
			else {
				visit[nr][nc][ncnt][nday] = true;
				que.push({ nr,nc,cnt + 1,nday });
			}
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	memset(visit, false, sizeof(visit));

	int ans = BFS();
	if (ans == -1) {
		cout << ans << "\n";
		return 0;
	}
	else {
		int num = dayNight(ans);
		int date = ans / (M * 2);
		date++;
		if (num == 0)
			cout << date << " sun\n";
		else
			cout << date << " moon\n";

		return 0;
	}
}
