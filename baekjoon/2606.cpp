//바이러스
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int>vec[101];
bool visit[101];
int N,pairNum;
queue<int>que;
int ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> pairNum;
	for (int i = 0; i < pairNum; i++) {
		int a, b;
		cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}

	que.push(1);
	visit[1] = true;

	while (!que.empty()) {
		int q = que.front();
		que.pop();

		for (auto a : vec[q]) {
			if (visit[a])continue;
			visit[a] = true;
			que.push(a);
			ans++;
		}
	}
	cout << ans;
}
