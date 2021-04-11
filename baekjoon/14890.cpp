//경사로
#include <iostream>
#include <cmath>
using namespace std;

int N, L, ans;
int map[101][101];

int main() {
	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	//가로 확인
	for (int i = 0; i < N; i++) {
		bool flag = true;
		int prev = 1;
		for (int j = 1; j < N; j++) {
			//차이가 1초과이면 안됨
			if (abs(map[i][j - 1] - map[i][j]) > 1) {
				flag = false;
				break;
			}
			//이전과 같은 위치면 prev ++
			else if (map[i][j - 1] == map[i][j])prev++;
			//이전과 다른위치인데 하나차이
			else {
				//뒤에있는게 큰애이면 prev갯수 세기
				if (map[i][j - 1] < map[i][j]) {
					if (prev < L) {
						flag = false;
						break;
					}
					prev = 1;
				}
				//앞에 있는게 더 큰애면 블록 세울만큼 뒤에 있는지 확인하고 없거나 같은수 아니면 탈락
				else if (map[i][j - 1] > map[i][j]) {
					if (j + L - 1 >= N) {
						flag = false;
						break;
					}
					int num = map[i][j];
					for (int k = j+1; k < j + L; k++) {
						if (num != map[i][k]) {
							flag = false;
							break;
						}
					}
					j = j + L-1;
					prev = 0;
					if (!flag)break;
				}
			}
		}
		if (flag)ans++;
	}

	//세로 확인
	for (int j = 0; j < N; j++) {
		bool flag = true;
		int prev = 1;
		for (int i = 1; i < N; i++) {
			//차이가 1초과이면 안됨
			if (abs(map[i-1][j] - map[i][j]) > 1) {
				flag = false;
				break;
			}
			//이전과 같은 위치면 prev ++
			else if (map[i-1][j] == map[i][j])prev++;
			//이전과 다른위치인데 하나차이
			else {
				//뒤에있는게 큰애이면 prev갯수 세기
				if (map[i-1][j] < map[i][j]) {
					if (prev < L) {
						flag = false;
						break;
					}
					prev = 1;
				}
				//앞에 있는게 더 큰애면 블록 세울만큼 뒤에 있는지 확인하고 없거나 같은수 아니면 탈락
				else if (map[i-1][j] > map[i][j]) {
					if (i + L - 1 >= N) {
						flag = false;
						break;
					}
					int num = map[i][j];
					for (int k = i + 1; k < i + L; k++) {
						if (num != map[k][j]) {
							flag = false;
							break;
						}
					}
					i = i + L-1;
					prev = 0;
					if (!flag)break;
				}
			}
		}
		if (flag)ans++;
	}
	cout << ans;
}
