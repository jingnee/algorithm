/*고득점*/
#include <iostream>
#include <string>
using namespace std;

string str;
int answer = 0;

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> str;
		answer = 0;
		int pos = 2e9;
		//알파벳 변경 갯수
		for (int i = 0; i < str.size(); i++) {
			if (str[i] <= 'N')answer += str[i] - 'A';
			else answer += 'Z' - str[i] + 1;
		}
		//위치 변경 갯수
		for (int i = 0, j; i < str.size(); i++) {
			//i+1위치에서부터 어디까지 연속으로 A가 있는지(연속으로 A가 있다면 그부분은 이동하지 않아도 될 수도 있음)
			for (j = i + 1; j < str.size() && str[j] == 'A'; j++);
			//앞부분을 두번
			int a = i * 2 + str.size() - j;
			//뒷부분을 두번
			int b = i + (str.size() - j) * 2;
			int p = (a > b) ? b : a;
			pos = (pos > p) ? p : pos;
		}
		cout << answer + pos << "\n";
	}
}