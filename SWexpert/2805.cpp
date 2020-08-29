//sw Expert Academy 농작물 수확하기
#include <iostream>
using namespace std;

char map[49][49];
int main() {
	int T,N;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		int answer = 0;
		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
			}
		}
		int k = N / 2;
		for (int i = 0; i <= k; i++) {
			for (int j = k - i; j <= k + i; j++) {
				answer += map[i][j]-'0';
			}
		}
		int num = 0;
		for (int i = k + 1; i < N; i++) {
			num++;
			for (int j = num; j <= N - num - 1; j++) {
				answer += map[i][j]-'0';
			}
		}
		cout << "#" << t << ' ' << answer << endl;
		answer = 0;
	}
}