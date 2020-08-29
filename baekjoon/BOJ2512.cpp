/*예산*/
#include <iostream>
using namespace std;

int N, M, ans;
int money[10001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int left = 0;
	int right = 0;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> money[i];
		right = (right < money[i]) ? money[i] : right;
	}
	cin >> M;

	while (left <= right) {
		int tot = 0;
		int mid = (left + right) / 2;
		for (int i = 0; i < N; i++) {
			if (mid <= money[i])tot += mid;
			else tot += money[i];
		}
		if (tot > M)right = mid - 1;
		else {
			left = mid + 1;
			ans = (ans < mid) ? mid : ans;
		}
	}
	cout << ans << "\n";
}
