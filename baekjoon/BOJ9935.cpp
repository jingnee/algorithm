/*문자열 폭발*/
#include <iostream>
#include <string>
using namespace std;

string str, bomb;
char answer[1000001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> str >> bomb;
	int index = 0;
	int bomb_len = bomb.length() - 1;

	for (int i = 0; i < str.length(); i++) {
		answer[index++] = str[i];

		//bomb의 맨 끝 글자와 같으면
		if (str[i] == bomb[bomb_len] && index > bomb_len) {
			bool flag = true;
			for (int j = 0; j <= bomb_len; j++) {
				if (answer[index - 1 - j] != bomb[bomb_len-j]) {
					flag = false;
					break;
				}
			}
			if (flag)index -= (bomb_len+1);
		}
	}

	if (index == 0)cout << "FRULA\n";
	else 
		for (int i = 0; i < index; i++)cout << answer[i];
}
