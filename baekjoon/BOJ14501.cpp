/*퇴사*/
#include <iostream>
#include <algorithm>
using namespace std;

int T[16];
int P[16];
int DP[17];
int N;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++) cin >> T[i] >> P[i];
	for (int i = 1; i <= N; i++) {
		DP[i] = max(DP[i], DP[i - 1]);
		if (i + T[i] > N + 1)continue;
		DP[i + T[i]] = max(DP[i + T[i]], DP[i] + P[i]);
	}
	DP[N+1] = max(DP[N+1], DP[N]);
	cout << DP[N+1] << "\n";
}
