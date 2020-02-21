#include <iostream>
#include <queue>
using namespace std;

int main() {
	for (int test_case = 1; test_case <= 10; test_case++) {
		int num;
		cin >> num;
		queue<int> que;
		for (int i = 0; i < 8; i++) {
			int j;
			cin >> j;
			que.push(j);
		}
		int index = 1;
		int flag = 0;

		while (flag==0) {
			int first = que.front();
			que.pop();
			first -= index;
			if (first <= 0) {
				first = 0;
				//que.push(first);
				//index++;
				flag = 1;
			}
			que.push(first);
			index++;
			if (index == 6)index = 1;
		}
		cout << "#" << num << " ";
		while (!que.empty()) {
			int q = que.front();
			que.pop();
			cout << q << " ";
		}
		cout << endl;
	}
}