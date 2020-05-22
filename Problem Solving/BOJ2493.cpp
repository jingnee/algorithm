/*탑*/
#include <iostream>
#include <stack>
using namespace std;

stack<pair<int, int>> st;			//높이, 값
int N;
int topp[500001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> topp[i];
	
	int ans = 0;
	st.push(make_pair(topp[1], 1));
	cout << ans << " ";

	for (int i = 2; i <= N; i++) {
		//스택이 비지않고 나보다 큰값이 나올때까지
		while (!st.empty() && st.top().first <= topp[i])
			st.pop();
		if (st.empty()) ans = 0;
		else ans = st.top().second;
		st.push(make_pair(topp[i], i));
		cout << ans << " ";
	}

}
