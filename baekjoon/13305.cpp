//¡÷¿Øº“
#include <iostream>
using namespace std;

int N;
long long ans;
int city[100000];
int cur_road;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;

	for (int i = 0; i < N - 1; i++)cin >> city[i];
	for (int i = 0; i < N - 1; i++) {
		int next_road;
		cin >> next_road;
		if (i == 0 || cur_road > next_road)ans += 1LL*next_road*city[i];
		else ans += 1LL * cur_road*city[i];

		if (i == 0 || cur_road > next_road)cur_road = next_road;
	}
	cin >> cur_road;

	cout << ans;
}