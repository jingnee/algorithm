#include <iostream>
#include <queue>
using namespace std;

bool visit[100000];
int N, T, G;

queue<pair<int, int>> que;

int BFS() {

	while (!que.empty()) {
		pair<int, int> temp = que.front();
		que.pop();
		if (temp.second > T)return -1;
		if (temp.first == G)return temp.second;

		//A버튼 눌렀을때
		int num = temp.first + 1;
		if (num <= 99999 && !visit[num]) {
			visit[num] = true;
			que.push(make_pair(num, temp.second + 1));
		}

		//B버튼 눌렀을때
		if (temp.first == 0) {
			if (!visit[0]) {
				visit[0] = true;
				que.push(make_pair(0, temp.second + 1));
			}
			continue;
		}

		num = temp.first * 2;
		if (num > 99999)continue;
		int ten = 1;
		while (num / ten >= 10) ten *= 10;
		num = temp.first * 2 - ten;
		if (num <= 99999 && !visit[num]) {
			visit[num] = true;
			que.push(make_pair(num, temp.second + 1));
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> T >> G;
	que.push(make_pair(N, 0));
	visit[N] = true;

	int ret = BFS();
	if (ret == -1)cout << "ANG\n";
	else cout << ret << "\n";
}
