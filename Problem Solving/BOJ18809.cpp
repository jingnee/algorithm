/*Gaaaaaaaaaarden*/

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <string.h>
using namespace std;
#define MAX 52

int N, M, G, R, answer, rest;
int map[MAX][MAX];
int mapCount[MAX][MAX];
struct seeds {
	int r, c, color;
};
vector<pair<int, int>> canPlant;
vector<int> cultivation;
queue<seeds> que;
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };

int BFS() {
	int flowerNum = 0;
	while (!que.empty()) {
		seeds temp = que.front();
		que.pop();
		//큐에 있는 자리가 꽃이 되어버렸을 수도 있어
		if (map[temp.r][temp.c] == 5)continue;
		for (int d = 0; d < 4; ++d) {
			int nr = temp.r + dr[d];
			int nc = temp.c + dc[d];
			if (nr<0 || nc<0 || nr>=N || nc>=M)continue;
			int num = map[nr][nc];
			//다음 위치가 호수거나, 꽃이거나, 나랑같은 색이면 탐색안해
			if (num == 0 || num == 5 || num == temp.color)continue;
			//다음 위치가 배양액이 퍼질 수 있는 위치
			if (num == 1 || num == 2) {
				map[nr][nc] = temp.color;
				mapCount[nr][nc] = mapCount[temp.r][temp.c] + 1;
				que.push({ nr, nc, temp.color });
			}
			else {
				if (mapCount[nr][nc] != mapCount[temp.r][temp.c] + 1)continue;
				map[nr][nc] = 5;
				flowerNum++;
			}

		}
	}
	return flowerNum;
}

void combi(int cnt,int restNum, int greenNum, int redNum) {
	if (cnt == canPlant.size()) {
		int copyMap[MAX][MAX];
		memcpy(copyMap, map, sizeof(map));

		memset(mapCount, -1, sizeof(mapCount));

		for (int i = 0; i < cultivation.size(); ++i) {
			if (cultivation[i] != 0) {
				int r = canPlant[i].first;
				int c = canPlant[i].second;
				mapCount[r][c] = 0;
				map[r][c] = cultivation[i];
				que.push({ r, c,cultivation[i] });
			}
		}
		int ans = BFS();
		answer = (answer < ans) ? ans : answer;

		memcpy(map, copyMap, sizeof(map));
		return;
	}

	if (restNum < rest) {
		cultivation.push_back(0);
		combi(cnt + 1, restNum + 1, greenNum, redNum);
		cultivation.pop_back();
	}
	if (greenNum < G) {
		cultivation.push_back(3);
		combi(cnt + 1, restNum, greenNum + 1, redNum);
		cultivation.pop_back();
	}
	if (redNum < R) {
		cultivation.push_back(4);
		combi(cnt + 1, restNum, greenNum, redNum + 1);
		cultivation.pop_back();
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> G >> R;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2)canPlant.push_back(make_pair(i, j));
		}
	}
	rest = canPlant.size() - G - R;
	combi(0,0,0,0);
	cout << answer << "\n";
}

