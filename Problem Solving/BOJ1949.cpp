/*우수 마을*/
#include <iostream>
#include <vector>
using namespace std;

int N;
int resiNum[10000];
int visit[10000];
int DP[10000][2];					//DP[i][0]:i번째 노드까지 가는데 i번노드가 포함되지 않은 경우, [i][1]: 포함된 경우
vector<int> residents[10000];

void choose(int num) {
	//자식 탐색
	for (int i = 0; i < residents[num].size(); i++) {
		int child = residents[num][i];
		if (visit[child])continue;
		visit[child] = 1;
		choose(child);
		//내노드가 포함된 경우
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