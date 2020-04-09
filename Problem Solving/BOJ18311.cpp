/*왕복*/
#include <iostream>
#include <vector>
using namespace std;

int N;
long long K;
int answer;
vector<int> numbers;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long cnt = 0;
	bool flag = false;

	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		int num;
		cin >> num;
		cnt += num;
		numbers.push_back(num);
		if (!flag && K < cnt) {
			flag = true;
			answer = i;
		}
	}

	if (flag) {
		cout << answer << "\n";
		return 0;
	}
	else {
		for (int i = numbers.size() - 1; i >= 0; i--) {
			cnt += numbers[i];
			if (!flag && K < cnt) {
				flag = true;
				cout << i + 1 << "\n";
				return 0;
			}
		}
	}
}
