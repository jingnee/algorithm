//잃어버린 괄호
#include <iostream>
#include <string>
using namespace std;

string str;
int num[25];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> str;
	int prev = 0;
	int idx = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '+') {
			string sub = str.substr(prev, i-prev);
			prev = i + 1;
			int len = sub.size();
			int n = 0;
			int ten = 1;
			while (--len >= 0) {
				n += (sub[len] - '0')*ten;
				ten *= 10;
			}
			num[idx] += n;
		}
		else if (str[i] == '-') {
			string sub = str.substr(prev, i - prev);
			prev = i + 1;
			int len = sub.size();
			int n = 0;
			int ten = 1;
			while (--len >= 0) {
				n += (sub[len] - '0')*ten;
				ten *= 10;
			}
				num[idx++] += n;
		}
	}
	string sub = str.substr(prev, str.size() - prev);
	int len = sub.size();
	int n = 0;
	int ten = 1;
	while (--len >= 0) {
		n += (sub[len] - '0')*ten;
		ten *= 10;
	}
	num[idx] += n;

	int answer = num[0];
	for (int i = 1; i <= idx; i++)answer -= num[i];
	cout << answer;
}
