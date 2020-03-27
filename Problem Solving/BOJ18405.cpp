/*경쟁적 전염
priority Que를 이용한 BFS*/
#include <iostream>
#include <queue>
using namespace std;

struct pos {
	int r, c, num;
};

struct compare {
	bool operator()(pos a, pos b) {
		return a.num > b.num;
	}
};

priority_queue<pos, vector<pos>, compare > que;
int map[200][200];
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };
int N, K, S, X, Y;

void BFS(int S) {
	if (S == 0)return;
	priority_queue<pos, vector<pos>, compare> newQue;
	while (!que.empty()) {
		pos first = que.top();
		que.pop();

		for (int d = 0; d < 4; d++) {
			int nr = first.r + dr[d];
			int nc = first.c + dc[d];
			if (nr < 0 || nc < 0 || nr >= N || nc >= N)continue;
			if (map[nr][nc] == 0) {
				map[nr][nc] = first.num;
				newQue.push({ nr,nc,map[nr][nc] });
			}
		}
	}
	while (!newQue.empty()) {
		que.push(newQue.top());
		newQue.pop();
	}
	BFS(S - 1);
}

int main() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] != 0)que.push({ i,j,map[i][j] });
		}
	}
	cin >> S >> X >> Y;
	X--;
	Y--;
	BFS(S);

	cout << map[X][Y] << "\n";
}