/*괄호의 값
stack 이용*/
#include <iostream>
#include <stack>
#include <string>
using namespace std;

stack<char> st;
int sum = 0;

int main() {
	string str;
	cin >> str;
	int temp = 1;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(') {
			st.push(str[i]);
			temp *= 2;
		}
		else if (str[i] == '[') {
			st.push(str[i]);
			temp *= 3;
		}
		else if (str[i] == ')') {
			if (st.empty() || st.top()=='[') {
				cout << "0";
				return 0;
			}
			if (str[i - 1] == '(')	sum += temp;
			temp /= 2;
			st.pop();
		}
		else if (str[i]==']') {
			if (st.empty() || st.top() == '(') {
				cout << "0";
				return 0;
			}
			if (str[i - 1] == '[')sum += temp;
			temp /= 3;
			st.pop();
		}
	}

	if (!st.empty())
		cout << "0";
	else
		cout << sum << "\n";
	return 0;
}