/*스카이라인 쉬운거*/
#include <iostream>
#include <stack>
using namespace std;

int n, ans;
int height[500001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x >> height[i];
	}

	stack<int> s;
	for (int i = 0; i <= n; i++) {
		while (!s.empty() && s.top() > height[i]) {
			ans++;
			s.pop();
		}
		if (!s.empty() && s.top() == height[i])continue;
		s.push(height[i]);
	}
	cout << ans << "\n";
}
