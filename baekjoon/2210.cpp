//숫자판 점프
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

map<int, int> m;
int numbers[5][5];
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };

void DFS(int r, int c, int sum, int cnt) {
	if (cnt == 5) {
		m[sum]++;
		return;
	}

	for (int d = 0; d < 4; d++) {
		int nr = r + dr[d];
		int nc = c + dc[d];
		if (nr >= 0 && nc >= 0 && nr < 5 && nc < 5)
			DFS(nr, nc, sum * 10 + numbers[nr][nc], cnt + 1);
	}
}

int main() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> numbers[i][j];
		}
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			DFS(i, j, numbers[i][j], 0);
		}
	}
	cout << m.size();
}