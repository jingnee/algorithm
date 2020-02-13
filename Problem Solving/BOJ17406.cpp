// 배열 돌리기 4
//고친부분 조합찾을때마다 돌려주고 확인한다음 리턴하면 되돌려주는 함수가 있었는데, 조합을 구하고나서 한번에 돌리는것으로 변경
// rotate함수도 돌리는순서를 잘 정해서 한방향으로 돌려줌 그전에는 변수두개쓰고 가장 첫번째값 받아가면서 돌리고 넣어주고했는데
//딱히 다른부분 건들지 않고 rotate수정해서 성공하는거보니까 sr,sc,len->r,c,l으로 수정하고 돌리는 구현이 잘못되었었나봄
//왠만하면 문제에서 주어진대로 사용하자(인덱스를) 원래 인덱스로 r+l-1,c+l-1,l*2+1를 넣었음(복잡) 결국 함수안에서 sr,sc,len 구하는 연산은 똑같았는데..

#include <iostream>
using namespace std;

int N, M, K;
int map[50][50];
int copy_map[50][50];
int order[6][3];
int corder[6];
bool visit[6];
int mini = 987654321;
void find_min() {	//가장 작은 합을 가진 행 찾기
	int answer = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			answer += copy_map[i][j];
		}
		if (answer < mini)mini = answer;
		answer = 0;
	}
}

void initMap() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			copy_map[i][j] = map[i][j];
		}
	}
}

void rotate(int r, int c, int l) {		//[sr][sc]부터 [sr+len-1][sc+len-1]까지 테두리 시계방향 돌리기
	int len = l * 2 + 1;
	int sr = r - l - 1;
	int sc = c - l - 1;
	if (len == 1)return;
	int temp = copy_map[sr][sc];
	for (int i = 0; i <= len-2; i++)copy_map[sr+i][sc] = copy_map[sr+i+1][sc];		//왼쪽테두리 돌리기
	for (int i = 0; i <= len-2; i++)copy_map[sr + len-1][sc + i] = copy_map[sr + len-1][sc + i+1]; //아래테두리돌리기
	for (int i = len-2; i >= 0; i--)copy_map[sr + i+1][sc + len-1] = copy_map[sr + i][sc + len-1];	//오른쪽테두리 돌리기
	for (int i = len-2; i > 0; i--)copy_map[sr][sc+i+1] = copy_map[sr][sc+i];
	copy_map[sr][sc + 1] = temp;

	rotate(r, c, l-1);		//안에테두리돌리기
}

void combi(int cnt) {
	if (cnt == K) {
		initMap();
		for (int i = 0; i < K; i++) {
			int j = corder[i];
			rotate(order[j][0], order[j][1], order[j][2]);
		}
		find_min();
		
		return;
	}
	for (int i = 0; i < K; i++) {
		if (visit[i] == false) {
			visit[i] = true;
			corder[cnt] = i;
			combi(cnt+1);
			visit[i] = false;
		}
	}
}

int main() {
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < K; i++)
		cin >> order[i][0] >> order[i][1] >> order[i][2];

	combi(0);
	cout << mini << endl;
}