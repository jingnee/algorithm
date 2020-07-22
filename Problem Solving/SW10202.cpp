/*문자열 동화*/
#include <iostream>
#include <string>
using namespace std;

int T, n, ans;
string str[3];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		cin >> n;
		for (int i = 0; i < 3; i++)cin >> str[i];
		for (int i = 0; i < n; i++) {
			if (str[0][i] == str[1][i]) {
				//한개만 다름
				if (str[2][i] != str[0][i])ans++;
				else continue;
			}
			else if (str[1][i] == str[2][i]) {
				//한개만 다름
				if (str[0][i] != str[1][i])ans++;
				else continue;
			}
			else if (str[2][i] == str[0][i]) {
				if (str[1][i] != str[2][i])ans++;
				else continue;
			}
			else ans += 2;
		}
		cout << "#" << test_case << " " << ans << "\n";
		ans = 0;
	}
}
