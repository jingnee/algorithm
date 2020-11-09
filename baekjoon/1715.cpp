//카드 정렬하기
#include <iostream>
#include <queue>
using namespace std;

int N, ans;
priority_queue<int>que;
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		que.push(-a);
	}

	if (N == 1) {
		cout << "0";
		return 0;
	}

	while (!que.empty()) {
		int first = que.top();
		que.pop();

		if (ans == 0 || !que.empty()) {
			int second = que.top();
			que.pop();
			ans += (-first + -second);
			que.push(first+second);
		}
	}
	cout << ans;
}
