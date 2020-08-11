/*찾기*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string T, P;
vector<int> ans;

vector<int> failurFunc() {
	vector<int> pi(P.size(), 0);
	int begin = 1;
	int m = 0;

	while (begin + m < P.size()) {
		if (P[begin + m] == P[m]) {
			m++;
			pi[begin + m - 1] = m;
		}
		else {
			if (m == 0)begin++;
			else {
				begin += m - pi[m - 1];
				m = pi[m - 1];
			}
		}
	}
	return pi;
}

void kmp() {
	vector<int> pi = failurFunc();
	
	int begin = 0;
	int m = 0;

	while (begin + m < T.size()) {
		if (m < P.size() && T[begin + m] == P[m]) {
			m++;
			//패턴 P의 길이까지 찾은경우
			if (m == P.size())ans.push_back(begin+1);
		}
		else { //불일치하거나 패턴을 찾은경우
			if (m == 0)begin++;
			else {
				begin += m - pi[m - 1];
				m = pi[m - 1];
			}
		}
	}
}

int main() {
	getline(cin, T);
	getline(cin, P);
	kmp();

	cout << ans.size() << "\n";
	for (auto r : ans)cout << r << " ";
}
