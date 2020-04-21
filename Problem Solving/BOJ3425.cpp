/*고스택*/
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
#define MAX 1000000000

vector<string> programs;
vector<long long> temp;
long long idx = 0;

long long solve(long long num) {
	stack<long long> st;
	st.push(num);
	for (auto cmd : programs) {
		if (cmd == "NUM") {
			long long x = temp[idx++];
			st.push(x);
		}
		else if (cmd == "POP") {
			if (st.empty())return MAX+1;
			st.pop();
		}
		else if (cmd == "INV") {
			if (st.empty())return MAX + 1;
			long long x = -st.top();
			st.pop();
			st.push(x);
		}
		else if (cmd == "DUP") {
			if (st.empty())return MAX + 1;
			st.push(st.top());
		}
		else if (cmd == "SWP") {
			if (st.empty())return MAX + 1;
			long long a = st.top();
			st.pop();
			if (st.empty())return MAX + 1;
			long long b = st.top();
			st.pop();
			st.push(a);
			st.push(b);
		}
		else if (cmd == "ADD") {
			if (st.empty())return MAX + 1;
			long long x = st.top();
			st.pop();
			if (st.empty())return MAX + 1;
			x += st.top();
			st.pop();
			st.push(x);
		}
		else if (cmd == "SUB") {
			if (st.empty())return MAX + 1;
			long long x = st.top();
			st.pop();
			if (st.empty())return MAX + 1;
			x = st.top() - x;
			st.pop();
			st.push(x);
		}
		else if (cmd == "MUL") {
			if (st.empty())return MAX + 1;
			long long x = st.top();
			st.pop();
			if (st.empty())return MAX + 1;
			x *= st.top();
			st.pop();
			st.push(x);
		}
		else if (cmd == "DIV") {
			if (st.empty())return MAX + 1;
			long long a = st.top();
			st.pop();
			if (st.empty())return MAX + 1;
			long long b = st.top();
			st.pop();
			if (a == 0)return MAX + 1;
			long long mNum = 0;
			if (a < 0) {
				mNum++;
			}
			if (b < 0) {
				mNum++;
			}
			a = b / a;
			if (mNum == 1)a = -(abs(a));
			else a = (abs(a));
			st.push(a);
		}
		else if (cmd == "MOD") {
			bool flag = false;
			if (st.empty())return MAX + 1;
			long long a = st.top();
			st.pop();
			if (st.empty())return MAX + 1;
			long long b = st.top();
			st.pop();
			if (a == 0)return MAX + 1;
			long long mNum = 0;

			if (b < 0) {
				flag = true;
			}
			a = b%a;
			if (flag)a = -(abs(a));
			else a = (abs(a));
			st.push(a);
		}
		if (!st.empty() && (st.top() > MAX || st.top() < -MAX))
			return MAX + 1;
	}
	if (st.size() != 1)return MAX + 1;
	else return st.top();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string cmd;
	do {
		cin >> cmd;
		if (cmd == "END") {
			long long N;
			cin >> N;
			for (long long i = 0; i < N; i++) {
				long long num;
				cin >> num;
				idx = 0;
				long long ans = solve(num);
				if (ans == MAX + 1)cout << "ERROR\n";
				else cout << ans << "\n";
			}
			programs.clear();
			temp.clear();
			cout << "\n";
		}
		else programs.push_back(cmd);
		if (cmd == "NUM") {
			long long n = 0;
			cin >> n;
			temp.push_back(n);
		}
	} while (cmd != "QUIT");
}
