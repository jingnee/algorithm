//기상캐스터
#include<iostream>
using namespace std;

int H, W;
char map[101][101];
int answer[101][101];
int main() {
	cin >> H >> W;
	for (int i = 0; i < H; i++)cin >> map[i];
	int flag;
	for (int i = 0; i < H; i++) {
		if (map[i][0] == '.') flag = 0;
		else if (map[i][0] == 'c')flag = 1;
		for (int j = 0; j < W; j++) {
			if (map[i][j] == '.' && flag == 0)answer[i][j] = -1;
			else if (map[i][j] == 'c') {
				flag = 1;
				answer[i][j] = 0;
			}
			else {
				answer[i][j] = answer[i][j - 1] + 1;
			}
		}
	}
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cout << answer[i][j] << ' ';
		}cout << endl;
	}
}