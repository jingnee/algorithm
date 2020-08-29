/*암호 만들기*/
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

int L, C;
char str[16];
char answer[16];
//bool alpha[16];
map<char, int> alpha;

bool check() {
	int mNum = 0, jNum = 0;
	for (int i = 0; i < L; i++) {
		if (answer[i] == 'a' || answer[i] == 'i' || answer[i] == 'e' || answer[i] == 'o' || answer[i] == 'u')mNum++;
		else jNum++;
	}
	if (mNum >= 1 && jNum >= 2)return true;
	else return false;
}

void DFS(int cnt, int index) {
	if (cnt == L) {
		if (check()) {
			for (int i = 0; i < L; i++)cout << answer[i];
			cout << "\n";
		}
		return;
	}

	for (int i = index; i < C; i++) {
		if (alpha[str[i]]==1)continue;
		alpha[str[i]] = 1;
		answer[cnt] = str[i];
		DFS(cnt + 1, i);
		alpha[str[i]] = 0;
	}
}

int main() {
	cin >> L >> C;
	for (int i = 0; i < C; i++)cin >> str[i];
	sort(str, str + C);

	DFS(0, 0);
}
