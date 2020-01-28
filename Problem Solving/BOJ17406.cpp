// �迭 ������ 4
//��ģ�κ� ����ã�������� �����ְ� Ȯ���Ѵ��� �����ϸ� �ǵ����ִ� �Լ��� �־��µ�, ������ ���ϰ��� �ѹ��� �����°����� ����
// rotate�Լ��� �����¼����� �� ���ؼ� �ѹ������� ������ �������� �����ΰ����� ���� ù��°�� �޾ư��鼭 ������ �־��ְ��ߴµ�
//���� �ٸ��κ� �ǵ��� �ʰ� rotate�����ؼ� �����ϴ°ź��ϱ� sr,sc,len->r,c,l���� �����ϰ� ������ ������ �߸��Ǿ�������
//�ظ��ϸ� �������� �־������ �������(�ε�����) ���� �ε����� r+l-1,c+l-1,l*2+1�� �־���(����) �ᱹ �Լ��ȿ��� sr,sc,len ���ϴ� ������ �Ȱ��Ҵµ�..

#include <iostream>
using namespace std;

int N, M, K;
int map[50][50];
int copy_map[50][50];
int order[6][3];
int corder[6];
bool visit[6];
int mini = 987654321;
void find_min() {	//���� ���� ���� ���� �� ã��
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

void rotate(int r, int c, int l) {		//[sr][sc]���� [sr+len-1][sc+len-1]���� �׵θ� �ð���� ������
	int len = l * 2 + 1;
	int sr = r - l - 1;
	int sc = c - l - 1;
	if (len == 1)return;
	int temp = copy_map[sr][sc];
	for (int i = 0; i <= len-2; i++)copy_map[sr+i][sc] = copy_map[sr+i+1][sc];		//�����׵θ� ������
	for (int i = 0; i <= len-2; i++)copy_map[sr + len-1][sc + i] = copy_map[sr + len-1][sc + i+1]; //�Ʒ��׵θ�������
	for (int i = len-2; i >= 0; i--)copy_map[sr + i+1][sc + len-1] = copy_map[sr + i][sc + len-1];	//�������׵θ� ������
	for (int i = len-2; i > 0; i--)copy_map[sr][sc+i+1] = copy_map[sr][sc+i];
	copy_map[sr][sc + 1] = temp;

	rotate(r, c, l-1);		//�ȿ��׵θ�������
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