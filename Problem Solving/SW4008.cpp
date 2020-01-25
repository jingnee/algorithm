/*���ڸ����
1. ����ī�� N���� ������ī�� N-1���� �־����� ����� ���� �ִ񰪰� �ּڰ��� ���̴�?
�� ������ �����ڿ켱������ ��������ʰ� ���ʿ��� ������ ������ �����
2. 3<=N(���ڰ���)<=12, �����ڰ����� N-1, ����Ȱ��� ������ -1�￡�� 1�����
3. �������� ������ ���� �迭�� �̿��� ��ͷ� ����Ž��.
+���������ϴ���, -���� �����ϴ���, *���� �����ϴ���, /���� �����ϴ���
*/

#include<iostream>
#include<vector>
using namespace std;

int N;
vector<int> answer;
vector<string> oper;
int number[13];
int cnt[4];			//������ ����, 0:+, 1:-, 2:*, 3:/
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