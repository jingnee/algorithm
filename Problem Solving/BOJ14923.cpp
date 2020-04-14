/*미로 탈출*/
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

struct pos{
	int r, c;
	int isUse;
	//int cnt;			원래는 cnt변수를 가졌는데, 변수하나더있다고 메모리초과가 난다. 큐에 엄청난 데이터가 들어가나봐.. 그래서 그냥 answerMap인덱스를 출력
};

//struct compare {
//	bool operator()(pos &a, pos &b) {
//		if (a.cnt > b.cnt)return true;
//		else return false;
//	}
//};

//priority_queue<pos,vector<pos>,compare>que; 굳이 우선순위 큐를 사용할 이유가 없다.
queue<pos>que;
int map[1000][1000];
int answerMap[1000][1000][2];
int startPos[2];
int endPos[2];
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };
int N, M;

int BFS() {
	while (!que.empty()) {
		pos cur = que.front();
		que.pop();

		//마지막점 도달한 경우
		if (cur.r == endPos[0] && cur.c == endPos[1]) {
			return answerMap[cur.r][cur.c][cur.isUse];
		}

		for (int d = 0; d < 4; d++) {
			int nr = cur.r + dr[d];
			int nc = cur.c + dc[d];

			if (nr < 0 || nc < 0 || nr >= N || nc >= M)continue;
			//이미 지팡이 사용했는데 다음위치가 1인경우
			if (cur.isUse && map[nr][nc] == 1)continue;

			//다음위치가 1인경우(지팡이 사용했는데1인경우는 위에서 걸럿으므로 무조건 지팡이 안사용한 상태) -> 여기서 지팡이 사용
			if (map[nr][nc] == 1 && answerMap[nr][nc][1] == -1) {
				que.push({nr,nc,1});
				answerMap[nr][nc][1] = answerMap[cur.r][cur.c][0] + 1;
			}
			//다음 위치가 0인경우는 지팡이를 사용했는지 안했는지 몰라. 그러니 지팡이 사용값에 cur.isUse입력
			else if (map[nr][nc] == 0 && answerMap[nr][nc][cur.isUse] == -1) {
				que.push({ nr,nc,cur.isUse});
				answerMap[nr][nc][cur.isUse] = answerMap[cur.r][cur.c][cur.isUse] + 1;
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
	cin >> startPos[0] >> startPos[1];
	cin >> endPos[0] >> endPos[1];
	startPos[0]--; startPos[1]--; endPos[0]--; endPos[1]--;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	memset(answerMap, -1, sizeof(answerMap));
	que.push({ startPos[0],startPos[1],false});
	answerMap[startPos[0]][startPos[1]][0] = 0;
	answerMap[startPos[0]][startPos[1]][1] = 0;

	cout << BFS() << "\n";
}