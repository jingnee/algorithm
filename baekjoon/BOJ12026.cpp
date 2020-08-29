/*BOJ거리*/
#include <iostream>
#include <cstring>
using namespace std;

char street[1001];
int ans[1001];
int N;

char next(int ch) {
	if (ch == 'B')return 'O';
	else if (ch == 'O')return 'J';
	else return 'B';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) cin >> street[i];

	//이부분이 문제였던거 같다.
	/*int idx = 1;
	while (idx < N && street[idx] != 'O')ans[idx++] = -1;*/
	memset(ans, -1, sizeof(ans));
	ans[0] = 0;

	for (int i = 0; i < N-1; i++) {
		char ch = street[i];
		char next_ch = next(ch);
		//어차피 처음에 갈 수 있는곳을 미리 해놨기 때문에 -1을 만나면 못가는곳이 맞음
		if (ans[i] == -1)continue;

		for (int j = i + 1; j < N; j++) {
			if (street[j] == next_ch) {
				int num = ans[i] + (j - i)*(j - i);
				if (ans[j] == -1 || ans[j] > num)ans[j] = num;
			}

		}
	}

	if (ans[N - 1] == 0 || ans[N - 1] == -1)cout << "-1\n";
	else cout << ans[N - 1] << "\n";
}
