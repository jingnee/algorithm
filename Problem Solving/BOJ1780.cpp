//종이의 개수
#include <iostream>
using namespace std;

int cnt[3];
int map[2188][2188];
int N;

//check함수 하나만 이용 (범위설정을 이용한 풀이)
#if 1
void check(int y, int x, int l) {
	if (l == 0)return;
	int temp = map[y][x];
	int flag = 0;
	for (int i = y; i < y + l; i++) {
		if (flag == 1)break;
		for (int j = x; j < x + l; j++) {
			if (temp != map[i][j]) {
				flag = 1;
				break;
			}
		}
	}

	if(flag==0) cnt[temp + 1]++;
	if (flag == 1) {
		for (int i = y; i < y+l; i += (l / 3)) {
			for (int j = x; j < x+l; j += (l / 3)) {
				check(i, j, l / 3);
			}
		}
	}
	
}

int main() {
	int length;
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	check(0, 0, N);
	cout << cnt[0] << '\n' << cnt[1] << '\n' << cnt[2] << '\n';
	
}
#endif

//구간이 모두 같은 수인지 판별하는 check함수와, check함수를 이용해 갯수를 세는 simul함수
#if 0

bool check(int y, int x, int l) {
	int temp = map[y][x];
	for (int i = y; i < y + l; i++) {
		for (int j = x; j < x + l; j++) {
			if (temp != map[i][j]) {
				return false;
			}
		}
	}
	return true;
}

void simul(int y, int x, int l) {
	if (check(y, x, l) == true)
		cnt[map[y][x] + 1]++;
	else {
		int ll = l / 3;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				simul(y + i*ll, x + j*ll, ll);
			}
		}
	}
}

int main() {
	int length;
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	simul(0, 0, N);
	cout << cnt[0] << '\n' << cnt[1] << '\n' << cnt[2] << '\n';

}
#endif