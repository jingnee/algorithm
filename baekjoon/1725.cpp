//히스토그램
#include <iostream>
#include <stack>
using namespace std;

stack<int> st;
int ans;
int N;
int arr[100003];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	arr[N+1] = 0;
	st.push(0);

	for (int i = 1; i <= N+1; i++) {
		while (!st.empty() && arr[st.top()] > arr[i]) {
			int h = arr[st.top()];
			st.pop();
			int w = i - st.top() - 1;
			int size = h*w;
			if (ans < size)ans = size;
		}
		st.push(i);
	}

	cout << ans;
}
