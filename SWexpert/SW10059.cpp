/*유효기간*/
#include <iostream>
#include <string>
using namespace std;

int T;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	string date;
	for (int test_case = 1; test_case <= T; test_case++) {
		cin >> date;
		int front = (date[0] - '0') * 10 + (date[1] - '0');
		int back = (date[2] - '0') * 10 + (date[3] - '0');
		if (front <= 12 && front >= 1) {
			if (back <= 12 && back >= 1)cout << "#" << test_case << " AMBIGUOUS\n";
			else cout << "#" << test_case << " MMYY\n";
		}
		else {
			if (back <= 12 && back >= 1)cout << "#" << test_case << " YYMM\n";
			else cout << "#" << test_case << " NA\n";
		}
	}
}
