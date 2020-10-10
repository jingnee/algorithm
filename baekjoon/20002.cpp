//사과나무 정답X
#include <iostream>
#include <algorithm>
using namespace std;

int N, ans = -1000;
int map[301][301];
int profit[301][301];
int ssize[301][301];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
			int s = ssize[i - 1][j - 1];
			int temp = profit[i - 1][j - 1];
			for (int k = 1; k < s+1; k++) {
				temp += (map[i][j - k] + map[i-k][j]);
			}
			profit[i][j] = max(temp+map[i][j], map[i][j]);
			ssize[i][j] = ssize[i - 1][j - 1] + 1;
			ans = (ans < profit[i][j]) ? profit[i][j] : ans;
		}
	}
	cout << ans;
}
