/*청소년 상어*/
#include <iostream>
#include <algorithm>
using namespace std;

struct pos{
	int r, c, dir;
};

int dr[8] = { -1,-1,0,1,1,1,0,-1 };
int dc[8] = { 0,-1,-1,-1,0,1,1,1, };

int map[4][4];		//각 위치에 어떤 물고기가 있는지
pos fishes[17];
pos shark;
int ans;

//map[r][c]==0 만 검사했더니 다음위치가 상어한테 먹혀서 못바꾸는 위치였을때 위치를 바꿔버려서 번호가 다시 생기는 부분이 생김. 따라서 상어한테 이미 먹힌애들은 방향을 -1로 설정함

void simul(int map[4][4], pos fishes[17], pos shark, int sum) {
	
	ans = max(ans, sum);

	//물고기들 이동
	for (int i = 1; i <= 16; i++) {
		int r = fishes[i].r;
		int c = fishes[i].c;
		int curDir = fishes[i].dir;

		if (curDir == -1)continue;
		if (map[r][c] != 0) {
			for (int d = 0; d < 8; d++) {
				int j = (curDir + d) % 8;
				int nr = r + dr[j];
				int nc = c + dc[j];

				if (nr < 0 || nc < 0 || nr >= 4 || nc >= 4)continue;
				//if (map[nr][nc]==0)continue; 빈칸 갈 수 있음
				if (shark.r == nr && shark.c == nc)continue;

				int nextNum = map[nr][nc];

				if (nextNum != 0) {
					fishes[nextNum].r = r;
					fishes[nextNum].c = c;
					map[r][c] = nextNum;
				}
				else map[r][c] = 0;

				fishes[i] = { nr,nc,j };
				map[nr][nc] = i;

				break;
			}
		}
	}

	//상어가 먹기
	int sr = shark.r;
	int sc = shark.c;
	int sd = shark.dir;

	for (int si = 1; si <= 3; si++) {
		pos newFishes[17];
		for (int j = 1; j < 17; j++) {
			newFishes[j] = fishes[j];
		}
		int newMap[4][4];
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				newMap[j][k] = map[j][k];
			}
		}

		int nr = sr + dr[sd]*si;
		int nc = sc + dc[sd]*si;
		if (nr < 0 || nc < 0 || nr >= 4 || nc >= 4)continue;
		if (newMap[nr][nc] == 0)continue;

		shark.r = nr;
		shark.c = nc;
		int num = newMap[nr][nc];
		newMap[nr][nc] = 0;
		shark.dir = newFishes[num].dir;

		newFishes[num].dir = -1;

		simul(newMap, newFishes, shark, sum + num);
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> a >> b;
			pos temp = { i,j,--b };
			if (i == 0 && j == 0) {
				shark = temp;
				ans += a;
				map[i][j] = 0;
				fishes[a] = { 0,0,-1 };
				continue;
			}
			else {
				map[i][j] = a;
				fishes[a] = temp;
			}
		}
	}
		
	simul(map, fishes, shark, ans);

	cout << ans << "\n";
}
