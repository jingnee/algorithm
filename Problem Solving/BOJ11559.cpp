/*Puyo Puyo
1. 뿌요뿌요는 같은 색 뿌요가 4개이상 상하좌우로 연결되면 사라진다.
사라진 다음 공중에 떠있는 뿌요뿌요는 중력에 의해 떨어진다.
뿌요들이 없어진 후 또 4개이상 모이면 터지게 된다.
동시에 뿌요들이 터진다면 하나의 연쇄로 봄
2. 맵은 12*6 .은 빈공간, R은 빨간색, G은 초록색, P는 파란색, Y는 노란색
3. 같은색 뿌요가 4개이상인지 탐색하는 함수 BFS(), 중력으로 아래로 내리는 함수,
전체 맵을 돌면서 visit체크하면서 같은 뿌요가 있는지 탐색*/

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
					/*cout << i << "," << j << "에서 연결된 뿌요 갯수는 ";
					cout << n << "개" << endl;*/
					if (n >= 4) {
						bomb();
						flag = true;
					}
					while (!bom.empty())bom.pop();
				}
			}
		}

		//cout << answer<<"번의 연쇄 끝" << endl;
		//for (int i = 0; i < 12; i++) {
		//	for (int j = 0; j < 6; j++) {
		//		cout << map[i][j];
		//	}cout << endl;
		//}

		down();

	/*	cout << "아래로 내려감" << endl;
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