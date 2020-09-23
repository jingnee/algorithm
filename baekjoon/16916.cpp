//부분 문자열
#include <iostream>
#include <vector>
#include <string>
using namespace std;

string S, P;
int answer = 0;
vector<int> getFailure() {
	int begin = 1, m = 0;
	vector<int>pi(P.size(), 0);

	while (begin + m < P.size()) {
		//접두 접미 일치
		if (P[m] == P[begin + m]) {
			m++;
			pi[begin + m - 1] = m;
		}
		else {
			//일치하는게 하나도 없을때
			if (m == 0)begin++;
			//일치하다가 안맞을때 m과 begin갱신
			else {
				begin += m - pi[m - 1];
				m = pi[m - 1];
			}
		}
	}
	return pi;
}

int main() {
	cin >> S >> P;
	vector<int>pi = getFailure();
	int begin = 0, m = 0;

	while (begin + m < S.size()) {
		if (m < P.size() && S[begin + m] == P[m]) {
			m++;
			if (m == P.size()) {
				answer = 1;
				break;
			}
		}
		else {
			if (m == 0)begin++;
			else {
				begin += m - pi[m - 1];
				m = pi[m - 1];
			}
		}
	}

	cout << answer;
}
