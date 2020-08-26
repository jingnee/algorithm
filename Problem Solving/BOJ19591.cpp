/*독특한 계산기*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<char> oper;
vector<long long> numbers;
string str;

int priority(char c) {
	if (c == '+' || c == '-')return 1;
	else return 2;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> str;
	string str2 = str;
	int s = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] < '0' && i != 0) {
			oper.push_back(str[i]);
			numbers.push_back(stoll(str.substr(s, i - s)));
			s = i + 1;
		}
		if (i == str.size() - 1) numbers.push_back(stoll(str.substr(s)));
	}

	int sn = 0;
	int en = numbers.size()-1;
	if (oper.size() == 0) {
		cout << numbers[0];
		return 0;
	}

	while (1) {
		int fo = priority(oper[sn]);
		int eo = priority(oper[en - 1]);
		//우선순위가 뒤에가 더큼
		if (fo < eo) {
			long long num = numbers[en-1];
			if (oper[en-1] == '*')num *= numbers[en];
			else if (oper[en-1] == '/')num /= numbers[en];
			//numbers.erase(numbers.begin()+en);
			en--;
			numbers[en] = num;
			if (en == sn) {
				cout << num;
				return 0;
			}
		}
		//우선순위가 같음
		else if (fo == eo) {
			long long firstNum = numbers[sn];
			long long lastNum = numbers[en-1];
			//연산자가 덧셈, 뺄셈
			if (fo == 1) {
				if (oper[sn] == '+')firstNum += numbers[sn + 1];
				else if (oper[sn] == '-')firstNum -= numbers[sn + 1];

				if (oper[en-1] == '+')lastNum += numbers[en];
				else if (oper[en-1] == '-')lastNum -= numbers[en];

				if (firstNum < lastNum) {
					en--;
					numbers[en] = lastNum;
					if (en == sn) {
						cout << lastNum;
						return 0;
					}
				}
				else {
					sn++;
					numbers[sn] = firstNum;
					if (sn == en) {
						cout << firstNum;
						return 0;
					}
				}
			}
			//연산자가 곱셈 나눗셈
			else {
				if (oper[sn] == '*')firstNum *= numbers[sn + 1];
				else if (oper[sn] == '/')firstNum /= numbers[sn + 1];

				if (oper[en-1] == '*')lastNum *= numbers[en];
				else if (oper[en-1] == '/')lastNum /= numbers[en];

				if (firstNum < lastNum) {
					en--;
					numbers[en] = lastNum;
					if (en == sn) {
						cout << lastNum;
						return 0;
					}
				}
				else {
					sn++;
					numbers[sn] = firstNum;
					if (sn == en) {
						cout << firstNum;
						return 0;
					}
				}
			}
		}
		else {
			long long num = numbers[sn];
			if (oper[sn] == '*')num *= numbers[sn + 1];
			else if (oper[sn] == '/')num /= numbers[sn + 1];
			//numbers.erase(numbers.begin() + sn + 1);
			sn++;
			numbers[sn] = num;
			if (sn == en) {
				cout << num;
				return 0;
			}
		}
	}
}
