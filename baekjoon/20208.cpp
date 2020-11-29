//진우의 민트초코우유
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M, H, answer;
int home[2];
vector<pair<int, int>> mincho;
bool visit[10];
int pick[10];

void simul(int num) {
	int cnt = 0, health = M, r = home[0], c = home[1];
	for (int i = 0; i < num; i++) {
		int to_mincho = (abs)(mincho[pick[i]].first - r) + (abs)(mincho[pick[i]].second - c);
		if (to_mincho <= health) {
			health += H - to_mincho;
			r = mincho[pick[i]].first;
			c = mincho[pick[i]].second;
			cnt++;
		}
		else return;
	}
	int to_home = (abs)(r - home[0]) + (abs)(c - home[1]);
	if (to_home <= health)answer = (answer < cnt) ? cnt : answer;
}

void DFS(int num) {
	if (num > answer)simul(num);

	for (int i = 0; i < mincho.size(); i++) {
		if (!visit[i]) {
			visit[i] = true;
			pick[num] = i;
			DFS(num + 1);
			visit[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> H;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int a;
			cin >> a;
			if (a == 1) {
				home[0] = i;
				home[1] = j;
			}
			else if (a == 2)mincho.push_back(make_pair(i, j));
		}
	}
	DFS(0);
	cout << answer;
}
