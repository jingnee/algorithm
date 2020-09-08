/*최대 유량*/
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int N, INF = (1 << 30), total;
int capacity[58][58];
int flow[58][58];
int parent[58];
vector<int> v[58];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		char from, to;
		int cap;
		cin >> from >> to >> cap;
		//같은 경로가 있을 수 있음
		capacity[from - 'A'][to - 'A'] += cap;
		capacity[to - 'A'][from - 'A'] += cap;
		v[from - 'A'].push_back(to - 'A');
		v[to - 'A'].push_back(from - 'A');
	}

	while (1) {
		queue<int>que;
		memset(parent, -1, sizeof(parent));
		que.push(0);
		parent[0] = 0;
		while (!que.empty() && parent[25] == -1) {
			int here = que.front();
			que.pop();
			for (int i = 0; i < v[here].size(); i++) {
				int there = v[here][i];

				if (parent[there] == -1 && capacity[here][there] - flow[here][there] > 0) {
					que.push(there);
					parent[there] = here;
				}
			}
		}

		int amount = INF;
		if (parent[25] == -1)break;
		for (int p = 25; p != 0; p = parent[p]) 
			amount = min(capacity[parent[p]][p] - flow[parent[p]][p], amount);
		for (int p = 25; p != 0; p = parent[p]) {
			flow[parent[p]][p] += amount;
			flow[p][parent[p]] -= amount;
		}
		total += amount;
	}
	cout << total;
}
