//에너지 모으기
#include <iostream>
#include <vector>
using namespace std;

int N, ans;

void DFS(int idx, int tot, vector<int> beads) {
	vector<int>vec = beads;
	tot += vec[idx - 1] * vec[idx + 1];
	vec.erase(vec.begin() + idx);

	for (int i = 1; i < vec.size() - 1; i++) {
		DFS(i, tot, vec);
	}
	
	if (vec.size() == 2) {
		ans = (ans < tot) ? tot : ans;
		return;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	vector<int> beads;

	cin >> N;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		beads.push_back(a);
	}

	for (int i = 1; i < beads.size()-1; i++)
	DFS(i, 0, beads);

	cout << ans;
}
