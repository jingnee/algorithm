//������ ����
#include <iostream>
#include <string>
#include <stack>
#include <map>
using namespace std;
typedef long long ll;

map<char, int> op_priority;
stack<ll> numbers;
stack<pair<char, int>> operations;
char op[4] = { '+','-','*','/' };
string expression;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 0; i < 4; i++) {
		int a;
		cin >> a;
		op_priority[op[i]] = a;
	}
	cin >> expression;
	//reverse(expression.begin(), expression.end());

	int idx = expression.size()-1;
	for (int i = expression.size()-1; i >= 0; i--) {
		//������ ���ڱ��� �ֱ�
		if (i == 0) {
			numbers.push(stoll(expression.substr(i, idx - i + 1)));
			continue;
		}
		//������ �϶��� �Ʒ� ����
		if (expression[i] >= '0' && expression[i] <= '9')continue;
		int p = op_priority[expression[i]];
		numbers.push(stoll(expression.substr(i + 1, idx - i + 1)));
		idx = i - 1;
		if (operations.empty() || operations.top().second < p) {
			operations.push(make_pair(expression[i], p));
		}
		else {
			//������ �켱������ ������ ������ ���
			while (!operations.empty() && operations.top().second >= p) {
				ll second = numbers.top();
				numbers.pop();
				ll first = numbers.top();
				numbers.pop();
				pair<char, int> temp = operations.top();
				operations.pop();

				if (temp.first == '+')first += second;
				else if (temp.first == '-')first -= second;
				else if(temp.first == '*')first *= second;
				else first /= second;

				numbers.push(first);
				/*if(!operations.empty())
				p = operations.top().second;*/
			}
			operations.push(make_pair(expression[i], p));
		}
	}

	while (!operations.empty()) {
		ll second = numbers.top();
		numbers.pop();
		ll first = numbers.top();
		numbers.pop();
		pair<char, int> temp = operations.top();
		operations.pop();

		if (temp.first == '+')first += second;
		else if (temp.first == '-')first -= second;
		else if (temp.first == '*')first *= second;
		else first /= second;

		numbers.push(first);
	}
	cout << numbers.top();
}