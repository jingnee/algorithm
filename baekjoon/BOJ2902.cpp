/*KMP는 왜 KMP일까?*/
#include <iostream>
#include <string>
using namespace std;

string str;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> str;
	for (int i = 0; i < str.length(); i++) {
		if (i == 0)cout << str[i];
		else if (str[i] == '-')cout << str[i + 1];
	}
}
