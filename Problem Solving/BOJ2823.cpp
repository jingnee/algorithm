//���� �Ⱦ�
#include<iostream>
using namespace std;

int R, C;
char map[11][11];
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };
int main() {
	cin >> R >> C;
	for (int i = 0; i < R; i++)
			cin >> map[i];
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] == '.') {
				int cnt = 0;
				for (int dir = 0; dir < 4; dir++) {
					int nr = i + dr[dir];
					int nc = j + dc[dir];
					if (nr >= 0 && nc >= 0 && nr < R && nc < C && map[nr][nc] == '.')cnt++;		//�ֺ��� ���� ����� ��
				}
				if (cnt < 2) {
					cout << "1" << endl;
					return 0;
				}
			}
		}
	}

	//�̰��� �����ߴٴ°��� �����־��ٴ� ��
	cout << "0" << endl;
	return 0;
}