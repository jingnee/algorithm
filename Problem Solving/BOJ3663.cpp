/*�����*/
#include <iostream>
#include <string>
using namespace std;

string str;
int answer = 0;

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> str;
		answer = 0;
		int pos = 2e9;
		//���ĺ� ���� ����
		for (int i = 0; i < str.size(); i++) {
			if (str[i] <= 'N')answer += str[i] - 'A';
			else answer += 'Z' - str[i] + 1;
		}
		//��ġ ���� ����
		for (int i = 0, j; i < str.size(); i++) {
			//i+1��ġ�������� ������ �������� A�� �ִ���(�������� A�� �ִٸ� �׺κ��� �̵����� �ʾƵ� �� ���� ����)
			for (j = i + 1; j < str.size() && str[j] == 'A'; j++);
			//�պκ��� �ι�
			int a = i * 2 + str.size() - j;
			//�޺κ��� �ι�
			int b = i + (str.size() - j) * 2;
			int p = (a > b) ? b : a;
			pos = (pos > p) ? p : pos;
		}
		cout << answer + pos << "\n";
	}
}