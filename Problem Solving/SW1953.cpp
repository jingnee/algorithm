//Ż�ֹ� �˰�
#include<iostream>
#include<vector>
#include<queue>
using namespace std; 

int N, M;
int map[50][50];
int visit[50][50];
int ttime;
int dr[4] = { -1,0,1,0 };			//�������
int dc[4] = { 0,1,0,-1 };
int pipe[8][2] = {
	{0,2},{3,1},{0,2},{3,1},{0,1},{2,1},{2,3},{0,3}
};
/*
1. �����¿� => 0,2,3,1
2. ���� => 0,2
3. �¿� => 3,1
4. ��� => 0,1
5. �Ͽ� => 2,1
6. ���� => 2,3
7. ���� => 0,3
*/
struct pos {
	int r;
	int c;
	int time;
};
queue<pos> thief;
//vector<pos> thief;

void init() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visit[i][j] = -1;
		}
	}
}

int count(int time) {
	int answer = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visit[i][j] <= time && visit[i][j]>=1)answer++;
		}
	}
	return answer;
}

int main() {
	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		
		cin >> N >> M;
		pos temp;
		cin >> temp.r >> temp.c >> ttime;
		init();

		temp.time = 1;
		visit[temp.r][temp.c] = 1;
		thief.push(temp);
		//thief.push_back(temp);
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> map[i][j];
				if (map[i][j] == 0)visit[i][j] = 30;			//Ż��ҿ�ð��� �ִ� 20
			}
		}

		//BFS();
		while (!thief.empty()) {
			pos temp = thief.front();
			thief.pop();
			int sw = map[temp.r][temp.c];

			if (sw == 1) {
				for (int i = 0; i < 2; i++) {
					for (int j = 0; j < 2; j++) {
						int nr = temp.r + dr[pipe[i][j]];
						int nc = temp.c + dc[pipe[i][j]];
						if (nr >= 0 && nc >= 0 && nr < N && nc < M && visit[nr][nc] == -1 ) {			//���� �����ְ� �湮�� �� ������
							if (map[nr][nc] != 1 && (pipe[i][j] + 2) % 4 != pipe[map[nr][nc]][0] && (pipe[i][j] + 2) % 4 != pipe[map[nr][nc]][1]) continue;
							visit[nr][nc] = temp.time + 1;
							pos next_thief;
							next_thief.r = nr;
							next_thief.c = nc;
							next_thief.time = temp.time + 1;
							thief.push(next_thief);
							//cout << next_thief.time << "�ð� ������ġ[" << next_thief.r << "][" << next_thief.c << "]" << endl;
						}
					}
				}

			}
			else {
				for (int i = 0; i < 2; i++) {
					int nr = temp.r + dr[pipe[sw][i]];
					int nc = temp.c + dc[pipe[sw][i]];
					if (nr >= 0 && nc >= 0 && nr < N && nc < M && visit[nr][nc] == -1) {			//���� �����ְ� �湮�� �� ������
						if (map[nr][nc] != 1 && (pipe[sw][i] + 2) % 4 != pipe[map[nr][nc]][0] && (pipe[sw][i] + 2) % 4 != pipe[map[nr][nc]][1]) continue;			//������ġ�� 1�̾ƴϰ�, ���ᵵ�ȵȰ��
						visit[nr][nc] = temp.time + 1;
						pos next_thief;
						next_thief.r = nr;
						next_thief.c = nc;
						next_thief.time = temp.time + 1;
						thief.push(next_thief);
						//cout << next_thief.time << "�ð� ������ġ[" << next_thief.r << "][" << next_thief.c << "]" << endl;
					}
				}
			}
			
		}
		////visitȮ�ο�
		//for (int i = 0; i < N; i++) {
		//	for (int j = 0; j < M; j++) {
		//		if(visit[i][j]<30 || visit[i][j]!=-1)
		//		cout<<' ' << visit[i][j];
		//		else cout << visit[i][j];
		//	}cout << endl;
		//}

		cout << "#" << test_case << " " << count(ttime) << endl;
	}
}