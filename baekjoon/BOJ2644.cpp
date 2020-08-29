/*ÃÌ¼ö °è»ê*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> relative[101];
int chon[101];
int n, m, mem1, mem2;

int BFS() {
	queue<int> que;
	que.push(mem1);
	while (!que.empty()) {
		int curmem = que.front();
		que.pop();
		if (curmem == mem2)return chon[curmem];

		for (auto i : relative[curmem]) {
			if (chon[i] == 0) {
				que.push(i);
				chon[i] = chon[curmem] + 1;
			}
		}
	}
	return -1;
}
int main() {
	cin >> n >> mem1 >> mem2 >> m;
	int v1, v2;

	for (int i = 0; i < m; i++) {
		cin >> v1 >> v2;
		relative[v1].push_back(v2);
		relative[v2].push_back(v1);
	}

	cout << BFS() << "\n";
}