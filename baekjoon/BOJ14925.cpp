/*목장 건설하기*/
#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 1010

int map[MAX][MAX];
int DP[MAX][MAX];
int M, N, answer;

int main() {
	cin >> M >> N;

	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0) {
				int temp = 2e9;
				temp = min(temp, DP[i - 1][j]);
				temp = min(temp, DP[i][j - 1]);
				temp = min(temp, DP[i - 1][j - 1]);
				DP[i][j] = temp + 1;
				if (answer < DP[i][j])answer = DP[i][j];
			}
		}
	}

	cout << answer << "\n";
}
