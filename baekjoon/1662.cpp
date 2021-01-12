//æ–√‡
#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

struct number {
	int num, len;
};
string str;
stack<number> numbers;
int ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> str;
	int cur_len = 0;
	for (int i = 0; i<str.size(); i++) {
		if (str[i] == '(') {
			int multi = str[i - 1] - '0';
			numbers.push({multi,cur_len-1});
			cur_len = 0;
		}
		else if (str[i] == ')') {
			number temp = numbers.top();
			numbers.pop();
			cur_len = temp.num*cur_len + temp.len;
		}
		else
			cur_len++;
	}

	cout << cur_len;
}