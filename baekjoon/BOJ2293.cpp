/*동전 -- Dynamic programming*/
#include <iostream>
using namespace std;

int coin[100];
int DP[10001];				//10000원의 인덱스는 10000이므로
int n, k;
//f(n,k) = f(n-1,k) + f(n,k-coin(k))
//			n번째 동전 안쓰고 k원 만들기 + n번째 동전 1개 이상 쓰고 k원 만들기(=> n번째 동전은 한개를 꼭 써야한다는 뜻이니까, n개의 동전을 가지고 n동전을 뺀만큼을 구하는거야)
int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++)cin >> coin[i];
	
	DP[0] = 1;
	for (int i = 0; i < n; i++) {		//coin 갯수만큼 진행
		for (int j = coin[i]; j <= k; j++) {
			DP[j] += DP[j - coin[i]];
		}
	}
	cout << DP[k] << endl;
}