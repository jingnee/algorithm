//팩토리얼 0의 개수
#include <iostream>
using namespace std;

int N, answer;
int main() {
	cin >> N;
	for (int i = 2; i <= N; i++) {
		if (i % 5 == 0)answer++;
		if (i % 25 == 0)answer++;
		if (i % 125 == 0)answer++;
	}
		
	cout << answer;
	return 0;
}