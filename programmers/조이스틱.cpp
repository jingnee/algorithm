//조이스틱
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int push[20];

int solution(string name) {
	int answer = 0;
	
	int n = name.size();
	int turn = n - 1;

	for (int i = 0; i < name.size(); i++) {
		answer += min(name[i] - 'A', 'Z' - name[i] + 1);
		
		int next = i + 1;
		while (next < n && name[next] == 'A')next++;
		turn = min(turn, i + n - next + min(i, n - next));
	}

	return answer + turn;
}

int main() {
	cout << solution("JEROEN");
}
