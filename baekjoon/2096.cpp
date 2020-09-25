//내려가기
#include <iostream>
#include <algorithm>
using namespace std;

int N;
int maxi[3], mini[3];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (i == 0) {
			maxi[0] = mini[0] = a;
			maxi[1] = mini[1] = b;
			maxi[2] = mini[2] = c;
		}
		else {
			int prev_max = max(max(maxi[0], maxi[1]), maxi[2]);
			int prev_min = min(min(mini[0], mini[1]), mini[2]);

			int temp0, temp1, temp2;
			temp0 = max(maxi[0], maxi[1]) + a;
			temp1 = prev_max + b;
			temp2 = max(maxi[1], maxi[2]) + c;

			maxi[0] = temp0;
			maxi[1] = temp1;
			maxi[2] = temp2;

			temp0 = min(mini[0], mini[1]) + a;
			temp1 = prev_min + b;
			temp2 = min(mini[1], mini[2]) + c;

			mini[0] = temp0;
			mini[1] = temp1;
			mini[2] = temp2;
		}
	}

	int max_ans = max(max(maxi[0], maxi[1]), maxi[2]);
	int min_ans = min(min(mini[0], mini[1]), mini[2]);

	cout << max_ans << " " << min_ans;
}
