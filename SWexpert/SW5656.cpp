/*벽돌 깨기*/
#include<iostream>
using namespace std;

int brick[15][12];
int map[15][12];
int W, H, N, answer, flag;
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };
int num[12];

void Bomb(int r, int c) {				//[r][c]위치에서 벽돌 부시는 함수
	if (!brick[r][c])return;
	if (brick[r][c] == 1) {
		brick[r][c] = 0;
		return;
	}
	int num = brick[r][c];
	brick[r][c] = 0;

	for (int i = 1; i < num; i++) {
		for (int d = 0; d < 4; d++) {
			int nr = r + dr[d] * i;
			int nc = c + dc[d] * i;
			if (nr < 0 || nc < 0 || nr >= H || nc >= W || brick[nr][nc]==0)continue;
			Bomb(nr, nc);
		}
	}
}

void down() {							//공중에 떠있는 벽돌 내리는 함수
	for (int j = 0; j < W; j++) {
		for (int i = H-1; i >= 1; i--) {
				for (int k = i - 1; k >= 0; k--) {
					if (brick[i][j] != 0)break;
					if (brick[k][j] != 0) {
						brick[i][j] = brick[k][j];
						brick[k][j] = 0;
						break;
					}
			}
		}
	}
}

void copy() {
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			brick[i][j] = map[i][j];
		}
	}
}
int findRow(int c) {
	if (brick[H - 1][c] == 0)return H-1;
	else {
		for (int i = 0; i < H; i++) {
			if (brick[i][c] != 0)return i;
		}
	}
}
int countBrick() {
	int cnt = 0;
	for (int j = 0; j < W; j++) {
		for (int i = H - 1; i >= 0; i--) {
			if (brick[i][j] != 0)cnt++;
		}
	}
	return cnt;
}

void combi(int cnt) {
	if (flag)return;
	if (cnt == N) {
		//맵 복사하고
		copy();
		//num[cnt]열에 있는 행위치찾아서 벽돌부시고
		for (int n = 0; n < N; n++) {
			int row = findRow(num[n]);
			
				Bomb(row, num[n]);
				down();
			
		}
		int ans = countBrick();
		answer = (answer > ans) ? ans : answer;
		if(answer==0)flag = 1;
		return;
	}

	for (int i = 0; i < W; i++) {
		num[cnt] = i;
		combi(cnt + 1);
	}
}

int main() {
	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		cin >> N >> W >> H;
		answer = 2e9;
		flag = 0;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				cin >> map[i][j];
			}
		}

		combi(0);
		
		cout << "#" << test_case << " " << answer << "\n";
	}
}