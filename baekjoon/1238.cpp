//파티
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

int dist[1001];
int ans[1001];

int N, M, X;
vector<pair<int, int>> vec[1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> X;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		vec[a].push_back(make_pair(b, c));
	}

	for (int i = 1; i <= N; i++) {
		memset(dist, 0x7f, sizeof(dist));
		dist[i] = 0;
		queue<pair<int, int>>que;
		que.push(make_pair(i, 0));

		while (!que.empty()) {
			int src = que.front().first;
			int d = que.front().second;
			que.pop();
			for (int j = 0; j < vec[src].size(); j++) {
				int next = vec[src][j].first;
				int cost = vec[src][j].second;
				if (dist[next] > cost + d) {
					dist[next] = cost + d;
					que.push(make_pair(next, dist[next]));
				}
			}
		}
		ans[i] = dist[X];
	}

	memset(dist, 0x7f, sizeof(dist));
	dist[X] = 0;
	queue<pair<int, int>>que;
	que.push(make_pair(X, 0));

	while (!que.empty()) {
		int src = que.front().first;
		int d = que.front().second;
		que.pop();
		for (int j = 0; j < vec[src].size(); j++) {
			int next = vec[src][j].first;
			int cost = vec[src][j].second;
			if (dist[next] > cost + d) {
				dist[next] = cost + d;
				que.push(make_pair(next, dist[next]));
			}
		}
	}

	int answer = 0;
	for (int i = 1; i <= N; i++) {
		ans[i] += dist[i];
		if (answer < ans[i])answer = ans[i];
	}

	cout << answer;
}
