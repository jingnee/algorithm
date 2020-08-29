/*뱀*/
#include <iostream>
#include <queue>
using namespace std;

int N, K, L;
int map[101][101];
queue <pair<int, char>> que;
queue <pair<int, int>> snake;
int dr[4] = { 0,-1,0,1 };			//왼 위 오 아
int dc[4] = { -1,0,1,0 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;
	for (int i = 0; i < K; i++) {
		int a, b;
		cin >> a >> b;
		map[a][b] = 1;
	}
	cin >> L;
	for (int i = 0; i < L; i++) {
		int num;
		char dir;
		cin >> num >> dir;
		que.push(make_pair( num,dir ));
	}
	
	//초깃값
	int curdir = 2;			//처음은 오른쪽방향
	int curtime = 0;
	int r = 1;
	int c = 1;
	map[r][c] = 2;				//2는 뱀이 있다는 뜻
	snake.push(make_pair(r, c));	//snake에는 뱀을 만드는 좌표들이 들어있음

	while (1) {
		r += dr[curdir];
		c += dc[curdir];
		curtime++;
		//범위 벗어나면 끝
		if (r > N || c > N || r < 1 || c < 1)break;
		//다음 위치가 꼬리이면 끝
		if (map[r][c] == 2) break;
		//사과없으면 꼬리 제거 
		if (map[r][c] == 0) {
			pair<int, int> temp = snake.front();
			map[temp.first][temp.second] = 0;
			snake.pop();
		}

		snake.push(make_pair(r, c));
		map[r][c] = 2;

		if (!que.empty() && que.front().first == curtime) {
			char nd = que.front().second;
			if (nd == 'D')curdir = (curdir + 1) % 4;
			else curdir = (curdir + 3) % 4;
			que.pop();
		}
	}

	cout << curtime << "\n";
}
