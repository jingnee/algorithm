//안정적인 문자열
#include<iostream>
#include<string>
using namespace std;

string str;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int num = 1;
	while (1) {
		int ans = 0;
		cin >> str;
		if (str[0] == '-')break;
		int l_num = 0; int r_num = 0;
		for (auto s : str) {
			if (s == '{')l_num++;
			else r_num++;

			if (r_num > l_num) {
				l_num++;
				r_num--;
				ans++;
			}
			else if (l_num > str.size() / 2) {
				l_num--;
				r_num++;
				ans++;
			}
		}
		cout << num++ << ". " << ans << "\n";
	}
}