//체육복
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = n - lost.size();
	int j = 0;
	sort(lost.begin(), lost.end());
	sort(reserve.begin(), reserve.end());

	for (int i = 0; i < lost.size(); i++) {
		while (j < reserve.size() && lost[i] - reserve[j] > 1)j++;
		if (j == reserve.size())break;
		if (abs(lost[i] - reserve[j]) <= 1) {
			//lost의 다음값이랑 reserve의 현재값이 같을때
			if (i < lost.size() - 1 && reserve[j] == lost[i+1])continue;
			//reserve의 다음값이랑 lost의 현재값이 같을때
			if (j < reserve.size() - 1 && reserve[j + 1] == lost[i])j++;
			answer++;
			j++;
		}
	}
	return answer;
}

int main() {
	//cout << solution(5, { 2,4 }, { 1,3,5 });
	//cout << solution(5, { 2,4 }, { 3 });
	//cout << solution(3, { 3 }, { 1 });
	//cout << solution(10, { 1,2,3 }, { 4,5,6 });
	//cout << solution(10, { 4,5,6 }, { 1,2,3 });
	//5번 testcase 안되면
	cout << solution(7, { 2,3,4 }, { 1,2,3,6 });
}
