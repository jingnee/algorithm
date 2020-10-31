//몬스터를 처치하자!
#include <iostream>
#include <time.h>
using namespace std;

struct skill {
	int cool = 0;
	int damage = 0;
};

int N, HP, ans = 1e9;
skill skills[5];
int leftTime[5];
int check[100];

void DFS(int tot, int time, int *left) {
	if (ans < time)return;
	if (tot >= HP) {
		ans = (ans > time) ? time : ans;
		//cout << "time: " << time << endl;
		return;
	}

	int temp[5];
	bool flag = false;

	for (int i = 0; i < N; i++) {
		flag = false;
		//DFS끝날때마다 temp값을 초기화해줘야해서 여기서함 (이거안해서 스킬을 계속 쓰는 경우가 생김..)
		for (int k = 0; k < N; k++)temp[k] = left[k];
		//쿨타임 없는 경우 있으면 굳이 다른거 시도해볼 필요 없음 -> 여기서 시간 엄청 단축 시간초과 해결
		if (i<N - 1 && temp[i] != 0)continue;

		for (int j = 0; j < N; j++) {
			//이 스킬 사용
			if (i == j && temp[i]==0) {
				temp[j] = skills[j].cool - 1;

				flag = true;
			}
			else {
				if (temp[j] > 0) temp[j]--;
			}
		}
		//i번 스킬 사용
		if (flag)
			DFS(tot + skills[i].damage, time + 1, temp);
		//스킬모두 쿨타임
		else
			DFS(tot, time + 1, temp);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	//clock_t start, end;

	//start = clock();

	cin >> N >> HP;
	for (int i = 0; i < N; i++) {
		cin >> skills[i].cool >> skills[i].damage;
	}

	DFS(0, 0, leftTime);
	//end = clock();
	cout << ans << endl;
	//cout << "함수 실행 시간: " << (double)(end - start);
}
