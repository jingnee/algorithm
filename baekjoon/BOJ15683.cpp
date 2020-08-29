/*감시
1. 5가지 종류의 CCTV로 맵을 감시하는데, 사각지대 가장 적은경우의 사각지대 갯수
2. 1<=N,M<=8
3. 완전탐색
참고를 많이함..
*/

#include<iostream>
#include<vector>
using namespace std;

int map[8][8];
int visit[8][8];
int copy_visit[8][8];
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };
int order[8];			//각 감시카메라들에 대한 방향값 배열(조합으로 모든방향)
int N, M;
int mini = 987654321;
struct CCTV {
	int num;
	int r;
	int c;
};
vector<CCTV> cctv;
vector<CCTV> cctv5;
int cctv_num;
void check(int r, int c, int d, int arr[][8]) {
	int nr = r + dr[d];
	int nc = c + dc[d];
	while (nr >= 0 && nc >= 0 && nr < N && nc < M && map[nr][nc] != 6) {
		arr[nr][nc] = 1;
		nr += dr[d];
		nc += dc[d];
	}
}
void copy() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			copy_visit[i][j] = visit[i][j];
		}
	}
}

void simul() {		//cctv 담아있는 cctv의 번호와 조합으로 저장해놓은 방향을 이용해서 각 CCTV 방향대로 감시
	for (int i = 0; i < cctv_num; i++) {
		CCTV temp = cctv.at(i);
		switch (map[temp.r][temp.c]) {
		case 1:
			check(temp.r, temp.c, order[i], copy_visit);
			break;
		case 2:
			check(temp.r, temp.c, order[i], copy_visit);
			check(temp.r, temp.c, order[i]+2, copy_visit);
			break;
		case 3:
			check(temp.r, temp.c, order[i], copy_visit);
			check(temp.r, temp.c, (order[i]+1)%4, copy_visit);
			break;
		case 4:
			for (int j = 0; j < 4; j++) {
				if (order[i] != j)check(temp.r, temp.c, j, copy_visit);
			}
			break;
		}
	}
}

int count() {
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (copy_visit[i][j] == 0)cnt++;
		}
	}
	return cnt;
}

void combi(int cnt) {				//감시카메라들의 방향들을 조합으로 구함
	if (cnt == cctv_num) {
		//맵카피
		copy();
		//조합순서에따라 (각 방향값에 맞춰서)체크
		simul();
		//최솟값찾기
		int c = count();
		mini = (mini < c) ? mini : c;
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (i >= 2 && cctv.at(cnt).num == 2)continue;
		order[cnt] = i;
		combi(cnt + 1);
	}

}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 5) {
				CCTV temp;
				temp.r = i;
				temp.c = j;
				cctv5.push_back(temp);
			}
			else if (map[i][j] >= 1 && map[i][j] <= 4) {
				CCTV temp;
				temp.r = i;
				temp.c = j;
				temp.num = map[i][j];
				visit[i][j] = true;
				cctv.push_back(temp);
				cctv_num++;
			}
			else if (map[i][j] == 6)visit[i][j] = true;
		}
	}

	while (!cctv5.empty()) {
		CCTV temp = cctv5.back();
		cctv5.pop_back();
		visit[temp.r][temp.c] = 1;
		for (int i = 0; i < 4; i++)
			check(temp.r, temp.c, i, visit);
	}

	combi(0);
	cout << mini << endl;

}