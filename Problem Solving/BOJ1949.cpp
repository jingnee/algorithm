/*��� ����*/
#include <iostream>
#include <vector>
using namespace std;

int N;
int resiNum[10000];
int visit[10000];
int DP[10000][2];					//DP[i][0]:i��° ������ ���µ� i����尡 ���Ե��� ���� ���, [i][1]: ���Ե� ���
vector<int> residents[10000];

void choose(int num) {
	//�ڽ� Ž��
	for (int i = 0; i < residents[num].size(); i++) {
		int child = residents[num][i];
		if (visit[child])continue;
		visit[child] = 1;
		choose(child);
		//����尡 ���Ե� ���
		DP[num][1] += DP[child][0];
		DP[num][0] += (DP[child][0] < DP[child][1]) ? DP[child][1] : DP[child][0];
	}
	DP[num][1] += resiNum[num];
}


int main() {
	cin >> N;
	for (int i = 0; i < N; i++)cin >> resiNum[i];
	for (int i = 1; i < N; i++) {
		int r1, r2;
		cin >> r1 >> r2;
		--r1, --r2;
		residents[r1].push_back(r2);
		residents[r2].push_back(r1);
	}
	visit[0] = 1;
	choose(0);
	int answer = (DP[0][0] < DP[0][1]) ? DP[0][1] : DP[0][0];
	cout << answer << "\n";
}