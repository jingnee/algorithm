/*이동하기*/
#include <iostream>
using namespace std;

int N, M;
int map[1001][1001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
			if (i > 1) {
				int max = map[i - 1][j];
				if (j > 1) {
					int max2 = 0;
					max2 = (map[i][j - 1] < map[i - 1][j - 1]) ? map[i - 1][j - 1] : map[i][j - 1];
					max = (max < max2) ? max2 : max;
				}
				map[i][j] += max;
			}
			else if (j > 1) {
				int max = map[i][j-1];
				if (i > 1) {
					int max2 = 0;
					max2 = (map[i - 1][j] < map[i - 1][j - 1]) ? map[i - 1][j - 1] : map[i - 1][j];
					max = (max < max2) ? max2 : max;
				}
				map[i][j] += max;
			}
		}
	}

	cout << map[N][M] << "\n";
}
