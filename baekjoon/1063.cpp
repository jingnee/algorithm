#include <iostream>
#include <string.h>
using namespace std;

//char cmd[50][2];	//명령받을 배열
int map[9][9];	//맵크기 행은 1부터 시작하므로
//방향배열    R,RB,B,LB,L,LT,T,RT
int dc[8] = { 1,1,0,-1,-1,-1,0,1 };
int dr[8] = { 0,-1,-1,-1,0,1,1,1 };
int get_which(char *ch) {
	if (strcmp(ch, "R") == 0) return 0;
	else if (strcmp(ch, "RB") == 0)return 1;
	else if (strcmp(ch, "B") == 0)return 2;
	else if (strcmp(ch, "LB") == 0)return 3;
	else if (strcmp(ch, "L") == 0)return 4;
	else if (strcmp(ch, "LT") == 0)return 5;
	else if (strcmp(ch, "T") == 0)return 6;
	else if (strcmp(ch, "RT") == 0)return 7;
}

int main() {
	char king;
	char dol;
	int king_r, dol_r, king_c, dol_c;
	int num;
	cin >> king >> king_r;
	king_c = king - 64;

	cin >> dol >> dol_r;
	dol_c = dol - 64;

	cin >> num;
	for (int i = 0; i < num; i++) {
		char cmd[3];
		cin >> cmd;
		int num = get_which(cmd);
		//명령받은 위치 이동한값 담기
		int nkc = king_c + dc[num];
		int nkr = king_r + dr[num];
		int ndc = dol_c + dc[num];
		int ndr = dol_r + dr[num];
	
		if (nkc == dol_c && nkr == dol_r){
			if( ndc > 0 && ndc <= 8 && ndr > 0 && ndr <= 8) {
			king_c = nkc;
			king_r = nkr;
			dol_c = ndc;
			dol_r = ndr;
			}
			else continue;
		}
		else if (nkc <= 0 || nkc >8 || nkr <= 0 || nkr>8) continue;
		else {
			king_c = nkc;
			king_r = nkr;
		}
	}
	
	cout << (char)(king_c + 64) << king_r << endl;
	cout << (char)(dol_c + 64) << dol_r << endl;

}
