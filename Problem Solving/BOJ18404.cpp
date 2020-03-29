/*현명한 나이트*/
#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

char chess[500][500];
int countedMap[500][500];
vector<pair<int, int>> enemy;
queue<pair<pair<int, int>,int>> knight;
int dr[8] = { -2,-2,-1,-1,1,1,2,2 };
int dc[8] = { -1,1,-2,2,-2,2,-1,1 };
int N, M;

int main() {
	cin >> N >> M;
	int x, y;
	cin >> x >> y;
	knight.push(make_pair(make_pair(--x, --y),0));
	chess[x][y] = 'K';
	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		x--, y--;
		enemy.push_back(make_pair(x, y));
		chess[x][y] = 'E';
	}


	int countedEnemy = 0;
	while (!knight.empty()) {
		if (countedEnemy == enemy.size())break;
		pair<pair<int, int>,int> curKnight = knight.front();
		knight.pop();

		for (int d = 0; d < 8; d++) {
			int nr = curKnight.first.first + dr[d];
			int nc = curKnight.first.second + dc[d];
			int count = curKnight.second + 1;
			if (nr < 0 || nc < 0 || nr >= N || nc >= N) continue;
			if (chess[nr][nc] == 'E' && countedMap[nr][nc] == 0) {
				countedMap[nr][nc] = count;
				countedEnemy++;
			}
			if (chess[nr][nc] != 'K') {
				knight.push(make_pair(make_pair(nr, nc),count));
				chess[nr][nc] = 'K';
			}
		}
	}

	for (int i = 0; i < enemy.size(); i++) 
		cout << countedMap[enemy[i].first][enemy[i].second] << " ";
	cout << "\n";
}
