//�Ľ�Į�� �ﰢ��
/*
���� �Ʒ� ���ﰢ���� ���� ��´�.
pascal[n][r] = pascal[n-1][r-1] + pascal[n-1][r]
�Ľ�Į�ﰢ������ n��°�� k��°���� n-1Ck-1�� ����. �� pascal[n-1][k-1]
*/
#include<iostream>
using namespace std;

int pascal[31][31];
int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i <= n; i++)pascal[i][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k&&j <= i; j++)
			pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
	}
	cout << pascal[n - 1][k - 1];
}