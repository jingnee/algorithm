/*
 [SW] Ư���� �ڼ�
 1. ���� �ڼ��� ����ִ� �ڼ� 4���� �ִ�. �ð���� �Ǵ� �ݽð�������� ȸ���� �����ѵ�, ȸ���� ���� �ڼ��� �پ��ִ� ���� �������� pass,
 �޶����� �����ڼ� ȸ���� �ݴ�������� ȸ���Ѵ�.
 2. ���� > �ð����:1 , �ݽð����: -1
	�ڼ� > N��:0, S��:1
	�ڼ���4��, �ڼ��� 8��
3. magnetic[4][8]: magnetic ������ �������
	arrow[4]	: ȭ��ǥ��ġ
	index[4][2]	: ����ִ� �ڼ��� ��ġ(
	[0][1]:�ڼ�1���� 1,2����ִ���ġ, 
	[1][0]:�ڼ�2���� 1,2����ִ� ��ġ,
	[1][1]:�ڼ�2���� 2,3����ִ���ġ,
	[2][0]:�ڼ�3���� 2,3����ִ���ġ,
	[2][1]:�ڼ�3���� 3,4����ִ���ġ,
	[3][0]:�ڼ�4���� 3,4����ִ���ġ)

�ð�������� ���ư��� ȭ��ǥ�� ��������, �ݽð�������� ���ư��� ȭ��ǥ�� �������̷� �̵��ϹǷ�
ȭ��ǥ�� ��ġ�� ����*-1
*/


#include<iostream>
using namespace std;

int magnetic[4][8];
void rotate(int m, int d) {		//m�� �ڼ��� d�������� ����
	if (d == 1) {	//�ð����ȸ��. [0]=[7], [1]=[0], [2]=[1], ... [7]=[6]
		int temp = magnetic[m][0];
		magnetic[m][0] = magnetic[m][7];
		for (int i = 7; i > 1; i--)magnetic[m][i] = magnetic[m][i - 1];
		magnetic[m][1] = temp;
	}

	else if (d == -1) {
		int temp = magnetic[m][7];
		magnetic[m][7] = magnetic[m][0];
		for (int i = 0; i < 6; i++)magnetic[m][i] = magnetic[m][i + 1];
		magnetic[m][6] = temp;
	}
}

bool check(int a, int b) {		//a�ڼ��� b�ڼ��� ����ִ� �ڼ��� ������ Ȯ��
	if (a > b) {
		if (magnetic[a][6] == magnetic[b][2])return true;
		else return false;
	}
	else {
		if (magnetic[a][2] == magnetic[b][6])return true;
		else return false;
	}
}
//main���� ������� ���� �ڼ��� �����ڼ��� �����°�.�׷��ϱ� �� �Լ��� �����ڼ��� ���ڰ����� �����Ƿ� ������ �ڼ��� ��
void turn_left(int m, int d) {		
	if (m < 0 || m>4)return;
	else if (!check(m, m + 1)) {	//üũ�Լ����� �ڼ��� �ٸ��� ������
		turn_left(m - 1, d*-1);
		rotate(m, d);
	}
}
void turn_right(int m, int d) {
	if (m < 0 || m>4)return;
	else if (!check(m - 1, m)) {
		turn_right(m + 1, d*-1);
		rotate(m, d);
	}
}

int main() {
	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		int k;
		int magnetic_num, direction;
		cin >> k;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 8; j++) {
				cin >> magnetic[i][j];
			}
		}

		for (int i = 0; i < k; i++) {
			cin >> magnetic_num >> direction;
			magnetic_num--;

			turn_left(magnetic_num - 1, direction*-1);
			turn_right(magnetic_num + 1, direction*-1);
			rotate(magnetic_num, direction);
		}

		int answer = 0;
		for (int i = 0; i < 4; i++) {
			if (magnetic[i][0] == 1) {
				int num;
				if (i == 0)num = 1;
				else if (i == 1)num = 2;
				else if (i == 2)num = 4;
				else if (i == 3)num = 8;
				answer += num;
			}
		}
		cout << "#" << test_case << " " << answer << endl;
	}
}

/*
���ڵ� ������: �������� Ž���Ϸ��� ��� �������� ���鼭 Ž���ؾ��ϴµ� ���� �������ΰ��� ���ʿ����� �Ѵ� �����������ϱ� �������� ����µ�

#include<iostream>
using namespace std;

int magnetic[4][8];
int arrow[4];
int index[4][2];
int visit[4];
int changeArrow(int arrow, int d) {		//ȭ��ǥ��ġ�� �ٲپ��ִ� �Լ�
	int new_arrow = arrow + d;
	if (new_arrow < 0)new_arrow = 7;
	else if (new_arrow > 7)new_arrow = 0;
	return new_arrow;
}

void simul(int m_num, int direction) {
	arrow[m_num] = changeArrow(arrow[m_num], direction);		//ȭ��ǥ��ġ����
	//visit[m_num] = 1;
	//���� Ž��

		if (index[m_num][0] != -1) {
			//if(visit[m_num-1]==1)index[m_num][0] = changeArrow(index[m_num][0], direction);
			if (magnetic[m_num][index[m_num][0]] == magnetic[m_num - 1][index[m_num - 1][1]]) {
				index[m_num][0] = changeArrow(index[m_num][0], direction);
			}
			else {
				index[m_num][0] = changeArrow(index[m_num][0], direction);
				simul(m_num - 1, direction*-1);
				//visit[m_num - 1] = 0;
			}
		}

	//������ Ž��

		if (index[m_num][1] != -1) {
			//if (visit[m_num+1] == 1)index[m_num][0] = changeArrow(index[m_num][0], direction);
			if (magnetic[m_num][index[m_num][1]] == magnetic[m_num + 1][index[m_num + 1][0]]) {		//�����ڼ��̸� ������ ȸ����Ű������, �����ڼ� index���� ����(����ִ���ġ)
				index[m_num][1] = changeArrow(index[m_num][1], direction);
			}

			else {
				index[m_num][1] = changeArrow(index[m_num][1], direction);
				simul(m_num + 1, direction*-1);
				//visit[m_num + 1] = 0;
			}
		}

	//index[m_num][0] = changeArrow(index[m_num][0], direction);
	//index[m_num][1] = changeArrow(index[m_num][1], direction);
}

int main() {
	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		int k;
		int magnetic_num, direction;
		cin >> k;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 8; j++) {
				cin >> magnetic[i][j];
			}
		}
		//�ʱ�ȭ �۾�  2��6��
		index[0][0] = -1;
		index[0][1] = 2;
		index[1][0] = 6;
		index[1][1] = 2;
		index[2][0] = 6;
		index[2][1] = 2;
		index[3][0] = 6;
		index[3][1] = -1;
		for (int i = 0; i < 4; i++) {
			arrow[i] = 0;
			visit[i] = 0;
		}

		for (int i = 0; i < k; i++) {
			cin >> magnetic_num >> direction;
			direction *= -1;
			magnetic_num--;

			simul(magnetic_num, direction);
			for (int i = 0; i < 4; i++)visit[i] = 0;
		}

		int answer = 0;
		for (int i = 0; i < 4; i++) {
			if (magnetic[i][arrow[i]] == 1) {
				int num;
				if (i == 0)num = 1;
				else if (i == 1)num = 2;
				else if (i == 2)num = 4;
				else if (i == 3)num = 8;
				answer += num;
			}
		}

		cout << "#" << test_case << " " << answer << endl;

	}
}
*/
