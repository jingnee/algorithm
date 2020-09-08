/*치킨 배달*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M, answer = 2e9;
//int map[51][51];
vector<pair<int, int>> chickens;
vector<pair<int, int>> homes;
pair<int, int> survivalChickens[13];

int countPath() {
	int ans = 0;
	for (int h = 0; h < homes.size(); h++) {
		int minPath = 101;
		for (int c = 0; c < M; c++) {
			int tot = abs(homes[h].first - survivalChickens[c].first) + abs(homes[h].second - survivalChickens[c].second);
			if (minPath > tot)minPath = tot;
		}
		ans += minPath;
	}
	return ans;
}

void chooseChicken(int idx, int cnt) {
	if(cnt == M) {
		int ret = countPath();
		answer = (answer > ret) ? ret : answer;
		return;
	}
	for (int i = idx+1; i < chickens.size(); i++) {
		survivalChickens[cnt] = chickens[i];
		chooseChicken(i, cnt + 1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int a;
			cin >> a;
			if (a == 1)homes.push_back(make_pair(i, j));
			else if (a == 2)chickens.push_back(make_pair(i, j));
		}
	}
	chooseChicken(-1, 0);
	cout << answer;
}
