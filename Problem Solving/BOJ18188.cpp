// �ٿ��� ����Ʈ
//����� �������� ���� �����ϰų� ���������Ѵ�.
//�װɸ��ؼ� �ڲ� �迭�� ��Ե�. ����Լ��� �����ϸ鼭 �迭�� ��ԵǹǷ� ����� �������� ��ƿ� ���Ⱚ �����ϴ°��� �߿�
//���� ���糪 �ε��� ���� ������ ��ӳ� ���Ͱ����Ұ�..

#if 1
#include<iostream>
#include<vector>
using namespace std;

char map[21][21];
int H, W, N;
//char answer[20];
vector<char> answer, anss;	//answer�� Ž���ϸ鼭 char�ִ¹迭, anss�� ����ϸ������� string�����ϴ¹迭
char marid[20][2];
int dao[2][2];			//dao[0]���� dao��ġ, dao[1]���� dizney��ġ
int flag;				//����ϸ����� ��� ������ 1
void search(int y, int x, int n) {
	if (map[y][x] == 'Z') {
		anss.assign(answer.begin(), answer.end());
		flag = 1;
		return;
	}
	if (n == N)return;
	for (int i = 0; i < 2; i++) {
		char ch = marid[n][i];
		int ny, nx;
		switch (ch) {
		case 'A':
			ny = y;
			nx = x - 1;
			//answer[w++] = 'A';
			answer.push_back('A');
			break;
		case 'W':
			ny = y - 1;
			nx = x;
			//answer[w++] = 'W';
			answer.push_back('W');
			break;
		case 'S':
			ny = y + 1;
			nx = x;
			//answer[w++] = 'S';
			answer.push_back('S');
			break;
		case 'D':
			ny = y;
			nx = x + 1;
			//answer[w++] = 'D';
			answer.push_back('D');
			break;
		}
		if (ny < 0 || nx < 0 || ny >= W || nx >= H || map[ny][nx] == '@') {
			//w--;
			answer.pop_back();
		}

		else {
			//w++;
			search(ny, nx, n + 1);
			answer.pop_back();
			//w--;
		}

	}
}
int main() {
	cin >> W >> H;
	for (int i = 0; i < W; i++) {
		for (int j = 0; j < H; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'D') {
				dao[0][0] = i;
				dao[0][1] = j;
			}
			else if (map[i][j] == 'Z') {
				dao[1][0] = i;
				dao[1][1] = j;
			}
		}
	}
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> marid[i][0];
		cin >> marid[i][1];
	}
	
	search(dao[0][0], dao[0][1], 0);
	if (flag == 0)cout << "NO";
	else {
		cout << "YES" << endl;
		for (int i = 0; i<anss.size();i++)
			cout << anss[i];
	}

}
#endif

#if 1
#include <iostream>
#include <vector>
using namespace std;

char order[20][2];
char map[20][20];
int sr, sc;
vector<char> answer, tmp;
int N, H, W, flag;
int dr[4] = {0,-1,0,1};//W A S D
int dc[4] = {-1,0,1,0};//W A S D

int next_dir(char dir) {
	if (dir == 'W')return 0;
	else if (dir == 'A')return 1;
	else if (dir == 'S')return 2;
	else return 3;
}

void dfs(int r, int c, int n) {
	if (flag)return;

	if (map[c][r] == 'Z') {
		cout << "YES" << endl;
		for (int i = 0; i < answer.size(); i++)cout<<answer[i];
		flag = 1;
		return;
	}

	if (n == N)return;
	for (int i = 0; i < 2 && !flag; i++) {
		int nd = next_dir(order[n][i]);
		int nr = r + dr[nd];
		int nc = c + dc[nd];

		if (nr >= 0 && nc >= 0 && nr < H && nc < W && map[nc][nr] != '@') {
			answer.push_back(order[n][i]);
			dfs(nr, nc, n + 1);
			answer.pop_back();
		}
	}
}

int main() {
	cin >> W >> H;
	for (int i = 0; i < W; i++) {
		for (int j = 0; j < H; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'D') {
				sc = i;
				sr = j;
			}
		}
	}
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> order[i][0] >> order[i][1];
	}
	dfs(sr, sc, 0);
	if (!flag)cout << "NO";
}
#endif
