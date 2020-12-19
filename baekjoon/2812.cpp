//크게 만들기
#include <iostream>
#include <deque>
#include <string>
using namespace std;

int N, K;
string number;
deque<char> dq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> K >> number;
	for (int i = 0; i < N; i++) {
		while (K && !dq.empty() && dq.back() < number[i]) {
			dq.pop_back();
			K--;
		}
		dq.push_back(number[i]);
	}
	for (int i = 0; i < dq.size() - K; i++)cout << dq[i];
}
