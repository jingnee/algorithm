/*
1. 장훈이 키(B)보다 가장 근소한 차이로 큰 직원들 키의합을 찾아라. 출력은 합이아닌 차
2. 1<= N(직원수) <= 20,
	1<= 각 직원수의 키 <=10000
	1<= B(장훈이 키) <= 20,
3. 완전탐색을 하되, 각 직원수의 키의 합이 장훈이 키를 넘으면 더이상 탐색하지 않는다.
	경우의 수 20*19*18*17*...*1 
*/
#include<iostream>
using namespace std;

int min = 987654321;			//가장 작은 차
int tall[20];					//직원들 키
bool visit[20];					//i번째 직원 키 포함했는지 확인
bool check[200001];
int N, B;
void dfs(int index, int sum) {
	if (sum >= B) {
		check[sum] = true;
		int cha = sum - B;
		min = (cha < min) ? cha : min;
		return;
	}

	for (int i = index; i < N; i++) {
		if (!visit[i]) {			//포함하지 않은 직원의 경우에만 포함
			visit[i] = true;
			if(!check[sum+tall[i]])			//나온적 없는 sum값에 대해서만 판단
			dfs(i+1, sum + tall[i]);
			visit[i] = false;
			
		}
	}
}
int main() {
	int T, max;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		max = 0;
		cin >> N >> B;
		for (int i = 0; i < N; i++) {
			cin >> tall[i];
			max += tall[i];
		}

		dfs(0, 0);
		cout << "#" << test_case << " " << min << endl;

		for (int i = 0; i < N; i++) //초기화
			visit[i] = false;
		for (int i = B; i <= max; i++)check[i] = false;
		min = 987654321;

	}
}