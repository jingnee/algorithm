//테트리스
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int C, P, answer;
int height[100];

int count_possible(string block) {
	int len = block.size();
	int cnt = 0;
	vector<int> vec;
	for (auto b : block)vec.push_back(b - '0');
	for (int i = 0; i <= C - len; i++) {
		bool flag = true;
		for (int j = 1; j < len; j++) {
			if (vec[j] - vec[j - 1] != height[i + j] - height[i + j - 1]) {
				flag = false;
				break;
			}
		}
		if(flag) cnt++;
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> C >> P;
	for (int i = 0; i < C; i++)cin >> height[i];

	switch (P) {
	case 1:
		answer += count_possible("0");
		answer += count_possible("0000");
		break;
	case 2:
		answer += count_possible("00");
		break;
	case 3:
		answer += count_possible("001");
		answer += count_possible("10");
		break;
	case 4:
		answer += count_possible("100");
		answer += count_possible("01");
		break;
	case 5:
		answer += count_possible("000");
		answer += count_possible("01");
		answer += count_possible("101");
		answer += count_possible("10");
		break;
	case 6:
		answer += count_possible("000");
		answer += count_possible("00");
		answer += count_possible("011");
		answer += count_possible("20");
		break;
	case 7:
		answer += count_possible("000");
		answer += count_possible("02");
		answer += count_possible("110");
		answer += count_possible("00");
		break;
	}
	cout << answer;	
}