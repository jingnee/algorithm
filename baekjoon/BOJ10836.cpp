/*여왕벌*/
#include <iostream>
using namespace std;

int M, N, s;
int map[701][701];
int bees[1400];


void breed(int r, int c, int idx, bool flag) {
	if (r == -1) {
		r = 0;
		c = 1;
		flag = true;
	}
	if (c == M || idx > 2*M - 1)return;
	
	map[r][c] += bees[idx];
	if (flag) c++;
	else r--;
	breed(r, c, idx+1, flag);
}

void Allbreed() {
	for (int i = 1; i < M; i++) {
		for (int j = 1; j < M; j++) {
			int num = (map[i - 1][j] > map[i - 1][j - 1]) ? map[i - 1][j] : map[i - 1][j - 1];
			num = (num < map[i][j - 1]) ? map[i][j - 1] : num;
			map[i][j] = num;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> M >> N;
	int a, b, c;
	for (int i = 0; i < N; i++) {
		cin >> a >> b >> c;
		for (int j = 0; j < b; j++) bees[a + j]++;
		for (int j = 0; j < c; j++)bees[a + b + j] += 2;
	}

	for (int i = 0; i < M; i++) 
		for (int j = 0; j < M; j++) 
			map[i][j] = 1;
	
	breed(M - 1, 0, 0, false);
	Allbreed();

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++) {
			cout << map[i][j]<<" ";
		}cout << "\n";
	}
}
