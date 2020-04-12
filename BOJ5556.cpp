/*타일*/
#include <iostream>
using namespace std;

int N, K, half;
int answer[1000];

int color(int r, int c) {
	int ans;
	if (N%2 == 1 && r > half) {
		int cha = r - half;
		r = half - cha;
	}
	else if (N % 2 == 0 && r > half) {
		int cha = r - half+1;
		r = half - cha;
	}
	//열에따라 먼저 색 설정
	if (r % 3 == 0)ans = 1;
	else if (r % 3 == 1)ans = 2;
	else ans = 3;

	if (c > r - 1 && c < N - r)return ans;
	else {
		if (N%2==1 && c > half) {
			int cha = c - half;
			c = half - cha;
		}
		else if (N%2== 0 && c > half) {
			int cha = c - half+1;
			c = half - cha;
		}
		if (c % 3 == 0)return 1;
		else if (c % 3 == 1)return 2;
		else return 3;
	}

}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;

	half = N / 2;

	for (int i = 0; i < K; i++) {
		int r, c;
		cin >> c >> r;
		c--, r--;
		answer[i] = color(r, c);
	}

	for (int i = 0; i < K; i++)cout << answer[i] << '\n';
}
