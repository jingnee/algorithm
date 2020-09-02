/*소수&팰린드롬*/
#include <iostream>
using namespace std;

bool notPrime[1003002];			//false가 소수
int N;

bool isPalindrome(int num) {
	int number[7] = { 0 };
	int idx = 0;
	while (num > 0) {
		number[idx++] = num % 10;
		num /= 10;
	}
	idx--;
	for (int i = 0; i <= idx/2; i++) {
		if (number[i] != number[idx - i])return false;
	}
	return true;
}

int main() {
	notPrime[0] = notPrime[1] = true;
	for (int num = 2; num*num <= 1003001; num++) {
		if (!notPrime[num]) {		//소수가아닌애들은 약수의 배수들로 이미 체크를 했기때문에 소수인 애들만 검사
			for (int i = num*num; i <= 1003001; i += num) {
				notPrime[i] = true;
			}
		}	
	}

	cin >> N;
	for (int i = N; i <= 1003001; i++) {
		if (!notPrime[i]) {
			if (isPalindrome(i)) {
				cout << i;
				return 0;
			}
		}
	}

}
