//단순 2진 암호코드
/*
암호코드는 8개의 숫자로 구성, 각 숫자는 7개의 이진수로 구성
1. 전체 맵에서 암호코드인 부분찾기(한줄만 찾으면 됨)
2. 암호코드 첫줄 인덱스를 si,sj에 저장해서 sj를 8씩 증가하면서 탐색
3. code배열에 7개의 이진수로 이루어진 암호코드를 넣고, code배열을 이용해서 답을 구함
	code배열은 1부터 시작
*/
#include<iostream>
using namespace std;

int N, M;			//N:세로, M:가로
//char num[10][56] = {
//	{0,0,0,1,1,0,1},		//0
//  {0,0,0,1,0,1,1},		//9
//------------------------------
//	{0,0,1,1,0,0,1},		//1
//	{0,0,1,0,0,1,1},		//2
//-------------------------------
//	{0,1,0,0,0,1,1},		//4
//	{0,1,0,1,1,1,1},		//6
//-------------------------------
//	{0,1,1,1,1,0,1},		//3
//	{0,1,1,1,0,1,1},		//7
//-------------------------------
//	{0,1,1,0,0,0,1},		//5
//	{0,1,1,0,1,1,1},		//8

//};
int map[50][100];
int main() {
	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		int code[9];				//이진 암호코드를 int로 변환해 넣음
		int mini_j = 0, flag = 0;
		int si = 0, sj = 0;
		cin >> N >> M;
		for (int i = 0; i < N; i++) {					//전체 암호코드 입력받기
			for (int j = 0; j < M; j++) {
				//cin >> map[i][j];
				scanf("%1d", &map[i][j]);
				if (map[i][j] == 1 && flag == 0) {		//1이나오는점을 중심으로 암호코드찾기
					si = i;
					mini_j = j;
					
				}
			}
		}

		for (int j = mini_j + 55; j >= mini_j; j--) {
			if (map[si][j] == 1) {//뒤에서부터 따졌을때 1이 처음나오는 곳이 암호코드의 제일 마지막자리
				sj = j - 55;
				break;
			}
		}
		//cout << "암호코드 시작위치 [" << si << "][" << sj << "]" << endl;
		//암호코드는 map[si][sj]부터 map[si+?][sj+55]이다.
		int index = 1;
		for (int j = sj; j < sj + 56; j += 7) {
			int start = j;
			if (map[si][start + 1] == 0) {		//0,1,2,9
				if (map[si][start + 2] == 0) {		//0,9
					if (map[si][start + 4] == 1) code[index++] = 0;	//0
					else code[index++] = 9;		//9
				}
				else {			//1,2
					if (map[si][start + 3] == 1) code[index++] = 1;//1
					else code[index++] = 2;
				}
			}
			else if (map[si][start + 1] == 1) {	//3,4,5,6,7,8
				if (map[si][start + 2] == 0) {		//4,6
					if (map[si][start + 3] == 1) code[index++] = 6;
					else code[index++] = 4;
				}
				else {			//3,5,7,8
					if (map[si][start + 3] == 0) {		//5,8
						if (map[si][start + 4] == 0) code[index++] = 5;
						else code[index++] = 8;
					}
					else {		//3,7
						if (map[si][start + 4] == 0) code[index++] = 7;
						else code[index++] = 3;
					}
				}
			}
		}

	/*	for (int i = 1; i <= 8; i++)cout << code[i] << ' ';
		cout << endl;*/

		int result = 0;
		int answer = 0;
		answer = code[1] + code[2] + code[3] + code[4] + code[5] + code[6] + code[7] + code[8];
		result = (code[1] + code[3] + code[5] + code[7]) * 3 + code[2] + code[4] + code[6] + code[8];
		//cout << "result: " << result << endl;
		if (result % 10 != 0) answer = 0;

		cout << "#" << test_case << ' ' << answer << endl;
	}
}