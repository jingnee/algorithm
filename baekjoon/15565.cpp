//귀여운 라이언
#include <iostream>
#include <vector>
using namespace std;

int N, K;
int ans = 1e9;
vector<int> vec;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		if (n == 1) vec.push_back(i);
	}
	
	if (vec.size() < K) {
		cout << "-1";
		return 0;
	}
	else {
		for (int i = K-1; i < vec.size(); i++) {
			if (vec[i] - vec[i-K + 1] + 1 < ans)ans = vec[i] - vec[i-K + 1] + 1;
		}
	}
	cout << ans;
}
