//���װ��2 nCk = n-1Ck + n-1Ck-1
//10007�� ������
#include<iostream>
using namespace std;

int N, K;
int check[1000][1000];

int binomi(int n, int k) {
	if (check[n][k] != 0)return check[n][k];

	if (k == 0 || n == k)return check[n][k] = 1;
	else if (k == 1)return check[n][k] = n;

	return check[n][k] = (binomi(n - 1, k) + binomi(n - 1, k - 1)) % 10007;
}
int main() {
	cin >> N >> K;
	cout << binomi(N, K);
}