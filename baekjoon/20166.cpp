//문자열 지옥에 빠진 호석
#include <iostream>
#include <map>
#include <string>
using namespace std;

char alpha[12][12];
int N, M, K, ans;
string str;
int dr[8] = { -1,-1,0,1,1,1,0,-1 };
int dc[8] = { 0,1,1,1,0,-1,-1,-1 };
map<string, int>m;

void DFS(int r, int c, int cnt, int size) {
	if (cnt == size) {
		ans++;
		return;
	}

	for (int d = 0; d < 8; d++) {
		int nr = r + dr[d];
		int nc = c + dc[d];

		if (nr < 0)nr = N - 1;
		else if (nr >= N)nr = 0;

		if (nc < 0)nc = M - 1;
		else if (nc >= M)nc = 0;

		if (alpha[nr][nc] == str[cnt])DFS(nr, nc, cnt + 1, size);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> K;
	for (int i = 0; i < N; i++)cin >> alpha[i];
	for (int i = 0; i < K; i++) {
		cin >> str;
		if (m[str])cout << m[str] << "\n";
		else {
			for (int r = 0; r < N; r++) {
				for (int c = 0; c < M; c++) {
					if (alpha[r][c] == str[0])DFS(r, c, 1, str.size());
				}
			}
			m[str] = ans;
			cout << ans << "\n";
			ans = 0;
		}
	}
}