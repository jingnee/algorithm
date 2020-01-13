/*
1. n��(1)�� �Ʒ���, s��(2)�� �����̵��ϴµ�, ���� ���� �̵��������ϴ� ���������� ���� ����ϱ�.
2. N <= 100
3. 2�� for���� ���鼭(���θ������ƴ� ���θ�����) 1�� ã�� �Ʒ� 2�� �ִ��� üũ
*/
#include <iostream>
using namespace std;

int answer;			//���� ���� ����
int map[100][100];	//���̺�
int N;				//���̺� ũ��

int check(int r, int c) {			//�������� ã���Լ�
	int i = r + 1;
	for (i; i < N; i++) {			//ã��1�Ʒ����� 2���ִ��� �˻�
		if (map[i][c] == 2) {
			answer++;
			return i;					//2ã�� �����ġ ��ȯ
		}
	}
	return i;								//ã�� ���Ѱ�� ��������ġ ��ȯ
}

int main() {
	int T = 10;
	for (int test_case = 1; test_case <= T; test_case++) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
			}
		}

		for (int col = 0; col < N; col++) {
			for (int row = 0; row < N; row++) {
				if (map[row][col] == 1) {		//1ã��
					int next_row= check(row, col);
					row = next_row;
				}
			}
		}
		cout << "#" << test_case << " " << answer << endl;
		
		answer = 0;			//�ʱ�ȭ
	}
}