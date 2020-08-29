/*미생물 격리*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 100

struct MICRO {
	int num, dir;
};
int N, M, K;
int dr[5] = { 0,-1,1,0,0 };
int dc[5] = { 0,0,0,-1,1 };
MICRO map[MAX][MAX];

int main() {
	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		cin >> N >> M >> K;
		int r, c, num, dir;
		int answer = 0;
		
		for (int i = 0; i < K; i++) {
			cin >> r >> c >> num >> dir;
			map[r][c] = { num,dir };
		}
		vector<MICRO> temp[MAX][MAX];

		while (M--) {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					if (map[i][j].num != 0) {
						int nr = i + dr[map[i][j].dir];
						int nc = j + dc[map[i][j].dir];
						//다음 위치가 특수약품
						if (nr<=0 || nc<=0 || nr>=N-1 || nc>=N-1) {
							int dir = map[i][j].dir;
							//다음위치가 경계를 벗어날때
							if (nr + dr[map[i][j].dir] < 0 || nr + dr[map[i][j].dir] >= N || nc + dc[map[i][j].dir] < 0 || nc + dc[map[i][j].dir] >= N) 
								dir = (map[i][j].dir % 2 == 0) ? map[i][j].dir - 1 : map[i][j].dir + 1;
							
							temp[nr][nc].push_back({ map[i][j].num/2, dir });
							map[i][j].num = 0;
						}
						//다음 위치는 일반 위치
						else {
							temp[nr][nc].push_back({ map[i][j].num,map[i][j].dir });
							map[i][j].num = 0;
						}
					}
				}
			}

			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					if (temp[i][j].size() != 0) {
						if (temp[i][j].size() == 1) {
							map[i][j] = temp[i][j].back();
							temp[i][j].pop_back();
						}
						else {
							int maxx = 0;
							int maxNum = 0;
							int dir = 0;
							int size = temp[i][j].size();
							for (int k = 0; k < size; k++) {
								maxx += temp[i][j].back().num;
								if (maxNum < temp[i][j].back().num) {
									maxNum = temp[i][j].back().num;
									dir = temp[i][j].back().dir;
								}
								temp[i][j].pop_back();
							}
							map[i][j] = { maxx,dir };
						}
					}
				}
			}
		}
		

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j].num != 0)answer += map[i][j].num;
				map[i][j].num = 0;
			}
		}
		cout << "#" << test_case << " " << answer << "\n";
	}
}
