/*수들의 합2*/
#include <iostream>
using namespace std;

int arr[10001];
int N, M, ans, leftNum, sum;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	/*for (int i = 0; i < N; i++)cin >> arr[i];

	for (int i = 0; i < N; i++) {
		int sum = 0;
		for (int j = i; j < N; j++) {
			sum += arr[j];
			if (sum >= M) {
				if (sum == M)ans++;
				break;
			}
		}
	}*/
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		sum += arr[i];
		while (sum > M)sum -= arr[leftNum++];
		ans += sum == M;
	}
	cout << ans << "\n";
}
