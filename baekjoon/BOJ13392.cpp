/*방법을 출력하지 않는 숫자 맞추기*/
//나중에 다시 꼭볼것 생각 안날 듯..
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int N;
int before[10001], after[10001], dp[10001][10];

int main() {

	cin >> N;
	for (int i = 1; i <= N; i++)scanf("%1d", &before[i]);
	for (int i = 1; i <= N; i++)scanf("%1d", &after[i]);
	memset(dp, 50000, sizeof(dp));

	//맨 처음 나사 돌리기
	for (int i = 0; i <= 9; i++)dp[0][i] = i;

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= 9; j++) {
			int lcnt = (after[i] - before[i] - j + 20) % 10;
			int rcnt = 10 - lcnt;
			dp[i][j] = min(dp[i][j], dp[i-1][j] + rcnt);
			dp[i][(j + lcnt) % 10] = min(dp[i][(j + lcnt) % 10], dp[i - 1][j] + lcnt);
		}
	}
	int answer = 100010;
	for (int i = 0; i <= 9; i++)answer = (answer > dp[N][i]) ? dp[N][i] : answer;
	printf("%d\n", answer);
}
