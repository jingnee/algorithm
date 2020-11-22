//오름세
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
int ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	do {
		ans = 0;
		int a;
		vector<int>vt;
		vt.push_back(-10);

		while (N-- > 0) {
			cin >> a;
			if (vt.back() < a) {
				vt.push_back(a);
				ans++;
			}
			else {
				auto it = lower_bound(vt.begin(), vt.end(), a);
				*it = a;
			}
		}
		cout << ans << "\n";

	} while (cin>>N);

}
