//가운데를 말해요
#include <iostream>
#include <functional>
#include <queue>
using namespace std;

priority_queue<int> max_heap;
priority_queue<int, vector<int>, greater<int>> min_heap;
int N;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	while (N--) {
		int num;
		cin >> num;
		if (max_heap.size() == min_heap.size())max_heap.push(num);
		else min_heap.push(num);

		if (!max_heap.empty() && !min_heap.empty() && min_heap.top() < max_heap.top()) {
			int mi = min_heap.top();
			int ma = max_heap.top();
			min_heap.pop();
			max_heap.pop();
			min_heap.push(ma);
			max_heap.push(mi);
		}
		cout << max_heap.top() << "\n";
	}
}