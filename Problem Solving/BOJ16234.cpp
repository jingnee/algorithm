/*인구 이동
1. 각 국가의 인구가 L이상 R이하 인경우 국경을 개방하고 인구수를 재설정 -> 국경개방된 인구들 / 국경개방된 국가 수
2. 1<= N <= 50 ,1<=L,R <= 100, 인구 이동의 수는 2000 이하 => 최대 시간 50*50*2000 = 200000
3. 각 국가에서 개방되었는지를 DFS탐색하면서 vector에 위치를 넣어주고, 인구도 더해줌 */

#include<iostream>
#include<vector>
#include<math.h>
#include<cstring>			//memset header
using namespace std;
#define MAX 50

int N, L, R;
int people, ans, num;
int map[MAX][MAX];
int visit[MAX][MAX];
vector<pair<int, int>> country;
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };

void DFS(int r, int c) {				//[r][c]에서 연결된(개방된)국가 찾기
	for (int d = 0; d < 4; d++) {
		int nr = r + dr[d];
		int nc = c + dc[d];
		if (nr >= 0 && nc >= 0 && nr < N && nc < N) {
			int cha = abs(map[r][c] - map[nr][nc]);
			if (visit[nr][nc] != 1 && cha >= L && cha <= R) {
				visit[nr][nc] = 1;
				people += map[nr][nc];
				num++;
				country.push_back(make_pair(nr, nc));
				DFS(nr, nc);
			}
		}
	}
}

int main() {
	cin >> N >> L >> R;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	while (1) {
		bool flag = false;
		memset(visit, 0,sizeof(visit));

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (visit[i][j])continue;
				num = 0;
				country.clear();
				country.push_back(make_pair(i, j));
				people = map[i][j];
				visit[i][j] = 1;
				DFS(i, j);			//[i][j]에서 오픈된 국가가 있는지 검사하고 있으면 country에 넣고, num++

				if (num) {
					int share = people / country.size();
					flag = true;
					for (int i = 0; i < country.size(); i++) {
						int r = country[i].first;
						int c = country[i].second;
						map[r][c] = share;
					}
				}
				
			}
		}
		if (flag)ans++;
		else break;
	}

	cout << ans << endl;
}