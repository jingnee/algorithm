/*
연구소 3
*/
#include<iostream>
#include<queue>
using namespace std;

int N, M;
int map[50][50];				//초기상태배열
int virus_check[50][50];		//처음 바이러스입력받았을때 벽만 1로 설정
int temp_map[50][50];			//visit배열
int mintime = 987654321;
int maxtime = 0;
int flag;
int total;
struct v {
	int r;
	int c;
	int time;
};
vector<v>virus;				//초기에 정해지는 바이러스 위치값
queue<v>infected;			//감염되는 바이러스위치값
v order[10];				//어떤위치의 바이러스들을 활성화시킬지에대한 조합
int visit[10];				//조합구할때 사용하는 배열
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
			if (nr >= 0 && nc >= 0 && nr < N && nc < N && temp_map[nr][nc] == 0) {			//경계안에 있고, 방문한적 없는곳만
				v insert;
				insert.r = nr;
				insert.c = nc;
				insert.time = temp.time + 1;
				infected.push(insert);
				temp_map[nr][nc] = 1;

				if (map[nr][nc] == 0) {			//빈공간일때만 시간저장
					cnt++;
					maxtime = insert.time;
				}
			}
		}
	}
	if (cnt == total)mintime = (maxtime < mintime) ? maxtime : mintime;			//빈공간이 없을경우에 지금 이맵에서 걸린시간(maxtime)과 여지껏 나왔던 걸린시간(mintime)중 작은값으로 갱신
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
			if (map[i][j] == 1) 			//벽인경우 표시
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