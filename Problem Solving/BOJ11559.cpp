/*Puyo Puyo
1. �ѿ�ѿ�� ���� �� �ѿ䰡 4���̻� �����¿�� ����Ǹ� �������.
����� ���� ���߿� ���ִ� �ѿ�ѿ�� �߷¿� ���� ��������.
�ѿ���� ������ �� �� 4���̻� ���̸� ������ �ȴ�.
���ÿ� �ѿ���� �����ٸ� �ϳ��� ����� ��
2. ���� 12*6 .�� �����, R�� ������, G�� �ʷϻ�, P�� �Ķ���, Y�� �����
3. ������ �ѿ䰡 4���̻����� Ž���ϴ� �Լ� BFS(), �߷����� �Ʒ��� ������ �Լ�,
��ü ���� ���鼭 visitüũ�ϸ鼭 ���� �ѿ䰡 �ִ��� Ž��*/

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

struct Puyo {
	int r, c;
};
queue<Puyo> puyo;
queue<Puyo> bom;
char map[12][7];
int visit[12][7];
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };

int BFS() {
	int colorNum = 1;
	while (!puyo.empty()) {
		Puyo p = puyo.front();
		visit[p.r][p.c] = 1;
		bom.push(p);
		puyo.pop();

		for (int d = 0; d < 4; d++) {
			int nr = p.r + dr[d];
			int nc = p.c + dc[d];
			if (nr >= 0 && nc >= 0 && nr < 12 && nc < 12) {
				if (visit[nr][nc]==0 && map[p.r][p.c] == map[nr][nc]) {
					visit[nr][nc] = 1;
					Puyo temp;
					temp.r = nr;
					temp.c = nc;
					puyo.push(temp);
					bom.push(temp);
					colorNum++;
				}
			}
		}
	}
	return colorNum;
}

void bomb() {
	while (!bom.empty()) {
		Puyo p = bom.front();
		bom.pop();
		map[p.r][p.c] = '.';
	}
}

void down() {
	for (int j = 0; j < 6; j++) {
		for (int i = 11; i >= 0; i--) {
			if (map[i][j] == '.') {
				for (int k = i - 1; k >= 0; k--) {
					if (map[k][j] != '.') {
						map[i][j] = map[k][j];
						map[k][j] = '.';
						i--;
					}
				}
				i = 0;
			}
		}
	}
}

int main() {
	int answer = 0;
	bool flag;
	for (int i = 0; i < 12; i++) 
		cin >> map[i];

	while (1) {
		flag = false;
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				if (map[i][j] != '.' && visit[i][j] == 0) {
					Puyo p;
					p.r = i;
					p.c = j;
					puyo.push(p);
					int n = BFS();
					/*cout << i << "," << j << "���� ����� �ѿ� ������ ";
					cout << n << "��" << endl;*/
					if (n >= 4) {
						bomb();
						flag = true;
					}
					while (!bom.empty())bom.pop();
				}
			}
		}

		//cout << answer<<"���� ���� ��" << endl;
		//for (int i = 0; i < 12; i++) {
		//	for (int j = 0; j < 6; j++) {
		//		cout << map[i][j];
		//	}cout << endl;
		//}

		down();

	/*	cout << "�Ʒ��� ������" << endl;
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				cout << map[i][j];
			}cout << endl;
		}*/

		if (flag)answer++;
		else break;
		memset(visit, 0, sizeof(visit));
	}

	cout << answer << endl;
}