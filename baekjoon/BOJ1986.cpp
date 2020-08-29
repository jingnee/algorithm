/* 체스
1. Q,K,P의 위치가 주어졌을때 안전한 위치의 갯수찾기
2. 1<= n,m <= 1000
3. 퀸, 나이트 순서로 큐에 담고, 폰은 이동하지 않기때문에 visit체크만 해줌
	큐에서 하나씩 꺼내서 이동할 수 있는 칸 true로 바꾸어주고
다 체크한 후에 false갯수 출력
*/

#include<iostream>
#include<queue>
using namespace std;

int visit[1002][1002];
int map[1002][1002];
int n, m;
int q_num, k_num, p_num;
int kr[8] = { -2,-2,-1,1,2,2,1,-1 };
int kc[8] = { -1,1,2,2,1,-1,-2,-2 };
int dr[8] = { -1,0,1,0, -1, 1, 1, -1 };
int dc[8] = { 0,1,0,-1, 1, 1, -1, -1 };
struct pos {
	int r;
	int c;
	char ch;
};
queue <pos> chess;
int main() {
	cin >> n >> m;
	cin >> q_num;		//퀸 입력받기
	for (int i = 0; i < q_num; i++) {
		pos temp;
		cin >> temp.r >> temp.c;
		temp.ch = 'q';
		chess.push(temp);
		visit[temp.r][temp.c] = 1;
		map[temp.r][temp.c] = 1;
	}
	cin >> k_num;		//나이트 입력받기
	for (int i = 0; i < k_num; i++) {
		pos temp;
		cin >> temp.r >> temp.c;
		temp.ch = 'k';
		chess.push(temp);
		visit[temp.r][temp.c] = 1;
		map[temp.r][temp.c] = 1;
	}
	cin >> p_num;		//폰 입력받기
	for (int i = 0; i < p_num; i++) {
		pos temp;
		cin >> temp.r >> temp.c;
		visit[temp.r][temp.c] = 1;
		map[temp.r][temp.c] = 1;
	}

	while (!chess.empty()) {
		pos temp = chess.front();
		chess.pop();
		if (temp.ch == 'q') {		//queen 일경우
			for (int dir = 0; dir < 8; dir++) {
				int nr = temp.r + dr[dir];
				int nc = temp.c + dc[dir];
				while (nr > 0 && nc > 0 && nr <= n && nc <= m && map[nr][nc] == 0) {
					visit[nr][nc] = 1;
					nr += dr[dir];
					nc += dc[dir];
				}
			}

		}
		else if (temp.ch == 'k') {	//knight 일경우
			for (int dir = 0; dir < 8; dir++) {
				int nr = temp.r + kr[dir];
				int nc = temp.c + kc[dir];
				if(nr > 0 && nc > 0 && nr <= n && nc <= m)
				visit[nr][nc] = 1;
				}
			}
		}

	int answer = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (visit[i][j] == 0)answer++;
		}
	}
	cout << answer << endl;
}
