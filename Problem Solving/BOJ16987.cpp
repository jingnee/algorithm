/*������� ���ġ��*/
#include<iostream>
using namespace std;

int N;
int eggs[8][2];
int maxx;

void smashEgg(int eggNum) {
	if (eggNum == N) {
		int broken = 0;
		for (int i = 0; i < N; i++)	if (eggs[i][0] <= 0) broken++;
		maxx = (maxx < broken) ? broken : maxx;
		return;
	}
	if (eggs[eggNum][0] <= 0)smashEgg(eggNum + 1);
	else {
		//�����Ǵ� �����༭ ��� Ʋ�� �̤�
		bool flag = false;					//�����ƴ��� ���ƴ��� Ȯ��
		for (int i = 0; i < N; i++) {
			if (i != eggNum && eggs[i][0] > 0) {			//�տ� ��� �ִ� ����̶� �ٸ� ����̰�, ������ ����� �̹� ������ �ʾ��� ���
				eggs[eggNum][0] -= eggs[i][1];
				eggs[i][0] -= eggs[eggNum][1];
				flag = true;
				smashEgg(eggNum + 1);

				eggs[eggNum][0] += eggs[i][1];
				eggs[i][0] += eggs[eggNum][1];
			}
		}
		if (flag == false)smashEgg(N);			//����ĥ�� ������ ���� ������ε� ����ĥ�� �����Ƿ� ��

	}

}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> eggs[i][0] >> eggs[i][1];
	}
	smashEgg(0);
	cout << maxx << endl;
}