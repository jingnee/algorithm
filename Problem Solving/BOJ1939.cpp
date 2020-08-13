/////*중량제한
////그래프처럼 입력받고, 최대중량으로 갱신
////mid를 구하면서 그 길이로 통과할 수 있는지 BFS탐색*/
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int, int>> bridges[100001];
int N, M, C;
int islands[2];
bool visit[100001];

bool BFS(int mid) {
	queue<int> que;
	que.push(islands[0]);
	memset(visit, false, sizeof(visit));
	visit[islands[0]] = true;

	while (!que.empty()) {
		int s = que.front();
		que.pop();
		
		if (s == islands[1])return true;
		for (int i = 0; i < bridges[s].size(); i++) {
			if (!visit[bridges[s][i].first] && bridges[s][i].second >= mid) {
				visit[bridges[s][i].first] = true;
				que.push(bridges[s][i].first);
			}
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		bridges[a].push_back(make_pair(b, c));
		bridges[b].push_back(make_pair(a, c));
		//가능한 최대중량으로 C설정
		C = (C < c) ? c : C;
	}
	cin >> islands[0] >> islands[1];

	int left = 0;
	int right = C;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (BFS(mid))
			left = mid + 1;
		else right = mid - 1;
	}
	cout << right << "\n";
}
