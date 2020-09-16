//마인크래프트
#include <iostream>
using namespace std;

int N, M, B;
int map[501][501];
int ans = 1e9 , height;

int howMany(int n) {
	int inventory = B;
	int time = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] > n) {
				inventory += map[i][j] - n;
				time += (map[i][j] - n) * 2;
			}
			else if (map[i][j] < n) {
				inventory -= n - map[i][j];
				time += n - map[i][j];
			}
		}
	}
	if (inventory < 0)return -1;
	else return time;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> B;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 256; i >= 0; i--) {
		int n = howMany(i);
		if (n!=-1 && ans > n) {
			ans = n;
			height = i;
		}
	}

	cout << ans << " " << height;
}
