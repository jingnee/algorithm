//최대 힙
#include <iostream>
#include <queue>
using namespace std;

int N;
priority_queue<int> que;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	while (N--) {
		int a;
		cin >> a;
		if (a > 0) {
			que.push(a);
		}
		else {
			if (que.empty())cout << "0\n";
			else {
				cout << que.top() << "\n";
				que.pop();
			}
		}
	}
}
