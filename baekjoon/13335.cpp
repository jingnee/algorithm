//트럭
#include <iostream>
using namespace std;

int n, w, L, time = 1, weight;
int trucks[1000];
int now_truck[1000];

int main() {
	cin >> n >> w >> L;
	for (int i = 0; i < n; i++)cin >> trucks[i];

	int s = 0, e = 0;

	while (s < n) {
		//다음 트럭이 올 수 있으면
		if (e < n && weight + trucks[e] <= L && e - s < w) {
			weight += trucks[e];
			e++;
		}
		time++;

		for (int i = s; i < e; i++) {
			now_truck[i]++;
		}
		if (now_truck[s] >= w) {
			weight -= trucks[s];
			s++;
		}
	}
	cout << time;
}
