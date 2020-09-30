//에너지 모으기
#include <iostream>
#include <vector>
using namespace std;

int N, ans;
vector<int> beads;

//void DFS(int tot, vector<int> beads) {
//	if (beads.size() == 2) {
//		ans = (ans < tot) ? tot : ans;
//		return;
//	}
//
//	for (int i = 1; i < beads.size() - 1; i++) {
//		vector<int>vec = beads;
//
//		int temp = vec[i - 1] * vec[i + 1];
//		vec.erase(vec.begin() + i);
//		DFS(tot+temp, vec);
//	}
//	
//}

void DFS(int size, int tot) {
	if (size == 2) {
		ans = (ans < tot) ? tot : ans;
		return;
	}

	for (int i = 1; i < size - 1; i++) {
		int num = beads[i];
		int temp = beads[i - 1] * beads[i + 1];
		beads.erase(beads.begin() + i);
		DFS(size-1, tot + temp);
		beads.insert(beads.begin() + i, num);
	}

}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		beads.push_back(a);
	}

	//DFS(0, beads);
	DFS(beads.size(), 0);

	cout << ans;
}
