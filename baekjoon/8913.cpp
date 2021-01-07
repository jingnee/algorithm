//문자열 뽑기
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int N;
bool flag;
unordered_map<string, bool> isCheck;
unordered_map<string, bool> isTrue;

void DFS(string str) {
	if (str.size() == 0) {
		flag = true;
		return;
	}

	for (int i = 0; i < str.size()-1; i++)
	{
		if (str[i] == str[i + 1]) {
			string s = "";
			int j = i;
			while (str[j] == str[i])j++;
			if (i > 0)s += str.substr(0, i);
			if (j < str.size())s += str.substr(j);
			//이미 찾아보지 않은 문자열에 대해서만 조사
			if (!isCheck[s]) {
				isCheck[s] = true;
				DFS(s);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		auto it = isTrue.find(str);
		//해당 문자열이 존재하지 않는다면
		if (it == isTrue.end()) {
			DFS(str);
			isTrue[str] = flag;
		}
		cout << isTrue[str] << "\n";
		isCheck.clear();
		flag = false;
	}
}