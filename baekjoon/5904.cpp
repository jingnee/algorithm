//Moo ����
#include <iostream>
using namespace std;

long long N;

int main() {
	cin >> N;
	long long tot_len = 3;	//������ ��ü ����
	long long mid_len = 4;	//�߰� moo..oo �� ����

	//N��° �ε������ٴ� ������ ������
	while (N > tot_len) {
		tot_len = tot_len * 2 + mid_len;
		mid_len++;
	}
	mid_len--;

	//N��° �ε����� �߰� �߰��� ������ �ִ���, �� �տ� �ִ���, �� �ڿ� �ִ���
	while (1) {
		int prev_len = (tot_len - mid_len) / 2;
		//���� �������� �ȿ� ������ �� ���� ������ �ٽ� ����
		if (N <= prev_len) {
			tot_len = prev_len;
			mid_len--;
		}
		//���������� �߰��� ������ ���� ���������� ������. �װɷ� �ٽ� ����
		else if (N > prev_len + mid_len) {
			N -= (prev_len + mid_len);
			tot_len = prev_len;
			mid_len--;
		}
		//�߰��� ���� �߰��� �����ȿ� �����ϸ� �� ���� �� �־�
		else {
			N -= prev_len;
			break;
		}
	}
	if (N == 1)cout << "m";
	else cout << "o";
}