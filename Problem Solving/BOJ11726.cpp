/*2xn 타일링*/
#include <stdio.h>
using namespace std;

int n;
int arr[10008];

int fibonacci(int x) {
	if (x == 0)return 1;
	if (x == 1)return 1;
	if (arr[x])return arr[x];

	return arr[x] = fibonacci(x - 2)%10007 + fibonacci(x - 1)%10007;
}
int main() {
	scanf("%d", &n);
	printf("%d\n", fibonacci(n)%10007);
}
