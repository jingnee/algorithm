/*산업 스파이*/
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int c, answer;
string str;
bool visit[10000000];
bool isComposite[10000000];
bool num[7];

//초깃값이 0이므로, false로 되어있음 따라서 값이 false이면 소수, true이면 소수가 아님
void makePrime() {
	for (int i = 2; i*i < 10000000; i++) {
		if (!isComposite[i]) {
			for (int j = i*i; j < 10000000; j += i) {
				isComposite[j] = true;
			}
		}
	}
}

int makeNum(string number) {
	int ans = 0;
	int mul = 1;
	int size = number.length();
	for (int i = size-1; i >= 0; i--) {
		ans += mul*(number[i] - '0');
		mul *= 10;
	}
	return ans;
}

void DFS(int cnt, int n, int size, string ss) {
	if (cnt == n) {
		int number = makeNum(ss);
		if (!visit[number] && !isComposite[number]) {
			visit[number] = true;
			answer++;
		}
		return;
	}
	for (int i = 0; i < size; i++) {
		if (!num[i]) {
			num[i] = true;
			DFS(cnt + 1, n, size, ss + str[i]);
			num[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	makePrime();
	isComposite[0] = isComposite[1] = true;

	cin >> c;
	for (int t = 0; t < c; t++) {
		cin >> str;
		//for (int i = 0; i < str.length(); i++)num[i] = str[i] - '0';
		int size = str.length();
		for (int i = 1; i <= size; i++) {
			DFS(0, i, size, "");
		}
		cout << answer << "\n";
		answer = 0;
		memset(visit, false, sizeof(visit));
	}
}
