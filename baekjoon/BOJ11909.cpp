/*배열 탈출*/
#include <iostream>
#include <algorithm>
using namespace std;

int map[2222][2222];
//왼쪽에서 왔을때는 0, 위에서 왔을때는 1
int DP[2222][2222][2];
int N;
int dr[2] = { 0,1 };
int dc[2] = { 1,0 };
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 1; i < N; i++) {
		//맨 윗줄
		if (map[0][i - 1] <= map[0][i]) {
			DP[0][i][0] = DP[0][i - 1][0] + map[0][i] - map[0][i - 1] + 1;
			DP[0][i][1] = DP[0][i - 1][0] + map[0][i] - map[0][i - 1] + 1;
		}
		else {
			DP[0][i][0] = DP[0][i - 1][0];
			DP[0][i][1] = DP[0][i - 1][0];
		}
		//맨 왼쪽줄
		if (map[i - 1][0] <= map[i][0]) {
			DP[i][0][1] = DP[i - 1][0][1] + map[i][0] - map[i - 1][0] + 1;
			DP[i][0][0] = DP[i - 1][0][1] + map[i][0] - map[i - 1][0] + 1;
		}
		else {
			DP[i][0][1] = DP[i - 1][0][1];
			DP[i][0][0] = DP[i - 1][0][1];
		}
	}

	for (int i = 1; i < N; i++) {
		for (int j = 1; j < N; j++) {
			//위에서 내려오는 애랑 비교
			int num = min(DP[i - 1][j][1], DP[i - 1][j][0]);
			if (map[i][j] < map[i - 1][j]) 
				DP[i][j][1] = num;		
			else DP[i][j][1] = num + map[i][j] - map[i - 1][j] + 1;

			//왼쪽에서 오는 애랑 비교
			num = min(DP[i][j - 1][0], DP[i][j - 1][1]);
			if (map[i][j] < map[i][j - 1])DP[i][j][0] = num;
			else DP[i][j][0] =num + map[i][j] - map[i][j - 1] + 1;
		}
	}

	cout << min(DP[N - 1][N - 1][0], DP[N - 1][N - 1][1]) << "\n";
}
