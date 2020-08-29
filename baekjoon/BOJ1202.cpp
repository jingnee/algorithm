/*보석 도둑*/
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N, K;
long long ans;
int bag[300001];
pair<int, int> jew[300001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> jew[i].first >> jew[i].second;
	}
	for (int i = 0; i < K; i++)cin >> bag[i];

	sort(jew, jew + N);
	sort(bag, bag + K);
	priority_queue<int> pq;
	for (int i = 0, j = 0; i < K; i++) {
		while (j < N && jew[j].first <= bag[i]) {
			pq.push(jew[j].second);
			j++;
		}
		if (!pq.empty()) {
			ans += pq.top();
			pq.pop();
		}
	}
	
	cout << ans;
}
