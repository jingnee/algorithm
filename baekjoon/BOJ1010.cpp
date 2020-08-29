//다리 놓기
#include <iostream>
using namespace std;

int N, M;
int C[31][31];
int combination(int i, int j) {

	if (C[i][j] != 0)return C[i][j];
	else if (i == j || j == 0)return 1;
	C[i][j] = combination(i - 1, j - 1) + combination(i - 1, j);
	return C[i][j];
}

//M개의 서쪽 다리에서 N개의 동쪽과연결되는 도시를 고른다
//M개중 N개를 고르는 방법
// mCn
int main() {
	int T;
	cin >> T;
	for (int i = 1; i < 31; i++) {
		C[i][1] = i;
	}
	C[2][2] = 1;
	while (T-- > 0){
		cin >> N >> M;
		cout << combination(M, N) << endl;
	}
	
}