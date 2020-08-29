/*특정 거리의 도시 찾기*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define INF 2e9

int N, M, K, X;
vector<int> roads[300001];
bool visit[300001];

void dijkstra(int num) {
	queue<int> que;
	que.push(num);
	visit[num] = true;
	int dist = 0;

	while (!que.empty()) {
		int size = que.size();
		for (int i = 0; i < size; i++) {
			int cur = que.front();
			que.pop();
			for (int j = 0; j < roads[cur].size(); j++) {
				if (visit[roads[cur][j]])continue;
				visit[roads[cur][j]] = true;
				que.push(roads[cur][j]);
			}
		}
		dist++;

		if (dist == K && !que.empty()) {
			vector<int> answer;
			int size = que.size();
			for (int i = 0; i < size; i++) {
				answer.push_back(que.front());
				que.pop();
			}
			sort(answer.begin(), answer.end());
			for (int i = 0; i < answer.size(); i++)cout << answer[i] << "\n";
			return;
		}
		
	}
	cout << "-1\n";
	return;
}

int main() {
	cin >> N >> M >> K >> X;
	for (int i = 0; i < M; i++) {
		int s, e;
		cin >> s >> e;
		roads[s].push_back(e);
	}

	dijkstra(X);

}
