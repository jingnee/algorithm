/*문자열 잘라내기*/
#include <iostream>
#include <string>
#include <set>
using namespace std;

int R, C, answer;
char strs[1000][1001];

//index위치에서부터 문자열 구했을때 중복되는 값이 있는지 조사
bool check(int index) {
	set<string> s;
	for (int j = 0; j < C; j++) {
		string str = "";
		for (int i = index; i < R; i++) {
			str += strs[i][j];
		}
		if (s.find(str) == s.end())s.insert(str);
		else return false;
	}
	return true;
}

void binary(int start, int end) {
	if (start > end)return;

	int mid = (start + end) / 2;

	//동일한 부분이 발견되지 않음 -> 더 아래에 있는 행까지 조사해도 돼
	if (check(mid)) {
		if (answer < mid)answer = mid;
		binary(mid + 1, end);
	}
	else binary(start, mid - 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> R >> C;
	for (int i = 0; i < R; i++)cin >> strs[i];

	binary(0, R - 1);
	cout << answer << "\n";
}
