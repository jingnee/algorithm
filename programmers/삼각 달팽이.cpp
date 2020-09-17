//삼각달팽이
#include <iostream>
#include <vector>
using namespace std;

int snail[1000][1000];
vector<int> solution(int n) {
	vector<int> answer;

	snail[0][0] = 1;
	int num = 2;
	int r = 0, c = 0;
	
	while (num <= (1 + n)*n / 2) {
		//아래로 채우기
		while (1) {
			if (snail[r + 1][c] != 0 || r + 1 >= n)break;
			snail[r+1][c] = num++;
			r++;
		}
		//오른쪽으로 채우기
		while (1) {
			if (snail[r][c + 1] != 0 || c + 1 >= n)break;
			snail[r][c+1] = num++;
			c++;
		}
		//대각선으로 올라가면서 채우기
		while (1) {
			if (r - 1 < 0 || c - 1 < 0 || snail[r - 1][c - 1] != 0)break;
			snail[r - 1][c - 1] = num++;
			r--;
			c--;
		}
	}
	for (int i = 0; i < n; i++) {
		int j = 0;
		while (snail[i][j] != 0)answer.push_back(snail[i][j++]);
	}
	return answer;
}

int main() {
	vector<int> ans = solution(4);
}
