/*
������ 3
*/
#include<iostream>
#include<queue>
using namespace std;

int N, M;
int map[50][50];				//�ʱ���¹迭
int virus_check[50][50];		//ó�� ���̷����Է¹޾����� ���� 1�� ����
int temp_map[50][50];			//visit�迭
int mintime = 987654321;
int maxtime = 0;
int flag;
int total;
struct v {
	int r;
	int c;
	int time;
};
vector<v>virus;				//�ʱ⿡ �������� ���̷��� ��ġ��
queue<v>infected;			//�����Ǵ� ���̷�����ġ��
v order[10];				//���ġ�� ���̷������� Ȱ��ȭ��ų�������� ����
int visit[10];				//���ձ��Ҷ� ����ϴ� �迭
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };

void copy_map() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			temp_map[i][j] = virus_check[i][j];
		}
	}
}

void BFS() {
	int cnt = 0;
	while (!infected.empty()) {
		v temp = infected.front();
		infected.pop();
		for (int i = 0; i < 4; i++) {
			int nr = temp.r + dr[i];
			int nc = temp.c + dc[i];
			if (nr >= 0 && nc >= 0 && nr < N && nc < N && temp_map[nr][nc] == 0) {			//���ȿ� �ְ�, �湮���� ���°���
				v insert;
				insert.r = nr;
				insert.c = nc;
				insert.time = temp.time + 1;
				infected.push(insert);
				temp_map[nr][nc] = 1;

				if (map[nr][nc] == 0) {			//������϶��� �ð�����
					cnt++;
					maxtime = insert.time;
				}
			}
		}
	}
	if (cnt == total)mintime = (maxtime < mintime) ? maxtime : mintime;			//������� ������쿡 ���� �̸ʿ��� �ɸ��ð�(maxtime)�� ������ ���Դ� �ɸ��ð�(mintime)�� ���������� ����
}

void combi(int index, int cnt) {
	if (cnt == M) {
		copy_map();
		for (int j = 0; j < cnt; j++)
			infected.push(order[j]);
		BFS();
		maxtime = 0;
		return;
	}
	for (int i = index; i < virus.size(); i++) {
		if (visit[i] == false) {
			visit[i] = true;
			order[cnt] = virus.at(i);
			combi(i, cnt + 1);
			visit[i] = false;
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) 			//���ΰ�� ǥ��
				virus_check[i][j] = 1;

			else if (map[i][j] == 2) {
				v temp;
				temp.r = i;
				temp.c = j;
				temp.time = 0;
				virus.push_back(temp);
			}
			else total++;
		}
	}

	if (total != 0)
		combi(0, 0);

	if (total == 0)mintime = 0;
	else if (mintime == 987654321)mintime = -1;

	cout << mintime << endl;
}