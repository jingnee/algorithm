/* ü��
1. Q,K,P�� ��ġ�� �־������� ������ ��ġ�� ����ã��
2. 1<= n,m <= 1000
3. ��, ����Ʈ ������ ť�� ���, ���� �̵����� �ʱ⶧���� visitüũ�� ����
	ť���� �ϳ��� ������ �̵��� �� �ִ� ĭ true�� �ٲپ��ְ�
�� üũ�� �Ŀ� false���� ���
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
	cin >> q_num;		//�� �Է¹ޱ�
	for (int i = 0; i < q_num; i++) {
		pos temp;
		cin >> temp.r >> temp.c;
		temp.ch = 'q';
		chess.push(temp);
		visit[temp.r][temp.c] = 1;
		map[temp.r][temp.c] = 1;
	}
	cin >> k_num;		//����Ʈ �Է¹ޱ�
	for (int i = 0; i < k_num; i++) {
		pos temp;
		cin >> temp.r >> temp.c;
		temp.ch = 'k';
		chess.push(temp);
		visit[temp.r][temp.c] = 1;
		map[temp.r][temp.c] = 1;
	}
	cin >> p_num;		//�� �Է¹ޱ�
	for (int i = 0; i < p_num; i++) {
		pos temp;
		cin >> temp.r >> temp.c;
		visit[temp.r][temp.c] = 1;
		map[temp.r][temp.c] = 1;
	}

	while (!chess.empty()) {
		pos temp = chess.front();
		chess.pop();
		if (temp.ch == 'q') {		//queen �ϰ��
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
		else if (temp.ch == 'k') {	//knight �ϰ��
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
