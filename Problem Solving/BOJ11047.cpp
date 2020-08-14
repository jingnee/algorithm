/*동전0*/
#include <iostream>
using namespace std;

int N, K, sum;
int prev_coin, next_coin;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> K;
	cin >> prev_coin;
	for (int i = 1; i < N; i++){
		cin >> next_coin;
		if (K%next_coin) {
			sum += (K%next_coin) / prev_coin;
			K -= (K % next_coin);
		}
		prev_coin = next_coin;		
	}
	if (K > 0)sum += K/prev_coin;
	cout << sum << "\n";
}
