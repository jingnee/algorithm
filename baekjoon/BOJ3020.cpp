/*개똥벌레*/
#include <iostream>
#include <algorithm>
using namespace std;

int N, H, ans=1e9, cnt;
int down[100001];
int up[100001];
int downNum[500001];
int upNum[500001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> H;
	for (int i = 1; i <= N/2; i++) 
		cin >> down[i] >> up[i];

	sort(down, down + (N / 2)+1);
	sort(up, up + (N / 2)+1);
	//높이에 따른 석순갯수 구하기
	for (int i = 1; i <= H; i++) {
		int left = 1;
		int right = N/2;
		while (left <= right) {
			int mid = (left + right) / 2;
			if (down[mid] < i)left = mid + 1;
			else {
				downNum[i] = N/2 - mid + 1;
				right = mid - 1;
			}
		}
	}

	//높이에 따른 종유석 갯수 구하기
	for (int i = 1; i <= H; i++) {
		int left = 1;
		int right = N/2;
		while (left <= right) {
			int mid = (left + right) / 2;
			if (up[mid] <= H-i)left = mid + 1;
			else {
				upNum[i] = N/2 - mid + 1;
				right = mid - 1;
			}
		}
	}

	for (int i = 1; i <= H; i++) {
		if (ans > downNum[i] + upNum[i]) {
			ans = downNum[i] + upNum[i];
			cnt = 1;
		}
		else if (ans == downNum[i] + upNum[i])cnt++;
	}

	cout << ans << " " << cnt << "\n";
}
