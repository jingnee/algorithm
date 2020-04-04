/*큰 수 구성하기*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int num;
int answer;
int N;
int K[3];

void DFS(int nowNum) {
	if (nowNum > num)return;

	answer = (answer < nowNum) ? nowNum : answer;

	for (int i = N-1; i >= 0; i--) {
		DFS(nowNum * 10 + K[i]);
	}
}

int main() {
	cin >> num >> N;
	for (int i = 0; i < N; i++)cin >> K[i];
	sort(K, K + N);

	DFS(0);

	cout << answer << "\n";
}
