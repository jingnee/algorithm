/*숫자 정사각형*/
#include <iostream>
using namespace std;

int map[50][50];
int N, M;
int main() {
	cin >> N >> M;
	int length = (N > M) ? M : N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &map[i][j]);
		}
	}

	while (--length >= 0) {
		for (int i = 0; i < N - length; i++) {
			for (int j = 0; j < M - length; j++) {
				if ((map[i][j] == map[i][j + length]) && (map[i][j] == map[i + length][j + length]) && (map[i][j] == map[i+length][j])) {
					cout << (length+1) * (length+1) << "\n";
					return 0;
				}
			}
		}
	}
}
