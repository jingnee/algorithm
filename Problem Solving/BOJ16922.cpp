#include <iostream>
using namespace std;

bool Sum[1001];		//���� �� �ִ� �ִ� = 50*20 = 1000 �迭�ε����� 0����
int Roma[4] = { 1,5,10,50 };
int result, N;
void Homogeneous(int index, int sum, int cnt) {		//�ߺ������� H=Homogeneous
	if (cnt == N) {
		if (Sum[sum] == false) {
			Sum[sum] = true;
			result++;
		}
		return;
	}
	for (int i = index; i < 4; i++)
		Homogeneous(i, sum + Roma[i], cnt + 1);
}
int main() {
	cin >> N;
	Homogeneous(0, 0, 0);
	cout << result << endl;
}
/*
	�̹����� �ߺ� �������� Ǫ�� �������� �ߺ������� ���� ������ �ʴ� ����!
	�ܼ��� �����ϴ°��̾ƴ϶� "���յ� ��"���� �Ǵ��ϴ� �����̱� ����
	������ N�� 6�ΰ�� {1,1,1,1,1,50}�� {10,10,10,10,10,5}�� ��� ������ �޶� 55�� ���� ���⶧����
	�ߺ����հ�����δ� �ΰ��� ġ���� �� ���������� �ϳ��� ģ��.
*/