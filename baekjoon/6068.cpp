//시간 관리하기
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<int, int>> vec;
int N, answer;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		vec.push_back(make_pair(b, a));
	}
	sort(vec.begin(), vec.end());
	
	int answer = 0;
	int lastTime = vec[N - 1].first;

	for (int i = N-1; i >= 0; i--) {
		lastTime = min(lastTime, vec[i].first);
		if (lastTime < vec[i].second) {
			cout << "-1\n";
			return 0;
		}
		lastTime -= vec[i].second;
	}
	cout << lastTime;
}
