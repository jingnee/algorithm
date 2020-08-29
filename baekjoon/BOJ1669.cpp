/*멍멍이 쓰다듬기
두 수사이의 차이만 중요
차이가 n^2인경우(어떤수의 제곱) 1+2+3+..+n+n-1+....+2+1일. 즉 n+(n-1)일이다.
차이가 (n-1)^2+1 ~ n^2-n 까지는 전 제곱수일때 일+1일이다. 즉 (n-1)+(n-2)+1 일
차이가 n^2-n+1 ~ n^2인경우 n+(n-1)일 */
#include <iostream>
using namespace std;

unsigned int X, Y;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> X >> Y;
	unsigned int cha = Y - X;
	if (cha == 1) {
		cout << "1\n";
		return 0;
	}
	long long num = 1;
	while (1) {
		if (num*num >= cha)break;
		num++;
	}

	if (cha <= num*num - num)cout << num * 2 - 2 << "\n";
	else cout << 2 * num - 1 << "\n";
}
