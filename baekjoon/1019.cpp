//책 페이지
#include <iostream>
using namespace std;

int N;
int start, last, ten = 1;
int numCount[10];

void calc(int n, int ten) {
	while (n > 0) {
		numCount[n % 10] += ten;
		n /= 10;
	}
}

int main() {
	cin >> N;
	start = 1;
	last = N;

	while (start <= last) {
		//start의 1의자리 0으로 만들기
		while (start % 10 != 0 && start <= last) {
			calc(start, ten);
			start++;
		}
		if (start > last)break;
		//last의 1의자리 9로 만들기
		while (last % 10 != 9 && start <= last) {
			calc(last, ten);
			last--;
		}

		int cnt = (last / 10 - start / 10 + 1);
		for (int i = 0; i <= 9; i++)numCount[i] += cnt*ten;

		start /= 10;
		last /= 10;
		ten *= 10;
	}
	for (int i = 0; i <= 9; i++)cout << numCount[i] << ' ';
}
