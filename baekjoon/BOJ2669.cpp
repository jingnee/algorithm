/*직사각형 네개의 합집합의 면적 구하기*/
#include <iostream>
using namespace std;

int map[101][101];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 4; i++) {
		int x, y, x1, y1;
		cin >> x >> y >> x1 >> y1;
		for (int i = x; i < x1; i++) {
			for (int j = y; j < y1; j++) {
				map[i][j] = 1;
			}
		}
	}
	int tot = 0;
	for (int i = 1; i <= 100; i++) {
		for (int j = 1; j <= 100; j++) {
			if (map[i][j] == 1)tot++;
		}
	}
	cout << tot << "\n";
}
