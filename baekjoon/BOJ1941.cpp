/*소문난 칠공주*/
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

char map[5][5];
bool visit[25];
int ans;
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };

//인접한 애들인지 검사
bool find() {
	int cnt = 1;
	bool flag = false;
	bool newMap[5][5];
	queue<pair<int, int>> que;

	memset(newMap, false, sizeof(newMap));
	for (int i = 0; i < 25; i++) {
		if (visit[i]) {
			newMap[i / 5][i % 5] = true;
			if (!flag) {
				que.push(make_pair(i / 5, i % 5));
				flag = true;
			}
		}
	}

	//처음에 넣은 애를 기준으로 주변을 탐색하여 붙어있는애가 몇개인지
	while (!que.empty()) {
		pair<int, int>temp = que.front();
		newMap[temp.first][temp.second] = false;
		que.pop();

		for (int d = 0; d < 4; d++) {
			int nr = temp.first + dr[d];
			int nc = temp.second + dc[d];
			if (nr < 0 || nc < 0 || nr >= 5 || nc >= 5)continue;
			if (newMap[nr][nc]) {
				newMap[nr][nc] = false;
				cnt++;
				que.push(make_pair(nr, nc));
			}
		}
	}
	if (cnt == 7)return true;
	else return false;
}

//25명중 7명 찾는 조합
void combi(int idx, int cnt, int Ynum) {
	//4명 이상 찾았는데 임도연파가 이미 4명 이상이면 더찾아도 소용없음
	if (cnt >= 4 && Ynum >= 4)return;
	if (cnt == 7) {
		if (find()) {
			//for (int i = 0; i < 25; i++)if (visit[i])cout << "[" << i / 5 << "," << i % 5 << "]\t";
			ans++;
			//cout << endl;
		}
	}
	for (int i = idx; i < 25; i++) {
		if (!visit[i]) {
			visit[i] = true;

			if (map[i / 5][i % 5] == 'Y')
				combi(i, cnt + 1, Ynum + 1);
			else combi(i, cnt + 1, Ynum);
			visit[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 5; i++)cin >> map[i];
	combi(0, 0, 0);

	cout << ans << "\n";
}
