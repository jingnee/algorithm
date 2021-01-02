//선물이 넘쳐 흘러
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int B, N, M, remained, deleted;
int factory[105][105];
vector<pair<pair<int, int>, int>> vec;
int dr[3] = { 1,0,-1 };
int dc[3] = { 0,1,0 };

bool compare(pair<pair<int, int>, int> p1, pair<pair<int, int>, int> p2) {
	if(p1.first.first != B - 2 && p2.first.first != B - 2) {
		if (p1.first.first == p2.first.first)return p1.first.second < p2.first.second;
		else return p1.first.first < p2.first.first;
	}
	else {
		if (p1.first.first != p2.first.first)return p1.first.first < p2.first.first;
		else return p1.first.second > p2.first.second;
	}
	
}

//선물 이동
void move_gift(int r) {
	if (factory[B - 1][0] == -1)deleted++;
	for (int j = 0; j < B - 1; j++)factory[B - 1][j] = factory[B - 1][j + 1];
	for (int i = B - 1; i > 0; i--)factory[i][B - 1] = factory[i - 1][B - 1];
	for (int j = B - 1; j > 0; j--)factory[0][j] = factory[0][j - 1];
	factory[0][0] = 0;
	if (r > 0) {
		factory[0][0] = -1;
		remained--;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> B >> N >> M;
	for (int i = 0; i < N; i++) {
		int r, c, t;
		cin >> r >> c >> t;
		vec.push_back(make_pair(make_pair(r, c), t));
	}
	sort(vec.begin(), vec.end(), compare);
	int cnt = 0;
	remained = M;
	while (cnt++ < 3 * B + M) {
		//선물 이동(남은 선물이 있으면 0,0 위치에 추가)
		move_gift(remained);

		//일 안하는 점원이 선물 포장시작. 일하는 점원은 포장시간 --
		for (auto clerk : vec) {
			//해당 점원이 일을 안하고 있으면, 즉 남은 포장시간이 없다면
			if (factory[clerk.first.first][clerk.first.second] == 0) {
				for (int d = 0; d < 3; d++) {
					int r = clerk.first.first + dr[d];
					int c = clerk.first.second + dc[d];
					//선물있는지 찾아볼 위치가 유효하고(범위내에 있고) 선물이 있으면
					if (r < B && c < B && c >= 0 && r >= 0 && factory[r][c] == -1) {
						factory[r][c] = 0;
						factory[clerk.first.first][clerk.first.second] = clerk.second - 1;
						break;
					}
				}
			}
			//해당 점원의 포장남은 시간이 존재하면
			else factory[clerk.first.first][clerk.first.second]--;
		}
	}
	cout << M - deleted;
}