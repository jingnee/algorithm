//ÀÌÄ£¼ö
#include <iostream>
using namespace std;

int N;
long long sum[92][2];

int main() {
	cin >> N;
	sum[1][0] = 0;
	sum[1][1] = 1;
	for (int i = 2; i <= N; i++) {
		sum[i][0] = sum[i - 1][0] + sum[i - 1][1];
		sum[i][1] = sum[i - 1][0];
	}
	cout << sum[N][0] + sum[N][1];
}