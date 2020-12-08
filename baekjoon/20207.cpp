//달력
#include<iostream>
using namespace std;

int calendar[366];
int N, answer;
int start = 366, endd;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int s, e;
		cin >> s >> e;
		for (int j = s; j <= e; j++)calendar[j]++;
		start = (start > s) ? s : start;
		endd = (endd < e) ? e : endd;
	}

	int maxi = 0;
	int prev = start;

	for (int i = start; i <= endd + 1; i++) {
		if (calendar[i] == 0) {
			answer += (i - prev)*maxi;
			maxi = 0;
			prev = i + 1;
			continue;
		}
		maxi = (maxi < calendar[i]) ? calendar[i] : maxi;
	}
	cout << answer;
}
