//RGB 거리
#include <iostream>
#include <algorithm>
using namespace std;

int N;
int house[3];
int DP[1001][3];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> house[0] >> house[1] >> house[2];
		if (i == 0) {
			DP[i][0] = house[0];
			DP[i][1] = house[1];
			DP[i][2] = house[2];
		}
		else {
			DP[i][0] = house[0] + min(DP[i - 1][1], DP[i - 1][2]);
			DP[i][1] = house[1] + min(DP[i - 1][0], DP[i - 1][2]);
			DP[i][2] = house[2] + min(DP[i - 1][0], DP[i - 1][1]);
		}
	}
	cout << min(DP[N - 1][0], min(DP[N - 1][1], DP[N - 1][2]));
}
