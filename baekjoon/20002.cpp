//사과나무
#include <iostream>
#include <algorithm>
using namespace std;

int N, ans = -1000;
int map[301][301];
int profit[301][301];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
			profit[i][j] = map[i][j] + profit[i - 1][j] + profit[i][j - 1] - profit[i - 1][j - 1];
			ans = (ans < map[i][j]) ? map[i][j] : ans;
		}
	}

	for (int i = 2; i <= N; i++) {
		for (int j = i; j <= N; j++) {
			for (int k = i; k <= N; k++) {
				int temp = profit[j][k] - profit[j - i][k] - profit[j][k - i] + profit[j - i][k - i];
				ans = (ans < temp) ? temp : ans;
			}
		}
	}
	cout << ans;
}
