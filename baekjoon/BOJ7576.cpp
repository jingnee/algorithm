//�丶��
/*
1. 1:�����丶��, 0:������ �丶��, -1: �������
	������ �丶��� �����丶�� ���������� �ͰԵ�
	�����¿�������� �ʹ´�. ��� �丶�䰡 �ʹ� �ּҽð�
2. ������ �� �ִ°�� �ּҽð�, ���ʹ� ��� -1
	2<=M,N<=1000
3. BFS�̿��ؼ� ǰ
	�����丶���� ��ġ�� ť������ ������
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
int N, M, cnt;				//M:����, N:����, cnt:������ �丶�䰹��
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

	//���ʿ� �� �;����� ���
	if (cnt == 0)cout << "0" << endl;

	else {
		int answer = BFS();
		if (cnt > 0)cout << "-1" << endl;
		else cout << answer << endl;
	}
	
	return 0;
}