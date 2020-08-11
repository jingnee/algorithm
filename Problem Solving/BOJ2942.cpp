/*퍼거슨과 사과*/
#include<iostream>
using namespace std;

int R, G;

int GCD(int a, int b) {
	if (b == 0)return a;
	else return GCD(b, a%b);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> R >> G;

	int maxApple = 0;
	if (G < R)maxApple = GCD(R, G);
	else maxApple = GCD(G, R);

	/*for (int i = 1; i <= maxApple; i++) {
		if (R%i == 0 && G%i == 0) 
			cout << i << " " << R / i <<" " <<  G / i << "\n";	
	}*/

	//i로 나눠 떨어진다는건 그 몫으로도 나눌 수 있다는 말
	for (int i = 1; i * i <= maxApple; i++) {
		if (maxApple % i)
			continue;

		printf("%d %d %d\n", i, R / i, G / i);

		if (i * i == maxApple)
			break;
		int buf = maxApple / i;
		printf("%d %d %d\n", buf, R / buf, G / buf);
	}

}
