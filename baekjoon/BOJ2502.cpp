/*떡 먹는 호랑이*/

#include <iostream>
using namespace std;

int a = 1, b=1;
int D, K;
int firNum, secNum;

int main() {
	cin >> D >> K;
	for (int i = 3; i < D; i++) {
		int prev = a;
		a = b;
		b += prev;
	}
	
	for (int i = 1; i <= K / 2; i++) {
		if ((K - (a*i)) % b == 0) {
			firNum = i;
			secNum = (K - (a*i)) / b;
			break;
		}
	}
	cout << firNum << "\n" << secNum << '\n';
}
