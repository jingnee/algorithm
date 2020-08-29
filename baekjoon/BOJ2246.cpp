/*콘도 선정*/
#include <iostream>
#include <vector>
using namespace std;

int N;
int main() {
	cin >> N;
	vector<pair<int, int>> condo;
	for (int i = 0; i < N; i++) {
		int d, c;
		cin >> d >> c;
		condo.push_back(make_pair(d, c));
	}
	
	int ans = 0;

	for (int i = 0; i < N; i++) {
		bool flag = true;
		for (int j = 0; j < N; j++) {
			if (i != j) {
				if (condo[i].first > condo[j].first) {
					if (condo[i].second >= condo[j].second) {
						flag = false;
						break;
						}
					}
					else if (condo[i].second > condo[j].second) {
						if (condo[i].first >= condo[j].first) {
							flag = false;
							break;
					}
				}
			}
			
		}
		if (flag)ans++;
	}
	cout << ans;
}