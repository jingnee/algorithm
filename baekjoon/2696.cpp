//중앙값 구하기
#include <iostream>
#include <queue>
#include <functional>
#include <algorithm>
#include <vector>
using namespace std;

//홀수번째 입력받았을때 정렬해서 중간값 출력

//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//
//	int T;
//	cin >> T;
//	while (T--) {
//		vector<int> vec;
//		int M;
//		int cnt = 1;
//		cin >> M;
//		for (int i = 1; i <= M; i++) {
//			int n;
//			cin >> n;
//			vec.push_back(n);
//			if (i == 1)cout << (M + 1) / 2 << "\n" << n << " ";
//			else if (i % 2 == 1) {
//				cnt++;
//				sort(vec.begin(), vec.end());
//				cout << vec[i / 2] << " ";
//				if (cnt % 10 == 0)cout << "\n";
//			}
//		}
//		cout << "\n";
//	}
//}

int main() {
	int T;
	cin >> T;
	while (T--) {
		priority_queue<int> max_heap;
		priority_queue<int, vector<int>, greater<int>> min_heap;
		int M, cnt = 0;
		cin >> M;
		cout << (M + 1) / 2 << "\n";
		for (int i = 1; i <= M; i++) {
			int n;
			cin >> n;
			if (max_heap.size() == min_heap.size())max_heap.push(n);
			else min_heap.push(n);
			
			if (!max_heap.empty() && !min_heap.empty() && min_heap.top() < max_heap.top()) {
				int mi = min_heap.top();
				int ma = max_heap.top();
				min_heap.pop();
				max_heap.pop();
				min_heap.push(ma);
				max_heap.push(mi);
			}

			//홀수 번째이면
			if (i % 2) {
				cnt++;
				cout << max_heap.top() << " ";
				if (cnt % 10 == 0)cout << "\n";
			}
		}
		cout << "\n";
	}
}