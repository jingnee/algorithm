/*직사각형 길이 찾기*/
#include <stdio.h>
using namespace std;

int a, b, c;
int main() {
	int T;
	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; test_case++) {
		scanf("%d %d %d", &a, &b, &c);
		int answer = a;
		if (a == b)answer = c;
		else if (a == c)answer = b;
		printf("#%d %d\n", test_case, answer);
	}
}
