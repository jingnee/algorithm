/*뒤풀이*/
#include <iostream>
using namespace std;

int drink[1001][2];
int N, T, S;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> T;
	for (int i = 0; i < N; i++)cin >> drink[i][0] >> drink[i][1];

	while (S <= 1000000) {
		int minS = 0;
		int maxS = 0;
		bool flag = true;
		for (int i = 0; i < N; i++) {
			if (drink[i][0] <= S) {
				minS += drink[i][0];
				maxS += (drink[i][1] < S) ? drink[i][1] : S;
			}
			else {
				flag = false;
				break;
			}
		}
		if (flag && minS <= T && maxS >= T)break;
		S++;
	}
	
	if (S > 1000000)cout << "-1\n";
	else cout << S << "\n";
}
