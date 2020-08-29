/*N-Queen*/

#include<iostream>
#include<math.h>
using namespace std;

int N, ans;
int board[15];

void DFS(int cnt) {
	bool flag;
	if (cnt == N) {
		ans++;
		return;
	}

	for (int i = 0; i < N; i++) {
		flag = true;
		for (int q = 0; q < cnt; q++) {
			if (board[q] == i || abs(cnt - q) == abs(board[q] - i)) {
				flag = false;
				break;
			}
		}
		if (flag) {
			board[cnt] = i;
			DFS(cnt + 1);
		}
	}

}

int main() {
	cin >> N;
	DFS(0);
	cout << ans << endl;
}