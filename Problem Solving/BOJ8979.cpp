//�ø���
#include <iostream>
using namespace std;

int country[1001][3];
int main() {
	int N, K;
	cin >> N >> K;
	int num;
	for (int i = 1; i <= N; i++) {
		cin >> num;
		for (int j = 0; j < 3; j++) {
			cin >> country[num][j];
		}
	}
	num = 1;
	for (int i = 1; i <= N; i++) {
		if (K == i)continue;			//���Ϸ��� ������ ����� �˰���� ������ ������ continue

		if (country[i][0] > country[K][0]) num++;				//�ݸ޴��� �� ū���
		else if (country[i][0] == country[K][0]) {
			if (country[i][1] > country[K][1])num++;			//�ݸ޴� ������ ������ ���޴��� �� ���� ���
			else if (country[i][1] == country[K][1]) {
				if (country[i][2] > country[K][2])num++;		//���� ������ ���� ���޴��� �� ���� ���
			}
		}
	}
	cout << num << endl;
}