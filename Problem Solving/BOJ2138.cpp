// ���� ����ġ
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

#define INF 999999999
int answer, N;
string light, cur, result;

void push(int idx) {							//���� ������ �Լ�
	if (idx > 0)
		cur[idx - 1] = (cur[idx - 1] == '0') ? '1' : '0';
	cur[idx] = (cur[idx] == '0') ? '1' : '0';
	if (idx < N - 1)
		cur[idx + 1] = (cur[idx + 1] == '0') ? '1' : '0';
}

void simulate(int idx, int cnt) {				//int->void�� ���� (��Ÿ�ӿ���) return���� �ִ� �Լ��� �����س��� ����ο��� ���� ��ȯ��������. ���޼����� �������� ����!
	if (idx == N - 1) {
		if (cur[idx - 1] == result[idx - 1]) {
			if (cur[idx] == result[idx])
				answer = min(answer, cnt);
		}
		else {
			push(idx);
			if (cur[idx] == result[idx])
				answer = min(answer, cnt + 1);
		}
		return;
	}

	if (cur[idx - 1] == result[idx - 1])		//���� �ε��� ������ �������� ������ ���� �������ʰ� �ε��� �̵�
		simulate(idx + 1, cnt);
	else {
		push(idx);								//���� �ε��� ������ �������� �ٸ��� �����ε������� ������ ��������Ѵ�.(���� �ε����� �Ѿ������ ������������ ������ �� �����ϱ�)
		simulate(idx + 1, cnt + 1);
	}
}

int main() {
	cin >> N;
	cin >> light >> result;
	cur = light;

	answer = INF;
	simulate(1, 0);					//ù��° ���� �ȴ����� ����
	cur = light;					//���� �ʱ�ȭ
	push(0);						//ù��° ���� ����
	simulate(1, 1);

	if(answer == INF) cout << "-1" << endl;	//������ ã�� ���Ѱ�� -1���
	else cout << answer << endl;
	return 0;
}
