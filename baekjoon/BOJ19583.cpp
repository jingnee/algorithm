/*싸이버 개강총회*/
#include <iostream>
#include <string>
#include <map>
#include <queue>
using namespace std;

int ans;
string S, E, Q;
map<string,int> inClass;
map<string,int> outClass;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> S >> E >> Q;
	while (1) {
		string time, name;
		cin >> time >> name;
		if (time <= S)inClass[name]++;
		else if (time >= E && time <= Q)outClass[name]++;
		if (time == "")break;
	}
	queue<string>que;
	for (auto m : outClass)que.push(m.first);
	for (auto m : inClass) {
		while (!que.empty()) {
			if (que.front() < m.first)que.pop();
			else if (que.front() == m.first) {
				ans++;
				break;
			}
			else break;
		}
	}
	cout << ans << "\n";
}
