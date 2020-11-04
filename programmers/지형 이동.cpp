#include <string>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int map[300][300];
int parent[90001];
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };

int getParent(int x) {
	if (parent[x] == x)return x;
	else return parent[x] = getParent(parent[x]);
}

void Union(int a, int b) {
	a = getParent(a);
	b = getParent(b);

	if (a < b) parent[b] = a;
	else parent[a] = b;
}

int numbering(vector<vector<int>> land, int height) {
	int N = land.size();
	int num = 1;
	queue<pair<int,int>> que;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 0) {
				que.push(make_pair(i, j));
				map[i][j] = num;

				while (!que.empty()) {
					int r = que.front().first;
					int c = que.front().second;
					que.pop();

					for (int d = 0; d < 4; d++) {
						int nr = r + dr[d];
						int nc = c + dc[d];
						if (nr < 0 || nc < 0 || nr >= N || nc >= N || map[nr][nc] != 0 || abs(land[nr][nc] - land[r][c])>height)continue;
						que.push(make_pair(nr, nc));
						map[nr][nc] = num;
					}
				}
				num++;
			}
		}
	}
	return num - 1;
}

int solution(vector<vector<int>> land, int height) {
	int answer = 0;
	//넘버링
	int num = numbering(land, height);
	vector<pair<int, pair<int, int>>> vec;

	for (int i = 1; i <= num; i++)parent[i] = i;

	//모든 사다리 갯수 담기
	int N = land.size();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int d = 1; d <= 2; d++) {
				int nr = i + dr[d];
				int nc = j + dc[d];
				if (nr >= N || nc >= N || map[nr][nc] == map[i][j])continue;
				vec.push_back(make_pair(abs(land[nr][nc] - land[i][j]), make_pair(map[i][j], map[nr][nc])));
			}
		}
	}

	sort(vec.begin(), vec.end());
	int connected = 0;

	for (auto v : vec) {
		int p1 = getParent(v.second.first);
		int p2 = getParent(v.second.second);
		//아직 연결 안되었으면
		if (p1 != p2) {
			answer += v.first;
			Union(p1, p2);
			connected++;
		}
		if (connected == num - 1) break;
	}

	return answer;
}
