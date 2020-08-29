/*±Ù¼Õ½Ç*/
#include <iostream>
using namespace std;

int kit[8];
bool visit[8];
int ans[8];
int N, K, answer;

void exercise(int cnt, int sum) {
	if (sum < 500)return;
	if (cnt == N) {
		answer++;
		return;
	}
	for (int i = 0; i < N; i++) {
		if (!visit[i]) {
			visit[i] = true;
			ans[cnt] = i;
			exercise(cnt + 1, sum - K + kit[i]);
			visit[i] = false;
		}
	}
}

int main() {
	cin >> N >> K;
	for (int i = 0; i < N; i++)cin >> kit[i];
	exercise(0, 500);
	cout << answer << "\n";
}