/*
[����] �׸�׸� �÷°˻�
1. ������(0), �Ʒ���(1), ����(2), ����(3) ������ Ž��
2. #�� ��Ÿ�������� �ֺ� #�� ������ üũ-->BFS()
	�ֺ� #�� ������ 1���̸� �� ������ ����
	���� ���� �̵��ؾ��� ��Ұ� .�̰ų� ������ ����� ������ �ٲپ���
--------------------------------------------------------------------------
	�̵��� �ð����
	���������� �̵��߿� ������������ ������ �ո���
	�Ʒ������� �̵��߿� ������ ������ �������� �ո���
	�������� �̵��߿� ������ ������ �Ʒ����� �ո���
	�������� �̵��߿� ������ ������ ������ �ո���
*/

#include<iostream>
#include<string>
using namespace std;

char map[101][101];
string direction[4] = { "UP", "RIGHT", "DOWN", "LEFT" };
int dr[4] = { 0,1,0,-1 };
int dc[4] = { 1,0,-1,0 };
int N, M;

void BFS(int r, int c, int d) {
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];
		if (map[nr][nc] == '#')cnt++;
	}
	if (cnt >= 2) {
		int nr = r + dr[d];
		int nc = c + dc[d];
		if (nr >= 0 && nc >= 0 && nr < N && nc < M && map[nr][nc] == '#')BFS(nr, nc, d);
		else {
			int nr = r + dr[d + 1];
			int nc = c + dc[d + 1];
			BFS(nr, nc, d + 1);
		}
	}
	else if (cnt == 1) {
		cout << direction[d];
		return;
	}
}
int main() {
	cin >> N >> M;
	int sr, sc, flag = 0;				//sr,sc�� ������� �����ִ� #
	for (int i = 0; i < N; i++)cin >> map[i];

	for (int i = 0; i < N; i++) {
		if (flag == 1)break;
		for (int j = 0; j < M; j++) {
			if (map[i][j] == '#') {
				sr = i;
				sc = j;
				flag = 1;
				break;
			}
		}
	}
	BFS(sr, sc, 0);
	return 0;
}