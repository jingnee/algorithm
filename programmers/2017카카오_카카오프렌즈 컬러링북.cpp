//īī�� ������ �÷��� ��
#include <vector>
#include <queue>
using namespace std;

bool map[100][100];
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };
// ���� ������ ������ ��� �Լ� ���� �ʱ�ȭ �ڵ带 �� �ۼ����ּ���.
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