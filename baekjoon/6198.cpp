//옥상 정원 꾸미기
#include<iostream>
#include<stack>
using namespace std;

int N, ans;
stack<pair<int,int>> st;
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int height;
		cin >> height;
		while (!st.empty() && st.top().second <= height) {
			ans += (i - st.top().first - 1);
			st.pop();
		}
		st.push(make_pair(i, height));
	}
	if (!st.empty()) {
		int last = st.top().first;
		st.pop();
		while (!st.empty()) {
			ans += last - st.top().first;
			st.pop();
		}
	}
	cout << ans;
}
