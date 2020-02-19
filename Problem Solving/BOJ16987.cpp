/*계란으로 계란치기*/
#include<iostream>
using namespace std;

int N;
int eggs[8][2];
int maxx;

void smashEgg(int eggNum) {
	if (eggNum == N) {
		int broken = 0;
		for (int i = 0; i < N; i++)	if (eggs[i][0] <= 0) broken++;
		maxx = (maxx < broken) ? broken : maxx;
		return;
	}
	if (eggs[eggNum][0] <= 0)smashEgg(eggNum + 1);
	else {
		//여기판단 안해줘서 계속 틀림 ㅜㅜ
		bool flag = false;					//내려쳤는지 안쳤는지 확인
		for (int i = 0; i < N; i++) {
			if (i != eggNum && eggs[i][0] > 0) {			//손에 들고 있는 계란이랑 다른 계란이고, 깰려는 계란이 이미 깨지지 않았을 경우
				eggs[eggNum][0] -= eggs[i][1];
				eggs[i][0] -= eggs[eggNum][1];
				flag = true;
				smashEgg(eggNum + 1);

				eggs[eggNum][0] += eggs[i][1];
				eggs[i][0] += eggs[eggNum][1];
			}
		}
		if (flag == false)smashEgg(N);			//내리칠게 없으면 다음 계란으로도 내려칠게 없으므로 끝

	}

}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> eggs[i][0] >> eggs[i][1];
	}
	smashEgg(0);
	cout << maxx << endl;
}