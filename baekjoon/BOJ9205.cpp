/*맥주 마시면서 걸어가기*/
#include <iostream>
#include <math.h>
#include <cstring>
using namespace std;

int T, n;
int conv[103][2];
bool canVisit[103];
bool flag;

void DFS(int x, int y, int num) {
	if (num == n + 1)flag = true;

	for (int i = 1; i <= n + 1; i++) {
		if (abs(x - conv[i][0]) + abs(y - conv[i][1]) <= 1000 && !canVisit[i]) {
			canVisit[i] = true;
			DFS(conv[i][0], conv[i][1], i);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	for (int test_case = 0; test_case < T; test_case++) {
		cin >> n;
		cin >> conv[0][0] >> conv[0][1];
		for (int i = 1; i <= n; i++) {
			cin >> conv[i][0] >> conv[i][1];
		}
		cin >> conv[n+1][0] >> conv[n+1][1];
		
		if (abs(conv[0][0] - conv[n+1][0]) + abs(conv[0][1] - conv[n+1][1]) <= 1000) {
			cout << "happy\n";
			continue;
		}
		
		/*canVisit[0] = true;
		for (int i = 0; i < n + 1; i++) {
			if (!canVisit[i])continue;
			if (flag)break;
			for (int j = 0; j < n + 1; j++) {
				if (canVisit[j] || i==j)continue;
				if (flag)break;
				if (abs(conv[i][0] - conv[j][0]) + abs(conv[i][1] - conv[j][1]) <= 1000) {
					canVisit[j] = true;
					if (flag)break;
					if (abs(conv[j][0] - conv[n + 1][0]) + abs(conv[j][1] - conv[n + 1][1]) <= 1000) {
						cout << "happy\n";
						flag = true;
						break;
					}
				}
			}
		}*/

		//if(!flag)cout << "sad\n";
		canVisit[0] = true;
		DFS(conv[0][0], conv[0][1], 0);
		if (flag) cout << "happy\n";
		else cout << "sad\n";
		
		memset(conv, 0, sizeof(conv));
		memset(canVisit, 0, sizeof(canVisit));
		flag = false;
	}
}
