/*�������� --DFS*/
#include <iostream>
using namespace std;

int N, M;
int map[500][500];
int visit[500][500];
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };
int DFS(int r, int c) {
	if (r == N - 1 && c == M - 1) {			//�� ������ �Ʒ� ����(��������)
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
		if (nr >= 0 && nc >= 0 && nr < N && nc < M) {			//���� ��ġ�� ��� �ȿ� �ְ�,
			if (map[nr][nc] < map[r][c]) {		//���� ���̺��� �� ������
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
			visit[i][j] = -1;				//�� -1�� �ʱ�ȭ���������� �ð��ʰ� ��������?
		}
	}
	cout << DFS(0,0) << endl;
}


///*�������� --DFS(�ð� �ʰ�)*/
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
//	if (r == N - 1 && c == M - 1) {			//�� ������ �Ʒ� ����(��������)
//											//answer++;
//											//cout << answer << "��° ��δ� " << endl;
//											//for (int i = 0; i < index; i++)cout << path[i][0] << "," << path[i][1] << "-> ";
//		answer++;								//cout << endl;
//		return;
//	}
//
//	for (int d = 0; d < 4; d++) {
//		b++;
//		int nr = r + dr[d];
//		int nc = c + dc[d];
//		if (nr >= 0 && nc >= 0 && nr < N && nc < M) {			//���� ��ġ�� ��� �ȿ� �ְ�,
//			if (!visit[nr][nc] && map[nr][nc] < map[r][c]) {		//���� ���̺��� �� ������
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
//	cout << "DFS�Լ� ȣ��:" << a << "for�� ȣ��:" << b << "���ȿ��ְ�, ���̵� ������:" << e << endl;
//
//}