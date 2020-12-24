//â�� �ٰ���
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
	//�߰��� ���� ���� ��ġ ������ �տ�������
	while (vec[i].second < high) {
		if (vec[i].second > vec[idx].second) {
			ans += (vec[i].first - vec[idx].first)*vec[idx].second;
			idx = i;
		}
		i++;
	}
	ans += (vec[i].first - vec[idx].first)*vec[idx].second;
	//i�� ���� ���� ��ġ�� ù��°

	idx = N - 1;
	int j = N - 1;
	//�߰��� ���� ���� ��ġ ������ �ڿ�������
	while (vec[j].second < high) {
		if (vec[j].second > vec[idx].second) {
			ans += (vec[idx].first - vec[j].first)*vec[idx].second;
			idx = j;
		}
		j--;
	}
	ans += (vec[idx].first - vec[j].first)*vec[idx].second;
	//�߰� ���� ���� ��ġ ���ϱ�
	ans += (vec[j].first - vec[i].first + 1)*high;

	cout << ans;
}