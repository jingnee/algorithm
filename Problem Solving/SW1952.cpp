//������
#include<iostream>
using namespace std;

int price[4];
int day[12];
int answer[12];				//answer[i]=j		i������ j�� ������
void DP(int num) {
	if (num == 12)return;
	if (num == 0)answer[num] = (day[num] * price[0] < price[1]) ? day[num] * price[0] : price[1];
	else if (num == 1) {
		answer[num] = (answer[num - 1] + day[num] * price[0] < answer[num - 1] + price[1]) ? answer[num - 1] + day[num] * price[0] : answer[num - 1] + price[1];
	}
	else if(num==2){	//3�ް�, ������+�̹��� �Ϸ��갪, ������+ �̹��� �ް�갪
		int mini = price[2];
		if (mini > answer[num - 1] + day[num] * price[0]) mini = answer[num - 1] + day[num] * price[0];
		if (mini > answer[num - 1] + price[1])mini = answer[num - 1] + price[1];
		answer[num] = mini;
	}
	else {	//num�� 3�̻��̸� //3�ް�+num-3��, ������+�̹��� �Ϸ��갪, ������+�̹��� �ް�갪
		int mini = price[2] + answer[num - 3];
		if(mini>answer[num - 1] + day[num] * price[0]) mini = answer[num - 1] + day[num] * price[0];
		if (mini > answer[num - 1] + price[1])mini = answer[num - 1] + price[1];
		answer[num] = mini;
	}
	DP(num + 1);
}

int main() {
	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		cin >> price[0] >> price[1] >> price[2] >> price[3];
		for (int i = 0; i < 12; i++)cin >> day[i];

		DP(0);
		int ans = answer[11];
		if (ans > price[3])ans = price[3];
		cout << "#" << test_case << " " << ans << endl;
	}
}