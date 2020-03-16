/*부먹왕국의 차원 관문*/
#include <iostream>
using namespace std;
#define MAX 300000

int cities[MAX];
int main() {
	int T, city, dist;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		int answer = 0;
		cin >> city >> dist;
		for (int i = 0; i < city; i++)cin >> cities[i];
		
		int compare = 1;

		for (int i = 0; i < city; i++,compare++) {
			if (dist == compare && cities[i] == 0) {
				answer++;
				cities[i] = 1;
				compare = 0;
			}
			else if (cities[i] == 1) {
				compare = 0;
			}
		}

		cout << "#" << test_case << " " << answer << "\n";
	}
}
