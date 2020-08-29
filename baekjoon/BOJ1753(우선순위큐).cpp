/*최단경로 - (다익스트라 알고리즘 -- 우선순위 큐)*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define MAX 20001
#define INF 987654321
int V, E;
vector<pair<int, int>> graph[MAX];		//gragp[i]에서 갈 수 있는 정점은 first, 가중치는 second

vector<int> dijkstra(int start) {			//start에서 모든 정점의 최단경로를 가지는 벡터를 반환
	vector<int> dist(V+1, INF);					//정점은 1부터 시작
	dist[start] = 0;							//시작점에서 시작점까지의 거리는 0
	//cont, vertex
	priority_queue<pair<int, int>>pq;			//방문할 정점들을 우선순위 큐에 넣음 (우선순위 큐에 있는 순서대로 정점 방문->최소 경로순서)
	pq.push(make_pair(0, start));				//시작점을 먼저 넣고 시작

	while (!pq.empty()) {
		int curVex = pq.top().second;			//curVex : 방문할 정점
		//cost는 curVex까지의 비용
		int cost = -pq.top().first;				//우선순위큐는 가중치가 큰 값이 우선순위이므로 -를 해줌
		pq.pop();

		if (dist[curVex] < cost)continue;

		//curVex에서 연결된 이웃들 모두 확인
		for (int i = 0; i < graph[curVex].size(); i++) {
			int n = graph[curVex][i].first;
			int nd = cost + graph[curVex][i].second;			

			//저장되어있는 n까지의 거리값 > curVex까지의 거리 + curVex에서 n까지 거리 
			//이면 갱신 (최소 경로 발견)
			if (dist[n] > nd) {
				dist[n] = nd;
				pq.push(make_pair(-nd, n));
			}
		}
	}
	return dist;
}

int main() {
	int start_vertex;
	cin >> V >> E >> start_vertex;
	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back(make_pair(b, c));		//a에서 b까지의 간선 가중치는 c이다.
	}

	vector<int> result = dijkstra(start_vertex);

	for (int i = 1; i <= V; i++) {
		if (result[i] == INF)cout << "INF\n";
		else cout << result[i] << '\n';
	}
}