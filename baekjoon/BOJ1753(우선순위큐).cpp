/*�ִܰ�� - (���ͽ�Ʈ�� �˰��� -- �켱���� ť)*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define MAX 20001
#define INF 987654321
int V, E;
vector<pair<int, int>> graph[MAX];		//gragp[i]���� �� �� �ִ� ������ first, ����ġ�� second

vector<int> dijkstra(int start) {			//start���� ��� ������ �ִܰ�θ� ������ ���͸� ��ȯ
	vector<int> dist(V+1, INF);					//������ 1���� ����
	dist[start] = 0;							//���������� ������������ �Ÿ��� 0
	//cont, vertex
	priority_queue<pair<int, int>>pq;			//�湮�� �������� �켱���� ť�� ���� (�켱���� ť�� �ִ� ������� ���� �湮->�ּ� ��μ���)
	pq.push(make_pair(0, start));				//�������� ���� �ְ� ����

	while (!pq.empty()) {
		int curVex = pq.top().second;			//curVex : �湮�� ����
		//cost�� curVex������ ���
		int cost = -pq.top().first;				//�켱����ť�� ����ġ�� ū ���� �켱�����̹Ƿ� -�� ����
		pq.pop();

		if (dist[curVex] < cost)continue;

		//curVex���� ����� �̿��� ��� Ȯ��
		for (int i = 0; i < graph[curVex].size(); i++) {
			int n = graph[curVex][i].first;
			int nd = cost + graph[curVex][i].second;			

			//����Ǿ��ִ� n������ �Ÿ��� > curVex������ �Ÿ� + curVex���� n���� �Ÿ� 
			//�̸� ���� (�ּ� ��� �߰�)
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
		graph[a].push_back(make_pair(b, c));		//a���� b������ ���� ����ġ�� c�̴�.
	}

	vector<int> result = dijkstra(start_vertex);

	for (int i = 1; i <= V; i++) {
		if (result[i] == INF)cout << "INF\n";
		else cout << result[i] << '\n';
	}
}