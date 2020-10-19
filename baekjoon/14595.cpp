//동방 프로젝트(Large)
#include <iostream>
using namespace std;

int room[1000001];
int N, M;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		room[a]++;
		room[b]--;
	}

	int sum = 0;
	int ans = N;
	for (int i = 1; i <= N; i++) {
		sum += room[i];
		if (sum)ans--;
	}
	cout << ans;
}
