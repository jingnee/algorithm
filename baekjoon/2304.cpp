//창고 다각형
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, high, ans;
vector<pair<int, int>> vec;
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		vec.push_back(make_pair(a, b));
		high = (high < b) ? b : high;
	}
	sort(vec.begin(), vec.end());
	int idx = 0;
	int i = 0;
	//중간의 가장 높은 위치 전까지 앞에서부터
	while (vec[i].second < high) {
		if (vec[i].second > vec[idx].second) {
			ans += (vec[i].first - vec[idx].first)*vec[idx].second;
			idx = i;
		}
		i++;
	}
	ans += (vec[i].first - vec[idx].first)*vec[idx].second;
	//i는 제일 높은 위치의 첫번째

	idx = N - 1;
	int j = N - 1;
	//중간의 가장 높은 위치 전까지 뒤에서부터
	while (vec[j].second < high) {
		if (vec[j].second > vec[idx].second) {
			ans += (vec[idx].first - vec[j].first)*vec[idx].second;
			idx = j;
		}
		j--;
	}
	ans += (vec[idx].first - vec[j].first)*vec[idx].second;
	//중간 가장 높은 위치 더하기
	ans += (vec[j].first - vec[i].first + 1)*high;

	cout << ans;
}