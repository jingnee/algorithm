/*캐슬 티펜스*/
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <math.h>
using namespace std;

int N, M, D;
int map[15][15];
int archer[3];
vector<pair<int, int>> enemy;
int answer = 0;

int game() {
	//모든 적과 거리 계산
	int archer_r = N;
	int cnt = 0;
	//적 좌표 옮기기
	vector<pair<int, int>> vec;
	for (auto v : enemy) {
		vec.push_back(v);
	}

	//archer_r은 궁수위치
	while (archer_r >= 0) {
		set<int> removedEnemy;

		//모든 궁수에 대해서 계산
		for (int a = 0; a < 3; a++) {
			int enNum = 400;
			int dist = 2e9;
			int minc = 15;
			for (int v = 0; v < vec.size(); v++) {
				if (vec[v].first >= archer_r || vec[v].first == -1)continue;
				int archerToenemy = archer_r - vec[v].first + abs(archer[a] - vec[v].second);
				if (archerToenemy > D)continue;
				if (archerToenemy <= dist) {
					if (archerToenemy == dist && minc < vec[v].second) continue;
					dist = archerToenemy;
					minc = vec[v].second;
					enNum = v;
				}
			}
			if (enNum != 400)
			removedEnemy.insert(enNum);
			//vec[enNum].first = -1;
		}
		archer_r--;
		for (auto s : removedEnemy) {
			vec[s].first = -1;
			cnt++;
		}
	}
	return cnt;
}

void solve(int cnt, int idx) {
	if (cnt == 3) {
		int num = game();
		if (answer < num)answer = num;
		return;
	}
	for (int i = idx; i < M; i++) {
		archer[cnt] = i;
		solve(cnt + 1, i+1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> D;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			//적 좌표 받아놓기
			if (map[i][j])enemy.push_back(make_pair(i, j));
		}
	}

	solve(0, 0);
	cout << answer << "\n";
}
