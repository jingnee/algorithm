/*팀배분*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> teamBlue;
vector<int> teamWhite;
vector<int> hate[101];
bool visit[101];
queue<int> que;
int N;
int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int cnt = 0;
		cin >> cnt;
		for (int j = 0; j < cnt; j++) {
			int num;
			cin >> num;
			hate[i].push_back(num);
		}
	}
	
	for (int i = 1; i <= N; i++) {
		bool flag = true;
		if (!visit[i]) {
			visit[i] = true;
			que.push(i);
			teamBlue.push_back(i);
		}

		while (!que.empty()) {
			int size = que.size();
			flag = !flag;
			while (size--) {
				int n = que.front();
				que.pop();
				for (auto i : hate[n]) {
					if (visit[i])continue;
					visit[i] = true;
					que.push(i);
					if (flag)teamBlue.push_back(i);
					else teamWhite.push_back(i);
				}
			}
		}
	}

	sort(teamBlue.begin(), teamBlue.end());
	sort(teamWhite.begin(), teamWhite.end());

	cout << teamBlue.size() << "\n";
	for (auto i : teamBlue)cout << i << " ";
	cout << "\n";
	cout << teamWhite.size() << "\n";
	for (auto i : teamWhite)cout << i << " ";
	cout << "\n";
}
