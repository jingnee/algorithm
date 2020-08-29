/*수강 과목*/
#include<iostream>
#include <algorithm>
using namespace std;

int N, K, ans;
int DP[10001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;
	while (K--) {
		int a, b;
		cin >> a >> b;
		for (int i = N; i >= b; i--)DP[i] = max(DP[i], DP[i - b] + a);
	}
	
	cout << DP[N] << "\n";
}
