/*숫자만들기
1. 숫자카드 N개와 연산자카드 N-1개가 주어질때 연산된 값의 최댓값과 최솟값의 차이는?
단 연산은 연산자우선순위를 고려하지않고 왼쪽에서 오른쪽 순으로 진행됨
2. 3<=N(숫자갯수)<=12, 연산자갯수는 N-1, 연산된값의 범위는 -1억에서 1억사이
3. 연산자의 갯수를 담은 배열을 이용해 재귀로 완전탐색.
+갯수존재하는지, -갯수 존재하는지, *갯수 존재하는지, /갯수 존재하는지
*/

#include<iostream>
#include<vector>
using namespace std;

int N;
vector<int> answer;
vector<string> oper;
int number[13];
int cnt[4];			//연산자 숫자, 0:+, 1:-, 2:*, 3:/
int max_num;
int min_num;

void DFS(int sum, int index, int p, int s, int m, int d) {
	if (index == N) {
		if (sum < min_num)min_num = sum;
		if (sum > max_num)max_num = sum;
		return;
	}

	if (p) 
		DFS(sum + number[index], index+1, p - 1, s, m, d);
	if (s)
		DFS(sum - number[index], index + 1, p, s - 1, m, d);
	if (m)
		DFS(sum*number[index], index + 1, p, s, m - 1, d);
	if (d)
		DFS(sum / number[index], index + 1, p, s, m, d - 1);
}
int main() {
	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		cin >> N;
		for (int i = 0; i < 4; i++)cin >> cnt[i];
		for (int i = 0; i < N; i++)cin >> number[i];

		max_num = -9999999;
		min_num = 9999999;

		DFS(number[0], 1, cnt[0], cnt[1], cnt[2], cnt[3]);
		int answer = max_num - min_num;
		cout << "#" << test_case << " " << answer << endl;
	}
}