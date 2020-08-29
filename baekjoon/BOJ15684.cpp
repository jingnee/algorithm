/*
사다리추가
1.
2.
3. 가능한 사다리를 조합으로 구하기
사다리 타는함수, 조합구하는 함수
시간초과 엄청뜸. 아슬아슬하게 통과는했지만 최적화해보기
*/

#include<iostream>
using namespace std;

int N, M, H;
int visit[30][10];
int mmin = 987654321;

bool goDown() {
	bool ans = true;
	for (int i = 0; i < N; i++) {
		int r = 0, c = i;
		while (r < M) {
			if (visit[r][c] == 1)
				c++;
			else if (visit[r][c - 1] == 1)
				c--;
			r++;
		}
		if (c != i) {
			ans = false;
			break;			//break로 시간초과 해결
		}
	}
	return ans;
}

void combi(int index, int cnt) {
	if (cnt >= 4)return;
	if (goDown() == true) {
		/*cout << "======================" << endl;
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N-1; j++) {
				cout << visit[i][j];
			}cout << endl;
		}*/
		mmin = (cnt < mmin) ? cnt : mmin;
		return;
	}

	for (int i = index; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (visit[i][j] != 0) continue; 
			if (j != 0 && visit[i][j - 1] == 1)continue;
				visit[i][j] = 1;
				combi(i, cnt + 1);
				visit[i][j] = 0;
		}
	}
}

int main() {
	cin >> N >> H >> M;
	for (int i = 0; i < H; i++) {
		int r, c;
		cin >> r >> c;
		visit[r - 1][c - 1] = 1;
	}

	if (H == 0) {
		cout << "0" << endl;
		return 0;
	}

	combi(0,0);
	if (mmin == 987654321)mmin = -1;

	cout << mmin << endl;
}