/*네트워크 복구 아직 해야함*/
#include<iostream>
#include<queue>
using namespace std;
#define INF 987654321

int N, M;
int answer[1001];

int main() {
	cin >> N >> M;
	//graph를 vector<pair<int,int>> graph[MAX]로 밖에 빼놨더니 너무 커져서 런타인 오류뜸
	vector<vector<pair<int, int>>> graph (N+1);			//cost, 연결된 정점

	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back(make_pair(b, c));
		graph[b].push_back(make_pair(a, c));
	}
	for (int i = 1; i <= N; i++)answer[i] = -1;

	vector<int> dist(N + 1, INF);
	priority_queue<pair<int, int>> pq;
	dist[1] = 0;

	pq.push(make_pair(0, 1));
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int vertex = pq.top().second;
		pq.pop();

		for (int i = 0; i < graph[vertex].size(); i++) {
			if (dist[vertex] < cost)continue;


			int n = graph[vertex][i].first;
			int nd = cost + graph[vertex][i].second;

			if (dist[n] > nd) {
				dist[n] = nd;
				pq.push(make_pair(-nd, n));
				answer[n] = vertex;
			}
		}
	}

	int cnt = 0;
	for (int i = 1; i <= N; i++)if (answer[i] != -1)cnt++;
	cout << cnt << endl;
	for (int i = 1; i <= N; i++) {
		if (answer[i] != -1)
		cout << answer[i] <<" "<< i << "\n";
	}
}