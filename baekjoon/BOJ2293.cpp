/*���� -- Dynamic programming*/
#include <iostream>
using namespace std;

int coin[100];
int DP[10001];				//10000���� �ε����� 10000�̹Ƿ�
int n, k;
//f(n,k) = f(n-1,k) + f(n,k-coin(k))
//			n��° ���� �Ⱦ��� k�� ����� + n��° ���� 1�� �̻� ���� k�� �����(=> n��° ������ �Ѱ��� �� ����Ѵٴ� ���̴ϱ�, n���� ������ ������ n������ ����ŭ�� ���ϴ°ž�)
int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++)cin >> coin[i];
	
	DP[0] = 1;
	for (int i = 0; i < n; i++) {		//coin ������ŭ ����
		for (int j = coin[i]; j <= k; j++) {
			DP[j] += DP[j - coin[i]];
		}
	}
	cout << DP[k] << endl;
}