/*연산자 끼워넣기*/
#include<iostream>
using namespace std;

int oper[4];
int num[12];
int N, minNum = 2e9 , maxNum=-2e9;

void DFS(int sum, int idx) {
	if (idx == N) {
		minNum = (minNum > sum) ? sum : minNum;
		maxNum = (maxNum < sum) ? sum : maxNum;
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (oper[i] > 0) {
			oper[i]--;
			if (i == 0)DFS(sum + num[idx], idx + 1);
			else if (i == 1)DFS(sum - num[idx], idx + 1);
			else if (i == 2)DFS(sum*num[idx], idx + 1);
			else DFS(sum / num[idx], idx + 1);
			oper[i]++;
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)cin >> num[i];
	for (int i = 0; i < 4; i++)cin >> oper[i];

	DFS(num[0], 1);
	cout << maxNum << "\n" << minNum << "\n";
}
