/*볼 모으기*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string balls;
int n, answer = 2e9;

int main() { 
	int R1 = 0, R2, B1, B2;
	cin >> n >> balls;
	for (auto i : balls) {
		if (i == 'R')R1++;
	}
	R2 = R1, B1 = B2 = n - R1;
	//왼쪽에 빨간공 모으기
	int i = 0;
	while (balls[i++] == 'R')R1--;
	//왼쪽에 파란공 모으기
	i = 0;
	while (balls[i++] == 'B')B1--;
	//오른쪽에 빨강공 모으기
	i = n - 1;
	while (i >= 0 && balls[i--] == 'R') R2--;
	//오른쪽에 파란공 모으기
	i = n - 1;
	while (i >= 0 && balls[i--] == 'B') B2--;

	cout << min(min(R1, R2), min(B1, B2));
}
