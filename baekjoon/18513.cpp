//샘터
#include<iostream>
#include <map>
#include<queue>
using namespace std;
#define mini -100000000
#define maxi 100000000

int N, K;
long long answer;
map<int,bool> isHave;
queue<pair<int, int>> que;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		int s;
		cin >> s;
		isHave[s] = true;
		//s위치는 가장가까운 샘이랑 0차이
		que.push(make_pair(s, 0));
	}

	while (!que.empty()) {
		int now = que.front().first;
		int dist = que.front().second;
		que.pop();
		if (now - 1 >= mini && !isHave[now - 1]) {
			isHave[now - 1] = true;
			K--;
			answer += dist + 1;
			que.push(make_pair(now - 1, dist + 1));
			if (K == 0)break;
		}
		if (now + 1 <= maxi && !isHave[now + 1]) {
			isHave[now + 1] = true;
			K--;
			answer += dist + 1;
			que.push(make_pair(now + 1, dist + 1));
			if (K == 0)break;
		}
	}
	cout << answer;
}
