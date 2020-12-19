//줄 세우기
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, ans;
vector<int> vec;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	vec.push_back(-10);

	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		if (vec.back() < a) {
			ans++;
			vec.push_back(a);
		}
		else {
			auto it = lower_bound(vec.begin(), vec.end(), a);
			*it = a;
		}
	}
	cout << N - ans;
}
