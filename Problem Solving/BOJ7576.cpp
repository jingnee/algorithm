//토마토
/*
1. 1:익은토마토, 0:안익은 토마토, -1: 비어있음
	안익은 토마토는 익은토마토 옆에있으면 익게됨
	상하좌우방향으로 익는다. 모든 토마토가 익는 최소시간
2. 다익을 수 있는경우 최소시간, 못익는 경우 -1
	2<=M,N<=1000
3. BFS이용해서 품
	익은토마토의 위치를 큐에먼저 담고시작
*/

#include<iostream>
#include<queue>
using namespace std;

int map[1000][1000];
struct pos {
	int c, r;
	int time;
};
queue<pos> que;
int N, M, cnt;				//M:가로, N:세로, cnt:안익은 토마토갯수
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };
int BFS() {
	int nc, nr;
	pos temp;

	while (!que.empty()) {
		temp = que.front();
		que.pop();
		for (int i = 0; i < 4; i++) {
			nr = temp.r + dr[i];
			nc = temp.c + dc[i];

			if (nr >= 0 && nc >= 0 && nr < N && nc < M) {
				if (map[nr][nc] == 0) {
					pos insert;
					insert.r = nr;
					insert.c = nc;
					insert.time = temp.time+1;
					que.push(insert);
					map[nr][nc] = 1;
					cnt--;
				}
			}
		}

	}
	return temp.time;
}

int main() {
	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				pos temp;
				temp.r = i;
				temp.c = j;
				temp.time = 0;
				que.push(temp);
			}
			else if (map[i][j] == 0)cnt++;
		}
	}

	//애초에 다 익어있을 경우
	if (cnt == 0)cout << "0" << endl;

	else {
		int answer = BFS();
		if (cnt > 0)cout << "-1" << endl;
		else cout << answer << endl;
	}
	
	return 0;
}