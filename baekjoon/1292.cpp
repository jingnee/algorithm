//쉽게 푸는 문제
#include <iostream>
using namespace std;

int A, B, cnt, ans;

int main() {
	cin >> A >> B;
	for (int i = 1; i <= 45; i++) {
		for (int j = 1; j <= i; j++) {
			cnt++;
			if (cnt >= A && cnt <= B)ans += i;
			if (cnt == B)break;
		}
		if (cnt == B)break;
	}
	cout << ans;
}