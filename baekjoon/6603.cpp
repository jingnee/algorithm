//로또
#include <iostream>
#include <cstring>
using namespace std;

int k;
int S[13];
int ans[13];

void DFS(int idx, int cnt) {
	if (cnt == 6) {
		for (int i = 0; i < 6; i++)cout << ans[i] << " ";
		cout << "\n";
		return;
	}

	for (int i = idx; i < k; i++) {
		ans[cnt] = S[i];
		DFS(i + 1, cnt + 1);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	do {
		cin >> k;
		for (int i = 0; i < k; i++)cin >> S[i];
		memset(ans, 0, sizeof(ans));
		DFS(0, 0);
		cout << "\n";
	} while (k != 0);
}
