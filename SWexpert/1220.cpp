/*
1. n극(1)은 아래로, s극(2)는 위로이동하는데, 서로 만나 이동하지못하는 교착상태의 갯수 출력하기.
2. N <= 100
3. 2중 for문을 돌면서(가로먼저가아닌 세로먼저돔) 1을 찾고 아래 2가 있는지 체크
*/
#include <iostream>
using namespace std;

int answer;			//교착 상태 갯수
int map[100][100];	//테이블
int N;				//테이블 크기

int check(int r, int c) {			//교착상태 찾는함수
	int i = r + 1;
	for (i; i < N; i++) {			//찾은1아래부터 2가있는지 검사
		if (map[i][c] == 2) {
			answer++;
			return i;					//2찾은 경우위치 반환
		}
	}
	return i;								//찾지 못한경우 마지막위치 반환
}

int main() {
	int T = 10;
	for (int test_case = 1; test_case <= T; test_case++) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
			}
		}

		for (int col = 0; col < N; col++) {
			for (int row = 0; row < N; row++) {
				if (map[row][col] == 1) {		//1찾기
					int next_row= check(row, col);
					row = next_row;
				}
			}
		}
		cout << "#" << test_case << " " << answer << endl;
		
		answer = 0;			//초기화
	}
}