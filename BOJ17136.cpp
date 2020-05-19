/*색종이 붙이기*/
#include <iostream>
#include <algorithm>
using namespace std;

int paper[10][10];
int totalNum;
int answer = 2e9;
int paperCnt[6] = { 0,5,5,5,5,5};

//색종이 붙이는 함수
void attachPaper(int r, int c, int size, int n) {
	for (int i = r; i < r + size; i++) {
		for (int j = c; j < c + size; j++) {
			paper[i][j] = n;
		}
	}
}

//색종이 붙일 수 있는지 판별하는 함수
bool isAttachPaper(int r, int c, int size) {
	for (int i = r; i < r + size; i++) {
		for (int j = c; j < c + size; j++) {
			if (!paper[i][j])return false;
		}
	}
	return true;
}

void DFS(int r, int c, int attchedNum) {
	//1찾을때까지 반복
	while (paper[r][c] == 0) {
		if (++r >= 10) {
			if (++c >= 10) {
				answer = min(answer, attchedNum);
				return;
			}
			r = 0;
		}
	}

	//이미 최솟값보다 종이 더 많이 붙였으면 찾을 필요 없음
	if (answer <= attchedNum)return;

	//5부터 모든 크기를 실행
	for (int size = 5; size > 0; size--) {
		if (r + size > 10 || c + size > 10 || paperCnt[size] == 0)continue;

		if (isAttachPaper(r, c, size)) {
			//색종이 붙이기
			attachPaper(r, c, size, 0);
			paperCnt[size]--;
			DFS(r, c, attchedNum + 1);

			//색종에 제거(back tracking)
			attachPaper(r, c, size, 1);
			paperCnt[size]++;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 10; j++) {
			cin >> paper[i][j];
			if (paper[i][j])totalNum++;
		}
	}
	if (totalNum == 100) {
		cout << "4\n";
		return 0;
	}
	if (totalNum == 0) {
		cout << "0\n";
		return 0;
	}

	DFS(0, 0, 0);
	if (answer == 2e9) {
		cout << "-1\n";
		return 0;
	}
	cout << answer << "\n";
}
