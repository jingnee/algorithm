/*리모컨
1. 0부터 1000000까지숫자중에서 리모콘 숫자로 이동가능한지 판단
2. 이동가능한 숫자면 길이를 구하고
3. 이동가능숫자에서 +또는 - 얼마나하는지 구하기*/
#include<iostream>
using namespace std;

int N, M;
bool isBreakdown[10];
int length(int num) {
	int len = 0;
	if (num == 0) {
		if (isBreakdown[0])return 0;
		else return 1;
	}
	else {
		while (num > 0) {
			if (isBreakdown[num % 10])return 0;
			num /= 10;
			len++;
		}
	}
	return len;
}

int main() {
	int pushNum = 0;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int num;
		cin >> num;
		isBreakdown[num] = true;
	}
	if (N >= 100)pushNum = N - 100;
	else {
		pushNum = 100 - N;
	}

	for (int i = 0; i <= 1000000; i++) {
		int len = length(i);
		if (len > 0) {
			if (i >= N) {
				int pushed = i - N;
				pushed += len;
				pushNum = (pushNum > pushed) ? pushed : pushNum;
			}
			else {
				int pushed = N - i;
				pushed += len;
				pushNum = (pushNum > pushed) ? pushed : pushNum;
			}
		}
	}

	cout << pushNum << endl;
}