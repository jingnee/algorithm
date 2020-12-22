//회전하는 큐
#include <iostream>
#include <deque>
using namespace std;

int N, M, ans;
deque<int> dq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 1; i <= N; i++)dq.push_back(i);
	for (int i = 0; i < M; i++) {
		int a, idx = 0;
		cin >> a;
		for (int j = 0; j < dq.size(); j++) {
			if (dq[j] == a) {
				idx = j;
				break;
			}
		}
		//왼쪽이동이 더 빨라
		if (idx <= dq.size() - idx) {
			while (dq[0] != a) {
				dq.push_back(dq.front());
				dq.pop_front();
				ans++;
			}
			dq.pop_front();
		}
		else {
			while (dq[0] != a) {
				dq.push_front(dq.back());
				dq.pop_back();
				ans++;
			}
			dq.pop_front();
		}
	}
	cout << ans;
}

// #include <stdio.h> int main() { int n, m, s, c=1, t, ans=0; static char v[52]; scanf("%d%d",&n,&m); for(int r=0;r<m;r++) { scanf("%d",&s); for(t=0;c!=s;c=c%n+1) t+=v[c]==0; ans += (t<n-r-t)?t:n-r-t; v[c]=1; } printf("%d\n", ans); }

