#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<long long> num;
vector<char>oper;
char priority[6][3] = {	
	{'+','-','*'},
	{'+','*','-'},
	{'*','+','-'},
	{'*','-','+'},
	{'-','+','*'},
	{'-','*','+'}
};

long long solution(string expression) {
	long long ret = 0;
	int idx = 0;
	for (int i = 0; i < expression.size(); i++) {
		if (expression[i] == '+' || expression[i] == '*' || expression[i] == '-') {
			num.push_back(stoll(expression.substr(idx, i - idx)));
			idx = i + 1;
			oper.push_back(expression[i]);
		}
	}
	num.push_back(stoll(expression.substr(idx)));
	
	for (int p = 0; p < 6; p++) {
		vector<long long> newNum = num;
		vector<char> newOper = oper;

		for (auto a : priority[p]) {
			for (int b = 0; b < newOper.size(); b++) {
				if (a == newOper[b]) {
					if (a == '+') 
						newNum[b+1] = newNum[b] + newNum[b + 1];
					else if(a=='-')
						newNum[b+1] = newNum[b] - newNum[b + 1];
					else
						newNum[b+1] = newNum[b] * newNum[b + 1];
					newNum.erase(newNum.begin() + b);
					newOper.erase(newOper.begin() + b);
					b--;
				}
			}
		}
		ret = (ret < abs(newNum[0])) ? abs(newNum[0]) : ret;
	}
	return ret;
}

int main() {
	cout << solution("100-200*300-500+20");
}
