#include <iostream>
#include <cstring>
using namespace std;

int T, N;
char map[20][20];
int Vnum_garo[20];
int Vnum_sero[20];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;
	while (T--) {
		int answer = 0;
		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
				if (map[i][j] == 'V') {
					Vnum_garo[j]++;
					Vnum_sero[i]++;
				}
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				int num = Vnum_garo[j] + Vnum_sero[i];
				if (map[i][j] == 'V')num--;
				if (num % 2 == 1) {
					answer++;
				}
			}
		}
		cout << answer << "\n";
		memset(map, '\0', sizeof(map));
		memset(Vnum_garo, 0, sizeof(Vnum_garo));
		memset(Vnum_sero, 0, sizeof(Vnum_sero));
	}
}
