#include <string>
#include <math.h>
#include <vector>

using namespace std;
string friends = "ACFJMNRT";
char arr[8];
bool visit[8];
int answer;

void DFS(int cnt, vector<string> &data) {
	if (cnt == 8) {
		int n = data.size();
		bool flag = true;
		for (int i = 0; i<n; i++) {
			char from = data[i][0];
			char to = data[i][2];
			char op = data[i][3];
			int dist = data[i][4] - '0';
			int f_idx = 0; int t_idx = 0;
			for (int j = 0; j<8; j++) {
				if (arr[j] == from)f_idx = j;
				else if (arr[j] == to)t_idx = j;
			}
			if ((op == '=' && abs(f_idx - t_idx) != dist + 1) || (op == '<' && abs(f_idx - t_idx) >= dist + 1) || (op == '>' && abs(f_idx - t_idx) <= dist + 1)) {
				flag = false;
				break;
			}
		}
		if (flag)answer++;
		//cout<<(answer);
		return;
	}

	for (int i = 0; i<friends.size(); i++) {
		if (visit[i])continue;
		visit[i] = true;
		arr[cnt] = friends[i];
		DFS(cnt + 1, data);
		visit[i] = false;
	}
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
	for (int i = 0; i<8; i++) {
		visit[i] = false;
		arr[i] = ' ';
	}
	answer = 0;
	DFS(0, data);
	return answer;
}