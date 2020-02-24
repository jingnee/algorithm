/*���μ��� �����ϱ�
1. ����������� ������ ����Ǵ���, �ھ� ��ġ������ ����ü ����
2. �� �ھ�� ������ ���鼭 ������ ��ġ�� �� ������ ���� ��ġ�ϰ� �������� ������
3. ������ �ھ ������ �ھ���� �ִ��� �������� ����
*/

#include<iostream>
#include<vector>
#include<utility>
using namespace std;

int N;
int min_line, max_core;
int map[12][12];
struct Core{
	int r, c;
};
Core cores[12];
int index;
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };
int check(int r, int c, int d) {			//[r][c]���� d�������� ������ ������ �� �ִ���
	int line = 0;
	int flag = 1;
	int nr = r+dr[d];
	int nc = c+dc[d];
	while (nr >= 0 && nc >= 0 && nr < N && nc < N) {
		if (map[nr][nc] != 0) {
			flag = 0;
			break;
		}
		nr += dr[d];
		nc += dc[d];
	}

	if (flag) {
		nr = r+dr[d];
		nc = c+dc[d];
		while (nr >= 0 && nc >= 0 && nr < N && nc < N) {
			if (map[nr][nc] != 0) {
				return 0;
			}

			map[nr][nc] = 2;
			line++;
			
			nr += dr[d];
			nc += dc[d];
		}
	}
	return line;
}

void DFS(int cnt, int coreNum, int lineNum) {
	if (coreNum + (N - cnt) < max_core)return;			//���ݺ��� �ٴ��ص� max_core���� �������
	if (cnt == index) {
		if (max_core < coreNum) {
				max_core = coreNum;
				min_line = lineNum;			
		}
		else if (max_core == coreNum) {
			if (min_line > lineNum)min_line = lineNum;
		}
		return;
	}

	for (int d = 0; d < 4; d++) {
		int num = check(cores[cnt].r, cores[cnt].c, d);
		if (num != 0) {
			DFS(cnt + 1, coreNum + 1, lineNum + num);
			int nr = cores[cnt].r + dr[d];
			int nc = cores[cnt].c + dc[d];
			while (nr >= 0 && nc >= 0 && nr < N && nc < N) {		//�׸��� �������
				map[nr][nc] = 0;
				
				nr += dr[d];
				nc += dc[d];
			}
		}
		else
		DFS(cnt + 1, coreNum, lineNum);

	}
}

int main() {
	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		cin >> N;
		index = 0;
		min_line = 0;
		max_core = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
				if (map[i][j] == 1 && i!=0 && j!=0 && i!= N-1 && j!=N-1) {
					Core core;
					core.r = i;
					core.c = j;
					cores[index++] = core;
				}
			}
		}

		DFS(0, 0, 0);
		cout << "#" << test_case << " " << min_line << endl;

	}
}

