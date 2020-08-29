//[S/W 문제해결 기본] 10일차 - 비밀번호

#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int test_case = 1; test_case <= 10; test_case++) {
		string str;
		int num;
		cin >> num >> str;

		int index = 0;
		for (index; index < str.length()-1; index++) {
			if (str[index] == 'f') index++;

			if (str[index] == str[index + 1]) {
				int prev = index, next = index + 1;
				while ((prev >= 0 && next < str.length()) && (str[prev] == str[next] || str[prev]=='f' || str[next]=='f')) {
					if (str[prev] == 'f') {
						prev--;
						continue;
					}
					if (str[next] == 'f') {
						next++;
						continue;
					}
					str[prev] = str[next] = 'f';
					prev--, next++;
				}
			}
		}
		cout << "#" << test_case << " ";
		for (int i = 0; i < str.length(); i++) {
			if (str[i] != 'f')cout << str[i];
		}
		cout << "\n";
	}
}
