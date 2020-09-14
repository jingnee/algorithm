//주식가격
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

stack<int> st;
vector<int> solution(vector<int> prices) {
	vector<int> answer(prices.size(), 0);
	for (int i = 0; i < prices.size(); i++) {
		if (st.empty() || prices[st.top()] <= prices[i])st.push(i);
		else {
			int temp = st.top();
			st.pop();
			answer[temp] = i - temp;
			i--;
		}
	}
	int cnt = st.top();
	while (!st.empty()) {
		answer[st.top()] = cnt - st.top();
		st.pop();
	}
	return answer;
}

int main() {
	vector<int> answer = solution({ 1,2,3,2,3 });
}
