/*3루수는 몰라*/
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int N, answer;
char map[501][501];
int DP[501][501];
string mola = "MOLA";
int dr[2] = { 0,1 };
int dc[2] = { 1,0 };

int findMola(int r, int c, int idx) {
	if (r < 0 || c < 0 || idx < 0)return 0;
	if (idx == 0 && map[r][c] == 'M')return DP[r][c] + 1;
	if (map[r][c] != mola[idx])return 0;
	return max(findMola(r - 1, c, idx - 1), findMola(r, c - 1, idx - 1));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	memset(DP, -1, sizeof(DP));

	cin >> N;
	for (int i = 0; i < N; i++)cin >> map[i];
	string temp1(1,map[0][0]);
	string temp2(1,map[0][0]);
	//맨윗줄이랑 맨왼쪽줄 판별
	DP[0][0] = 0;
	for (int i = 1; i < N; i++) {
		temp1 += map[0][i];
		temp2 += map[i][0];
		int n1 = temp1.find(mola);
		int n2 = temp2.find(mola);

		if (n1 == string::npos)DP[0][i] = DP[0][i-1];
		else {
			DP[0][i] = DP[0][i - 1] + 1;
			temp1 = "";
		}

		if (n2 == string::npos)DP[i][0] = DP[i-1][0];
		else {
			DP[i][0] = DP[i - 1][0] + 1;
			temp2 = "";
		}
	}
	for (int i = 1; i < N; i++) {
		for (int j = 1; j < N; j++) {
			if (map[i][j] != 'A')
				DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
			//현재 위치가 'A'인경우 4칸을 거슬러 올라가본다.
			else 
				DP[i][j] = max(max(DP[i - 1][j], DP[i][j - 1]), findMola(i, j, 3));	
		}
	}
	cout << DP[N - 1][N - 1] << "\n";
}
