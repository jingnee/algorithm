/*괄호 제거*/
#include <iostream>
#include <string>
#include <stack>
#include <set>
using namespace std;

string input;
stack<int> st;
int bracket[201];
bool erasing[201];
set<string> s;

void DFS(int idx, string str) {
	if (idx == input.size()) {
		s.insert(str);
		return;
	}

	if (input[idx] == '(') {
		erasing[bracket[idx]] = true;
		DFS(idx + 1, str);
		erasing[bracket[idx]] = false;
		DFS(idx + 1, str + input[idx]);
	}
	else if (input[idx] == ')' && erasing[idx]) {
		DFS(idx + 1, str);
	}
	else DFS(idx + 1, str+input[idx]);
}

//짝 설정
void matchBracket() {
	for (int i = 0; i < input.size(); i++) {
		if (input[i] == '(')st.push(i);
		else if (input[i] == ')') {
			int num = st.top();
			bracket[num] = i;
			bracket[i] = st.top();
			st.pop();
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> input;
	matchBracket();
	DFS(0, "");
	s.erase(input);
	for (auto a : s)cout << a << "\n";
}
