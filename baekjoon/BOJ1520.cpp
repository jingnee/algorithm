/*내리막길 --DFS*/
#include <iostream>
using namespace std;

int N, M;
int map[500][500];
int visit[500][500];
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };
int DFS(int r, int c) {
	if (r == N - 1 && c == M - 1) {			//맨 오른쪽 아래 도착(기저조건)
		return 1;
	}

	//int &ret = visit[r][c];
	//if (ret != 0)return ret;
	//ret = 0;
	if (visit[r][c] != -1)return visit[r][c];
	visit[r][c] = 0;

	for (int d = 0; d < 4; d++) {
		int nr = r + dr[d];
		int nc = c + dc[d];
		if (nr >= 0 && nc >= 0 && nr < N && nc < M) {			//다음 위치가 경계 안에 있고,
			if (map[nr][nc] < map[r][c]) {		//현재 높이보다 더 낮을때
				visit[r][c] += DFS(nr, nc);
			}
		}
	}
	return visit[r][c];
}

int main() {
	ios::sync_with_stdio();
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			visit[i][j] = -1;				//왜 -1로 초기화하지않으면 시간초과 나오는지?
		}
	}
	cout << DFS(0,0) << endl;
}


///*내리막길 --DFS(시간 초과)*/
//#include <iostream>
//using namespace std;
//
//int N, M, answer;
//int map[500][500];
//int visit[500][500];
////int path[500][2];
//int dr[4] = { -1,0,1,0 };
//int dc[4] = { 0,1,0,-1 };
//int a, b, e;
//void DFS(int r, int c) {
//	a++;
//	if (r == N - 1 && c == M - 1) {			//맨 오른쪽 아래 도착(기저조건)
//											//answer++;
//											//cout << answer << "번째 경로는 " << endl;
//											//for (int i = 0; i < index; i++)cout << path[i][0] << "," << path[i][1] << "-> ";
//		answer++;								//cout << endl;
//		return;
//	}
//
//	for (int d = 0; d < 4; d++) {
//		b++;
//		int nr = r + dr[d];
//		int nc = c + dc[d];
//		if (nr >= 0 && nc >= 0 && nr < N && nc < M) {			//다음 위치가 경계 안에 있고,
//			if (!visit[nr][nc] && map[nr][nc] < map[r][c]) {		//현재 높이보다 더 낮을때
//				e++;
//				visit[nr][nc] = 1;
//				//path[index][0] = nr;
//				//path[index][1] = nc;
//				DFS(nr, nc);
//				visit[nr][nc] = 0;
//			}
//		}
//	}
//}
//
//int main() {
//	cin >> N >> M;
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < M; j++) {
//			cin >> map[i][j];
//		}
//	}
//	visit[0][0] = 1;
//	/*path[0][0] = 0;
//	path[0][1] = 0;*/
//	DFS(0, 0);
//	cout << answer << endl;
//	cout << "DFS함수 호출:" << a << "for문 호출:" << b << "경계안에있고, 높이도 낮을때:" << e << endl;
//
//}