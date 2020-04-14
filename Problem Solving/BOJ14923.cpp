/*�̷� Ż��*/
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

struct pos{
	int r, c;
	int isUse;
	//int cnt;			������ cnt������ �����µ�, �����ϳ����ִٰ� �޸��ʰ��� ����. ť�� ��û�� �����Ͱ� ������.. �׷��� �׳� answerMap�ε����� ���
};

//struct compare {
//	bool operator()(pos &a, pos &b) {
//		if (a.cnt > b.cnt)return true;
//		else return false;
//	}
//};

//priority_queue<pos,vector<pos>,compare>que; ���� �켱���� ť�� ����� ������ ����.
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

		//�������� ������ ���
		if (cur.r == endPos[0] && cur.c == endPos[1]) {
			return answerMap[cur.r][cur.c][cur.isUse];
		}

		for (int d = 0; d < 4; d++) {
			int nr = cur.r + dr[d];
			int nc = cur.c + dc[d];

			if (nr < 0 || nc < 0 || nr >= N || nc >= M)continue;
			//�̹� ������ ����ߴµ� ������ġ�� 1�ΰ��
			if (cur.isUse && map[nr][nc] == 1)continue;

			//������ġ�� 1�ΰ��(������ ����ߴµ�1�ΰ��� ������ �ɷ����Ƿ� ������ ������ �Ȼ���� ����) -> ���⼭ ������ ���
			if (map[nr][nc] == 1 && answerMap[nr][nc][1] == -1) {
				que.push({nr,nc,1});
				answerMap[nr][nc][1] = answerMap[cur.r][cur.c][0] + 1;
			}
			//���� ��ġ�� 0�ΰ��� �����̸� ����ߴ��� ���ߴ��� ����. �׷��� ������ ��밪�� cur.isUse�Է�
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