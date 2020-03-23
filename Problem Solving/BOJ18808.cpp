/*스티커 붙이기*/
#include <iostream>
#include <cstring>
using namespace std;

int N, M, K;
int Notebook[40][40];
int sticker[40][40];

int putSticker(int n, int m, int i, int j) {
	for (int ii = 0; ii < n; ii++) {
		for (int jj = 0; jj < m; jj++) {
			if (sticker[ii][jj] == 1 && Notebook[ii + i][jj + j] != 0)return -1;
		}
	}
	return 1;
}

void rotate(int n, int m) {
	int newSticker[40][40];
	memset(newSticker, 0, sizeof(newSticker));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			newSticker[j][n - i - 1] = sticker[i][j];
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			sticker[i][j] = newSticker[i][j];
		}
	}
}

void findSticker(int n, int m) {
	//스티커 위치 선정
	int rot = 4;
	while (rot--) {
		for (int i = 0; i < N - n+1; i++) {
			for (int j = 0; j < M - m+1; j++) {
				//스티커붙이기

				int ret = putSticker(n, m, i, j);
				if (ret == 1) {
					for (int ii = 0; ii < n; ii++) {
						for (int jj = 0; jj < m; jj++) {
							if(sticker[ii][jj]==1)
							Notebook[i + ii][j + jj] = sticker[ii][jj];
						}
					}
					return;
				}
				
			}
		}
		rotate(n, m);
		int temp = n;
		n = m;
		m = temp;
	}
}

int check() {
	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (Notebook[i][j] == 1)ans++;
		}
	}
	return ans;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K;
	for (int i = 0; i < K; i++) {
		int n, m;
		cin >> n >> m;
		memset(sticker, 0, sizeof(sticker));
		for (int ni = 0; ni < n; ni++) {
			for (int mj = 0; mj < m; mj++) {
				cin >> sticker[ni][mj];
			}
		}
		findSticker(n, m);
	}
	cout << check() << endl;
}