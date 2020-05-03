/*1루수가 누구야*/
#include <iostream>
#include <cstring>
using namespace std;

int player[10];
int talk[10][2];

//거짓말하는사람 idx를 받아서 모순이 발생하면 -1, 1루수가 다양하면 -2, 1루수가 단 한명 존재하면 1루수 번호를 리턴
int findLier(int idx) {
	memset(player, -1, sizeof(player));
	int ret = 0;
	int retNum = 0;
	int notNum = 0;
	int nott= 0;
	for (int i = 1; i <= 9; i++) {
		int n = talk[i][0];
		//거짓말 idx의 경우 값을 바꿔줌
		if (i == idx) {
			if (n == 0)n = 1;
			else n = 0;
		}
		//-1로 초기화되어있으므로 -1인경우 아직 그 선수가 1루수인지아닌지 판단 안했으므로 값을 넣어줌
		if (player[talk[i][1]] == -1)player[talk[i][1]] = n;
		//그 선수가 1루수인지 아닌지에 대한 값이랑 내가 판단하는 값이랑 다르면 모순이 발생한것이므로 -1리턴
		else if (player[talk[i][1]] != n)return -1;
	}
	//전체를 돌아보면서 1루수가 한명인지 조사
	for (int i = 1; i <= 9; i++) {
		if (player[i] == 1) {
			ret = i;
			retNum++;
		}
		if (player[i] == -1) {
			nott= i;
			notNum++;
		}
	}
	//1루수가 한명이면 당연히 그 1루수 번호 리턴
	if (retNum == 1)return ret;
	//1루수가 여러명인경우 -1
	else if (retNum > 1)return -1;
	//1루수가 0명일 경우 정해지지않은 선수들로 판별해 볼 수 있다.
	else {
		//정해지지 않은 선수가 1명이면 그 선수가 1루수가 될 수 있다.
		if (notNum == 1)return nott;
		//그렇지 않다면 -2리턴
		else return -2;
	}
}

int main() {
	for (int i = 1; i <= 9; i++) {
		for (int j = 0; j < 2; j++) {
			cin >> talk[i][j];
		}
	}

	int cnt = 0;
	int answer = 0;
	//모든 선수에대해 한번씩 거짓말을 해봄
	for (int i = 1; i <= 9; i++) {
		int ans = findLier(i);
		if (ans == -2) {
			cout << "-1\n";
			return 0;
		}
		if (ans != -1) {
			cnt++;
			answer = ans;
			if (cnt > 1) {
				cout << "-1\n";
				return 0;
			}
		}
	}
	if (answer == 0)cout << "-1\n";
	else cout << answer << "\n";
}


/*생각해봐야할 반례
1루수가 누구라고 딱 정해지지 않을 수 있다. 1루수가 없는데, 정해지지 않은 선수가 여러명이면 그건 안되는 경우
모순이 발생한 경우와 1루수가 여러명인 경우는 구분해야함
-> 나의 경우 모순이 발생했을때는 그냥 무시하는쪽으로 코드를 짰기때문에 만약 1번이 거짓말했을때는 1루수가 한명이고, 2번에 거짓말했을때는 1루수가 여러명인 경우
답이 -1이 되어야하는데, 1루수가 여러명인경우를 모순이 발생한것처럼 처리하면 -1이 아닌 1번이 거짓말했을때의 정답 선수가나옴
*/