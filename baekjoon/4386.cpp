//별자리 만들기
#include <iostream>
#include <math.h>
#include <queue>
using namespace std;

int n;
double answer;
priority_queue<pair<double,pair<int,int>>> que;
double stars[1000][2];
int parent[1000];

int getParent(int x) {
	if (parent[x] == x)return x;
	else return parent[x] = getParent(parent[x]);
}

void Union(int a, int b) {
	a = parent[a];
	b = parent[b];
	if (a < b) {
		parent[b] = a;
	}
	else parent[a] = b;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> stars[i][0] >> stars[i][1];
		parent[i] = i;
	}
	
	//별 사이 거리 모두 벡터에 저장
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			double dist = sqrt((stars[j][0] - stars[i][0])*(stars[j][0] - stars[i][0]) + (stars[j][1] - stars[i][1])*(stars[j][1] - stars[i][1]));
			que.push(make_pair(-dist, make_pair(i, j)));
		}
	}

	while (!que.empty()) {
		double dist = -que.top().first;
		int from = que.top().second.first;
		int to = que.top().second.second;
		que.pop();

		//둘이 연결 안된 애들이면
		if (getParent(from) != getParent(to)) {
			Union(from, to);
			answer += dist;
		}
	}
	
	cout << answer;
}
