// ��� ������
#include <iostream>
#include <algorithm>
using namespace std;

int stairs[300];
int DP[300];		//DP[n]�� n��° ��ܿ����� �ִ�

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)cin >> stairs[i];
	//DP�ʱ갪 ���� (0,1�� �� �־���� ����)
	DP[0] = stairs[0];
	DP[1] = stairs[1] + stairs[0];
	//ù��° ��ܰ��� �� ũ�� ù��° ��ܰ��� �ƴϸ� �ι�° ��ܰ��� ����
	DP[2] = max(stairs[0] + stairs[2], stairs[1] + stairs[2]);

	for (int i = 3; i < N; i++) 
		DP[i] = max(stairs[i - 1] + stairs[i] + DP[i - 3], DP[i - 2] + stairs[i]);
	cout << DP[N - 1] << endl;
}