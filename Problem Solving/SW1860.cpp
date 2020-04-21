/*진기의 최고급 붕어빵*/
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

int N, M, K;
int num[11112];
int bread[11112];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		string answer = "Possible";
		cin >> N >> M >> K;

		for (int i = 0; i < N; i++) {
			cin >> num[i];
		}
		sort(num, num + N);

		bread[0] = 0;
		for (int i = 1; i <= num[N - 1]; i++)bread[i] = i / M*K;

		for (int i = 0; i < N; i++) {
			if (bread[num[i]] - (i + 1) < 0) {
				answer = "Impossible";
				break;
			}
		}
		cout << "#" << test_case << " " << answer << "\n";
		memset(bread, 0, sizeof(bread));
	}
}
