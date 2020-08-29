/*용감한 용사 진수*/
#include <iostream>
using namespace std;

int K, N;
int stats[100][3];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> stats[i][j];
		}
	}

	int ans = 2e9;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				int count = 0;

				for (int l = 0; l < N; l++) {
					if (stats[l][0] <= stats[i][0] && stats[l][1] <= stats[j][1] && stats[l][2] <= stats[k][2])
						count++;
					if (count == K) {
						ans = (ans > stats[i][0] + stats[j][1] + stats[k][2]) ? stats[i][0] + stats[j][1] + stats[k][2] : ans;
						break;
					}
				}
			}
		}
	}

	cout << ans << "\n";
}

/*
힘 최대, 민첩 최대, 지능 최대인 부분을 정해서 그 최대에 맞게 전체를 탐색함
전체를 탐색하면서 K개의 병사를 이기면 최솟값 구해주고
최대치 다시 정해서 또 탐색
O(N^4)*/
