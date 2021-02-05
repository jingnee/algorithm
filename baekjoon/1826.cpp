//연료 채우기
#include <iostream>
#include <functional>
#include <queue>
using namespace std;

int N, fuel, dist, ans;
priority_queue<pair<int, int>> pq;	//연료 내림차순(연료,거리)
priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq2;		//거리 오름차순(거리,연료)

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	while (N--) {
		int d, f;
		cin >> d >> f;
		//거리 오름차순으로 정렬
		pq2.push(make_pair(d, f));
	}
	cin >> dist >> fuel;
	while (fuel < dist) {
		//현재 연료로 갈 수 있는 거리만 pq에 담아
		while (!pq2.empty() && fuel >= pq2.top().first) {
			int d = pq2.top().first;
			int f = pq2.top().second;
			pq.push(make_pair(f, d));
			pq2.pop();
		}
		//pq에 담은 애가 없으면 그 연료로 갈 수 있는 곳이 없다는 거
		if (pq.empty()) {
			cout << "-1";
			return 0;
		}
		ans++;
		fuel += pq.top().first;
		pq.pop();
	}

	cout << ans;
}