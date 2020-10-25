//카카오 프렌즈 컬러링 북
#include <vector>
#include <queue>
using namespace std;

bool map[100][100];
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
	int number_of_area = 0;
	int max_size_of_one_area = 0;

	for (int i = 0; i<m; i++) {
		for (int j = 0; j<n; j++)map[i][j] = false;
	}

	queue<pair<int, int>> que;
	for (int i = 0; i<m; i++) {
		for (int j = 0; j<n; j++) {
			int temp_max = 0;
			if (picture[i][j] != 0 && map[i][j] == false) {
				int now_color = picture[i][j];
				number_of_area++;
				temp_max++;
				map[i][j] = true;
				que.push(make_pair(i, j));
				while (!que.empty()) {
					int r = que.front().first;
					int c = que.front().second;
					que.pop();
					for (int d = 0; d<4; d++) {
						int nr = r + dr[d];
						int nc = c + dc[d];
						if (nr<0 || nc<0 || nr >= m || nc >= n || picture[nr][nc] != now_color || map[nr][nc] == true)continue;
						que.push(make_pair(nr, nc));
						map[nr][nc] = true;
						temp_max++;
					}
				}
			}
			max_size_of_one_area = (max_size_of_one_area<temp_max) ? temp_max : max_size_of_one_area;
		}
	}

	vector<int> answer(2);
	answer[0] = number_of_area;
	answer[1] = max_size_of_one_area;
	return answer;
}