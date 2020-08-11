/*Cubeditor
접두사==접미사 길이가 가장긴 경우를 찾으면됨
방법은 KMP에서 실패함수 만드는 알고리즘*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string str;
int ans;

vector<int> findLong(string str) {
	//pi배열 초기화
	vector<int>pi(str.size(), 0);

	int begin = 1;
	int m = 0;

	while(begin + m < str.size()) {
		if (str[begin + m] == str[m]) {
			m++;
			pi[begin + m - 1] = m;
		}
		else {
			if (m == 0)begin++;
			else {
				//다르면 비교시작할값을 m만큼(같다고 비교해온m)더했다가, 같다고 비교한 문자에서 접두사 접미사가 같은만큼 다시 빼줌
				begin += m - pi[m - 1];
				m = pi[m - 1];
			}
		}
	}
	return pi;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		vector<int> pi = findLong(str.substr(i, str.size()));

		sort(pi.begin(), pi.end());
		ans = max(ans, pi.back());
	}

	cout << ans << "\n";
}
