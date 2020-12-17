//공유기 설치
#include <iostream>
#include <algorithm>
using namespace std;

int N, C;
int hub[200001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> C;
	for (int i = 0; i < N; i++)cin >> hub[i];
	sort(hub, hub + N);

	int left = 1;
	int right = hub[N - 1] - hub[0];

	while (left <= right) {
		int mid = (right + left) / 2;
		int cnt = 1;
		int start = hub[0];

		for (int i = 1; i < N; i++) {
			if (hub[i] - start >= mid) {
				start = hub[i];
				cnt++;
			}
		}
		//설치한 공유기 수가 설치할 수 있는 갯수보다 많으면 공유기 수 줄여야 해 -> 간격 넓혀야해
		if (cnt >= C) left = mid + 1;
		else right = mid - 1;
	}
	cout << left-1;
}
