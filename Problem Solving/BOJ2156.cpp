/*포도주 시식*/
#include <iostream>
#include <algorithm>
using namespace std;

int n;
int grapes[10001];
int DP[10001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)cin >> grapes[i];
	DP[0] = grapes[0];
	DP[1] = grapes[0] + grapes[1];
	DP[2] = max(max(grapes[0] + grapes[2], grapes[1]+grapes[2]), DP[1]);

	for (int i = 3; i < n; i++) {
		DP[i] = max(max(DP[i - 1], DP[i - 2] + grapes[i]), DP[i - 3] + grapes[i - 1] + grapes[i]);
	}
	cout << DP[n - 1] << "\n";
}
