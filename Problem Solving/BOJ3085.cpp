/*사탕 게임*/
#include <iostream>
using namespace std;

int N, maxCandy = 1;
char map[50][51];

//void countCandy(int r, int c) {					//왜 전체를 다 검사해야하는 지 모르겠다..
//	int len = 1;
//	int maxLen = 0;
//	//같은 행에서 제일 긴 길이 찾기
//	char candy = map[r][0];
//	for (int i = 1; i < N; i++) {
//		if (candy == map[r][i])len++;
//		else if (i == N - 1 && candy == map[r][i]) {
//			len++;
//			maxLen = (maxLen < len) ? len : maxLen;
//		}
//		else {
//			maxLen = (maxLen < len) ? len : maxLen;
//			len = 1;
//			candy = map[r][i];
//		}
//	}
//
//	//같은 열에서 제일 긴 길이 찾기
//	len = 1;
//	candy = map[0][c];
//	for (int i = 1; i < N; i++) {
//		if (candy == map[i][c])len++;
//		else if (i == N - 1 && candy == map[i][c]) {
//			len++;
//			maxLen = (maxLen < len) ? len : maxLen;
//		}
//		else {
//			maxLen = (maxLen < len) ? len : maxLen;
//			len = 1;
//			candy = map[i][c];
//		}
//		maxLen = (maxLen < len) ? len : maxLen;
//
//	}
//
//	maxCandy = (maxCandy < maxLen) ? maxLen : maxCandy;
//}

void countCandy() {
	int maxLen = 0;
	int len = 0;
	//가로에서 제일 긴 경우 찾기
	for (int i = 0; i < N; i++) {
		len = 1;
		char candy = map[i][0];
		for (int j = 1; j-1 < N; j++) {
			if (candy == map[i][j])len++;
			else if (j == N - 1 && candy == map[i][j]) {
				len++;
				maxLen = (maxLen < len) ? len : maxLen;
			}
			else {
				maxLen = (maxLen < len) ? len : maxLen;
				len = 1;
				candy = map[i][j];
			}
		}
	}

	//세로에서 제일 긴 경우 찾기
	for (int j = 0; j < N; j++) {
		len = 1;
		char candy = map[0][j];
		for (int i = 1; i - 1 < N; i++) {
			if (candy == map[i][j])len++;
			else if (j == N - 1 && candy == map[i][j]) {
				len++;
				maxLen = (maxLen < len) ? len : maxLen;
			}
			else {
				maxLen = (maxLen < len) ? len : maxLen;
				len = 1;
				candy = map[i][j];
			}
		}
	}

	maxCandy = (maxCandy < maxLen) ? maxLen : maxCandy;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)cin >> map[i];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N-1; j++) {
			//좌우 캔디 바꾸기
			if (map[i][j] != map[i][j + 1]) {
				swap(map[i][j], map[i][j + 1]);
				//countCandy(i, j);
				//countCandy(i, j + 1);
				countCandy();
				swap(map[i][j + 1], map[i][j]);
			}
			//상하 캔디 바꾸기
			if (map[j][i] != map[j + 1][i]) {
				swap(map[j][i], map[j + 1][i]);
				//countCandy(j, i);
				//countCandy(j + 1, i);
				countCandy();
				swap(map[j][i], map[j + 1][i]);
			}
			
		}
	}
	cout << maxCandy << endl;
}