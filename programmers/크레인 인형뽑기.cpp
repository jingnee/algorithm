#include <stack>
#include <vector>
using namespace std;

int height[30];

int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0;
	bool flag = false;
	//height정하기
	int N = board.size();
	for (int j = 0; j < N; j++) {
		flag = false;
		for (int i = 0; i < N; i++) {
			if (board[i][j] != 0) {
				height[j] = i;
				flag = true;
				break;
			}
		}
		if (!flag)height[j] = N - 1;
	}

	stack<int> st;
	for (auto m : moves) {
		//그 위치에 인형이 없으면 인형 안뽑아
		if (height[m - 1] == N)continue;

		int new_doll = board[height[m - 1]][m - 1];

		if (st.empty()) {
			st.push(new_doll);
		}
		else {
			if (st.top() == new_doll) {
				st.pop();
				answer += 2;
			}
			else {
				st.push(new_doll);
			}
		}
		height[m - 1]++;
	}
	return answer;
}
