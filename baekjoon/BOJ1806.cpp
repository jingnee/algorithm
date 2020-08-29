/*부분합*/
#include<iostream>
using namespace std;

int arr[100001];
int N, S, ans = 100001;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> S;
	for (int i = 0; i < N; i++)cin >> arr[i];

	int sum = 0;
	for (int i = 0, j = 0; i < N; i++) {
		sum += arr[i];
		if (sum >= S) {
			while (j<i && sum>S) {
				sum -= arr[j];
				j++;
			}
			if (sum == S)ans = (ans > i - j + 1) ? i - j + 1 : ans;
			else {
				ans = (ans > i - j + 2) ? i - j + 2 : ans;
			}
		}
	}
	if (ans == 100001)cout << 0;
	else cout << ans;
}
