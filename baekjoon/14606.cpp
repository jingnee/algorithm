//피자 (small)
#include <iostream>
using namespace std;

int N, ans;
int value[11];
int num[11];

void dfs(int n) {
	if (n == 1)return;
	ans += value[n];
	dfs(num[n]);
	dfs(n - num[n]);
}

int main() {
	value[1] = value[2] = 1;
	num[1] = 0;
	num[2] = 1;
	cin >> N;
	if (N == 1) {
		printf("0");
		return 0;
	}
	for (int i = 3; i <= N; i++) {
		for (int j = 1; j <= i / 2; j++) {
			int k = i - j;
			if (value[i] < j*k) {
				value[i] = j*k;
				num[i] = j;
			}
		}
	}
	dfs(N);
	printf("%d",ans);
}
