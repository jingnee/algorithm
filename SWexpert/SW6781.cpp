/*삼삼 트리플게임*/
#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <cstring>
using namespace std;

int cards[3][10];

int main() {
	int T = 0;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		string numbers;
		string colors;
		cin >> numbers >> colors;
		for (int i = 0; i < 9; i++) {
			if (colors[i] == 'R')cards[0][numbers[i] - '0']++;
			else if (colors[i] == 'G')cards[1][numbers[i] - '0']++;
			else cards[2][numbers[i] - '0']++;
		}

		int set = 0;
		for (int color = 0; color < 3; color++) {
			//연속된 수
			for (int i = 1; i <= 7; i++) {
				if (cards[color][i] > 0 && cards[color][i + 1] > 0 && cards[color][i + 2] > 0) {
					set++;
					cards[color][i]--;
					cards[color][i + 1]--;
					cards[color][i + 2]--;
					i--;
				}
			}
			//같은 수
			for (int i = 1; i <= 9; i++) {
				if (cards[color][i] >= 3) {
					cards[color][i] -= 3;
					set++;
					i--;
				}
			}
		}

		if (set >= 3)cout << "#" << test_case << " Win\n";
		else cout << "#" << test_case << " Continue\n";
		set = 0;
		memset(cards, 0, sizeof(cards));
	}
}
