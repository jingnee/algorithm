/*숨바꼭질*/
#include <iostream>
#include <queue>
using namespace std;

int N, K;
bool visit[100001];
queue<pair<int,int>> que;


int main() {
	cin >> N >> K;
	que.push(make_pair(N,0));

	while (!que.empty()) {
		pair<int, int>temp = que.front();
		que.pop();

		if (temp.first == K) {
			cout << temp.second << "\n";
			return 0;
		}

		if (temp.first > 0 && !visit[temp.first-1]) {
			visit[temp.first - 1] = true;
			que.push(make_pair(temp.first - 1, temp.second + 1));
		}
		if (temp.first < 100000 && !visit[temp.first + 1]) {
			visit[temp.first + 1] = true;
			que.push(make_pair(temp.first + 1, temp.second + 1));
		}
		if (temp.first * 2 <= 100000 && !visit[2 * temp.first]) {
			visit[temp.first * 2] = true;
			que.push(make_pair(temp.first * 2, temp.second + 1));
		}
	}
	
}
