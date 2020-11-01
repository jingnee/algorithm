//로프
#include <iostream>
#include <algorithm>
using namespace std;

int N, ans;
int lope[100000];

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)cin >> lope[i];
	sort(lope, lope + N);
	for (int i = 0; i < N; i++) {
		ans = (ans < lope[i] * (N - i)) ? lope[i] * (N - i) : ans;
	}
	cout << ans;
}
