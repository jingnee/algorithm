//°Å½º¸§µ·
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int dp[100001];
int solution(int n, vector<int> money) {
	int answer = 0;
	sort(money.begin(), money.end());
	for (int i = 0; i<money.size(); i++) {
		dp[money[i]]++;
		for (int j = money[i] + 1; j <= n; j++) {
			dp[j] = (dp[j] + dp[j - money[i]]) % 1000000007;
		}
	}
	return dp[n];
}