//민트 초코
#include <iostream>
#include <vector>
using namespace std;

int num, N;
char oper;
bool flag;
int temp;
int number[100001];

void Factorization(int n, bool isMulti) {
	if (n < 0)n *= -1;

	for (int i = 2; i*i <= n; i++) {
		while (n%i == 0) {
			if (isMulti)number[i]++;
			else number[i]--;
			n /= i;
		}
	}

	//n이 소수면
	if (n > 1) {
		if (isMulti)number[n]++;
		else number[n]--;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	cin >> num;

	if (N == 1) {
		cout << "mint chocolate";
		return 0;
	}
	if (num < 0)num *= -1;
	if (num == 0)flag = true;
	else Factorization(num, true);

	for (int i = 0; i < N - 1; i++) {
		cin >> oper >> num;
		if (num < 0)num *= -1;
		if (num == 0 || flag) {
			flag = true;
			continue;
		}

		if (oper == '*') {
			Factorization(num, true);
		}

		else {
			Factorization(num, false);
		}
	}

	if (flag) {
		cout << "mint chocolate";
		return 0;
	}
	for (int i = 1; i <= 100000; i++) {
		//0이하라는건 분모가 남아있다는거니까 정수가 아닌 유리수 (정수인경우 계속 소인수분해를 해주었기때문에 분모는 1)
		if (number[i] < 0) {
			cout << "toothpaste";
			return 0;
		}
	}
	cout << "mint chocolate";
	return 0;
}
