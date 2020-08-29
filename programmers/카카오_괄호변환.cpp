#include <iostream>
#include <string>
#include <vector>

using namespace std;
//string answer;
bool isRight(string str) {
	int num = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(')num++;
		else num--;
		if (num < 0)return false;
	}
	return true;
}

string solution(string p) {
	if (p == "")return "";
	string u = "";
	string v = "";
	string answer = "";

	int uNum = 0, vNum = 0, index = 0;
	for (auto c : p) {
		if (c == '(')uNum++;
		else vNum++;
		index++;
		if (uNum == vNum)break;
	}
	u += p.substr(0, index);
	v += p.substr(index);
	//올바른 괄호이면
	if (isRight(u)) {
		answer += u;
		answer += solution(v);
	}
	else {
		answer = "(";
		answer += solution(v);
		answer += ")";

		u = u.substr(1, u.size() - 2);
		for (int i = 0; i < u.size(); i++) {
			if (u[i] == '(')answer += ")";
			else answer += "(";
		}
	}

	return answer;
}

int main() {
	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		string s;
		cin >> s;
		cout << test_case << ": " << solution(s) << endl;
	}
}