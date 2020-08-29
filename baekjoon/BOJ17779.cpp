#include <iostream>
#include <algorithm>
using namespace std;

int map[21][21];
int ans = 2e9;
int num;

//x가 세로, y가 가로
int calcPopulation(int x, int y, int d1, int d2) {
	int count[5] = { 0,0,0,0,0 };
	for (int r = 1; r <= num; r++) {
		for (int c = 1; c <= num; c++) {
			if (r < x + d1 && c <= y && !(r >= x && c >= y - (r - x)))count[0] += map[r][c];
			else if (r <= x + d2 && c <= num && !(r >= x && c <= y + (r - x)))count[1] += map[r][c];
			else if (r >= x + d1 && c < y - d1 + d2 && !(r <= x + d1 + d2 && c >= y - d1 + d2 - (x + d1 + d2 - r)))count[2] += map[r][c];
			else if (r > x + d2 && c >= y - d1 + d2 && !(r <= x + d1 + d2 && c <= y - d1 + d2 + (x + d1 + d2 - r)))count[3] += map[r][c];
			else count[4] += map[r][c];
		}
	}
	sort(count, count + 5);
	return count[4] - count[0];
}

void makeDistrict() {
	for (int x = 1; x <= num-2; x++) {
		for (int y = 2; y <= num - 1; y++) {
			for (int d1 = 1; d1 <= y - 1 && d1 <= num - x - 1; d1++) {
				for (int d2 = 1; d2 <= num - y && d2 <= num - x - 1; d2++) {
					ans = min(ans, calcPopulation(x, y, d1, d2));
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> num;
	for (int i = 1; i <= num; i++) {
		for (int j = 1; j <= num; j++) {
			cin >> map[i][j];
		}
	}

	makeDistrict();
	cout << ans << "\n";
}
