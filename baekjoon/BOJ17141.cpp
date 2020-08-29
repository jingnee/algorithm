//������2

#include<iostream>
#include<queue>
using namespace std;

int N, M;
int map[50][50];
int virus_check[50][50];
int temp_map[50][50];
int mintime = 987654321;
int maxtime = 0;
int flag;

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

int check() {		//check���� 0���� ũ�� ���̷����� ��� ��������
	int num = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (temp_map[i][j] == 0)num++;
		}
	}
	return num;
}

void BFS() {
	int cnt = 0;
	while (!infected.empty()) {
		v temp = infected.front();
		infected.pop();
		for (int i = 0; i < 4; i++) {
			int nr = temp.r + dr[i];
			int nc = temp.c + dc[i];
			if (nr >= 0 && nc >= 0 && nr < N && nc < N && map[nr][nc] != 1 && temp_map[nr][nc]==0) {
				v insert;
				insert.r = nr;
				insert.c = nc;
				insert.time = temp.time + 1;
				infected.push(insert);
				temp_map[nr][nc] = 1;
				maxtime = (maxtime < insert.time) ? insert.time : maxtime;
			}
		}
	}
	int num = check();
	if (num == 0) {
		flag = 1;
		mintime = (mintime > maxtime) ? maxtime : mintime;
	}
	if (flag == 0 && num == 0)mintime = 987654321;
}

void combi(int index, int cnt) {
	if (cnt == M) {
		copy_map();
		for (int j = 0; j < cnt; j++) {
			infected.push(order[j]);
			temp_map[order[j].r][order[j].c] = 1;
		}
			
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
		}
	}

	combi(0, 0);

	if (mintime == 987654321)mintime = -1;

	cout << mintime << endl;
}