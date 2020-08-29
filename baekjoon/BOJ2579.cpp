// 계단 오르기
#include <iostream>
#include <algorithm>
using namespace std;

int stairs[300];
int DP[300];		//DP[n]은 n번째 계단에서의 최댓값

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)cin >> stairs[i];
	//DP초깃값 설정 (0,1은 값 넣어놓고 시작)
	DP[0] = stairs[0];
	DP[1] = stairs[1] + stairs[0];
	//첫번째 계단값이 더 크면 첫번째 계단값을 아니면 두번째 계단값을 더함
	DP[2] = max(stairs[0] + stairs[2], stairs[1] + stairs[2]);

	for (int i = 3; i < N; i++) 
		DP[i] = max(stairs[i - 1] + stairs[i] + DP[i - 3], DP[i - 2] + stairs[i]);
	cout << DP[N - 1] << endl;
}