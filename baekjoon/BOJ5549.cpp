/*Çà¼º Å½»ç*/
#include <stdio.h>
#include <cstring>
using namespace std;

int N, M, K;
struct land {
	int jNum, oNum, iNum;
} map[1001][1001];

int main() {

	//cin >> N >> M >> K;
	scanf("%d %d %d", &N, &M, &K);
	getchar();
	for (int i = 1; i <= N; i++) {
		int jungle = 0, sea = 0, ice = 0;
		for (int j = 1; j <= M; j++) {
			char ch;
			//cin >> ch;
			scanf("%c", &ch);
			map[i][j] = map[i-1][j];
			if (ch == 'J')jungle++;
			else if (ch == 'I')ice++;
			else if (ch == 'O')sea++;
			map[i][j].jNum += jungle;
			map[i][j].iNum += ice;
			map[i][j].oNum += sea;
		}
		getchar();
	}

	for (int i = 0; i < K; i++) {
		int sr, sc, er, ec;
		//cin >> sr >> sc >> er >> ec;
		scanf("%d %d %d %d", &sr, &sc, &er, &ec);
		getchar();
		int jj, ii, oo;
		jj = map[er][ec].jNum - map[er][sc - 1].jNum - map[sr - 1][ec].jNum + map[sr - 1][sc - 1].jNum;
		ii = map[er][ec].iNum - map[er][sc - 1].iNum - map[sr - 1][ec].iNum + map[sr - 1][sc - 1].iNum;
		oo = map[er][ec].oNum - map[er][sc - 1].oNum - map[sr - 1][ec].oNum + map[sr - 1][sc - 1].oNum;
		//cout << jj << ' ' << oo << ' ' << ii << endl;
		printf("%d %d %d\n", jj, oo, ii);
	}
	
}