/*
1. ������ Ű(B)���� ���� �ټ��� ���̷� ū ������ Ű������ ã�ƶ�. ����� ���̾ƴ� ��
2. 1<= N(������) <= 20,
	1<= �� �������� Ű <=10000
	1<= B(������ Ű) <= 20,
3. ����Ž���� �ϵ�, �� �������� Ű�� ���� ������ Ű�� ������ ���̻� Ž������ �ʴ´�.
	����� �� 20*19*18*17*...*1 
*/
#include<iostream>
using namespace std;

int min = 987654321;			//���� ���� ��
int tall[20];					//������ Ű
bool visit[20];					//i��° ���� Ű �����ߴ��� Ȯ��
bool check[200001];
int N, B;
void dfs(int index, int sum) {
	if (sum >= B) {
		check[sum] = true;
		int cha = sum - B;
		min = (cha < min) ? cha : min;
		return;
	}

	for (int i = index; i < N; i++) {
		if (!visit[i]) {			//�������� ���� ������ ��쿡�� ����
			visit[i] = true;
			if(!check[sum+tall[i]])			//������ ���� sum���� ���ؼ��� �Ǵ�
			dfs(i+1, sum + tall[i]);
			visit[i] = false;
			
		}
	}
}
int main() {
	int T, max;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		max = 0;
		cin >> N >> B;
		for (int i = 0; i < N; i++) {
			cin >> tall[i];
			max += tall[i];
		}

		dfs(0, 0);
		cout << "#" << test_case << " " << min << endl;

		for (int i = 0; i < N; i++) //�ʱ�ȭ
			visit[i] = false;
		for (int i = B; i <= max; i++)check[i] = false;
		min = 987654321;

	}
}