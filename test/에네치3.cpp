#include <iostream>
#include <string>
#include <stack>
#include <sstream>

using namespace std;

void solution(int numOfOrder, string *orderArr) {
	for (int ord = 0; ord < numOfOrder; ord++) {
		stack<char>st;
		string ans="";
		int ssize = orderArr[ord].size();
		bool flag = false;

		for (int i = 0; i < ssize; i++) {
			if (orderArr[ord][i] != ')' && !flag) {
				st.push(orderArr[ord][i]);
				if ((orderArr[ord][i] >= '1' && orderArr[ord][i] <= '9') && orderArr[ord][i + 1] != '(') {
					st.push('(');
					st.push(orderArr[ord][i + 1]);
					//i++;
					flag = true;
				}
			}
			else if (flag || orderArr[ord][i] == ')') {
				string temp = "";
				while (st.top() != '(') {
					temp += st.top();
					st.pop();
				}
				//( 제거
				st.pop();

				reverse(temp.begin(), temp.end());
				char c = st.top();
				st.pop();

				//앞에가 숫자면
				if (c >= '1' && c <= '9') {
					int num = c - '0';
					for (int n = 0; n < num; n++) {
						for (auto t : temp)st.push(t);
					}
				}
				//앞에가 문자면
				else {
					for (auto t : temp) {
						st.push(c);
						st.push(t);
					}
				}
				flag = false;
			}
		}
		while (!st.empty()) {
			ans += st.top();
			st.pop();
		}
		reverse(ans.begin(), ans.end());
		cout << ans << "\n";
	}
}

string order[1] = { "1B2R3G" };
int main() {
	solution(1, order);
}
