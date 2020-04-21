/*카드 게임*/
#include <iostream>
using namespace std;

int cards[12] = { 0,0,4,4,4,4,4,4,4,4,16,4 };
int N;
int main() {
	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		int sum = 0;
		int dist[12];
		copy(cards, cards + 12, dist);
		cin >> N;
		int n = 0;
		for (int i = 0; i < N; i++) {
			cin >> n;
			dist[n]--;
			sum += n;
		}
		int rest = 21 - sum;
		if (rest >= 11)cout << "#" << test_case << " GAZUA\n";
		else {
			int less = 0, greater = 0;
			for (int i = 0; i <= rest; i++)less += dist[i];
			for (int i = rest + 1; i < 12; i++)greater += dist[i];
			if (less >= greater)cout << "#" << test_case << " GAZUA\n";
			else cout << "#" << test_case << " STOP\n";
		}
	}
}
