/*마법의 체스판*/
#include <iostream>
using namespace std;

int n, m;
int chess[51][51];
int main() {
	cin >> n >> m;

	cout << n / 2 + m / 2 << "\n";
	for (int i = 2; i <= n; i+=2) 
		printf("%d 1 %d %d\n", i, i, m);
	for (int i = 2; i <= m; i += 2)
		printf("1 %d %d %d\n", i, n, i);
}
