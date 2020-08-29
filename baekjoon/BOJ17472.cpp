//다리만들기 2
#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#include<algorithm>
using namespace std;

int N, M;
int map[10][10];
int visit[10][10];
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };
int parent[7];
int index = 1;
queue<pair<int, int>> que;
vector<pair<int, pair<int, int>>> bridges;

//kruskal()
int getParent(int x) {
	if (parent[x] == x)return x;
	else return parent[x] = getParent(parent[x]);
}

int Union(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a < b) {
		parent[b] = a;
		return a;
	}
	else {
		parent[a] = b;
		return b;
	}
}

bool Find(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a==b)return true;
	else return false;
}

int kruskal() {
	int distance = 0;
	int connected = 0;
	for (int i = 0; i < bridges.size(); i++) {
		if (!Find(bridges[i].second.first, bridges[i].second.second)) {		//부모가 다르면 연결이 안된거
			distance += bridges[i].first;
			Union(bridges[i].second.first, bridges[i].second.second);
			connected++;
			//cout << bridges[i].second.first << "랑" << bridges[i].second.second << "랑 연결됨 총 길이:" << distance << endl;
		}
	}

	if (connected == index - 2)return distance;
	else return - 1;
}

//bool cmp(pair<pair<int, int>, int> &a, pair<pair<int, int>, int> & b) {
//	return a.second < b.second;
//}

void init() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visit[i][j] = 0;
		}
	}
}
void indexing(int r, int c, int index) {

	while (!que.empty()) {
		pair<int, int> temp = que.front();
		map[temp.first][temp.second] = index;
		//visit[temp.first][temp.second] = 1;
		que.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nr = temp.first + dr[dir];
			int nc = temp.second + dc[dir];
			if (nr >= 0 && nc >= 0 && nr < N && nc < M && map[nr][nc] == 1 && !visit[nr][nc]) {
				visit[nr][nc] = 1;
				que.push(pair<int, int>(nr, nc));
				for (int i = 0; i < 4; i++) {
					int rr = nr + dr[i];
					int cc = nc + dc[i];
					if (rr >= 0 && cc >= 0 && rr < N && cc < M && map[rr][cc] == 0) {
						vector<pair<int,pair<int,int>>> temp;
					}
				}
				//indexing(nr, nc, index);
			}
		}
	}
}

void findBridge(int r, int c) {

	for (int dir = 1; dir < 3; dir++) {
		int nr = r + dr[dir];
		int nc = c + dc[dir];
		int cnt = 0;
		while (nr >= 0 && nc >= 0 && nr < N && nc < M && map[nr][nc] == 0) {
			cnt++;
			nr += dr[dir];
			nc += dc[dir];
		}
		if (cnt >= 2 && nr >= 0 && nc >= 0 && nr < N && nc < M)bridges.push_back(make_pair(cnt,make_pair(map[r][c], map[nr][nc])));
		cnt = 0;
	}
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	//int index = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 1 && !visit[i][j]) {
				que.push(pair<int, int>(i, j));
				visit[i][j] = 1;
				indexing(i, j, index++);
			}
		}
	}
	init();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] > 0 && !visit[i][j]) {
				findBridge(i, j);
			}
		}
	}

	sort(bridges.begin(), bridges.end());

	//확인용
	/*for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << map[i][j];
		}cout << endl;
	}

	cout << "모든 간선 출력:" << endl;
	for (int i = 0; i < bridges.size(); i++) {
		cout << bridges[i].second.first << "섬에서 " << bridges[i].second.second << "섬까지의 거리는 = " << bridges[i].first << "입니다." << endl;
	}*/

	//kruskal 알고리즘 사용하기위해 부모배열 초기화
	for (int i = 1; i < index; i++)parent[i] = i;

	int answer = kruskal();
	cout << answer << endl;


}