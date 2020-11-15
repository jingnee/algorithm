//뒤집힌 계산기
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
		//마지막 숫자까지 넣기
		if (i == 0) {
			numbers.push(stoll(expression.substr(i, idx - i + 1)));
			continue;
		}
		//연산자 일때만 아래 수행
		if (expression[i] >= '0' && expression[i] <= '9')continue;
		int p = op_priority[expression[i]];
		numbers.push(stoll(expression.substr(i + 1, idx - i + 1)));
		idx = i - 1;
		if (operations.empty() || operations.top().second < p) {
			operations.push(make_pair(expression[i], p));
		}
		else {
			//연산자 우선순위가 나보다 낮으면 계산
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