/*원재의 메모리 복구하기*/
#include <iostream>
#include <string>
using namespace std;

string str;

int fix() {
	int cnt = 0;
	char now_num = '0';
	for (int i = 0; i < str.length(); i++) {
		if (now_num != str[i]) {
			cnt++;
			if (now_num == '1')now_num = '0';
			else now_num = '1';
		}
	}
	return cnt;
}

int main() {
	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		cin >> str;
		cout << "#" << test_case << " " << fix() << "\n";
	}
}
