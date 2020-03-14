#include <iostream>
#include <string>
#include <vector>
using namespace std;

int solution(string s) {
	int answer = s.size();
	for (int n = 1; n <= s.size()/2+1; n++) {
		vector<char> v;
		int cnt = 1;
		int index = 0;

		while (1) {
			if (index + n > s.size()) {
				for (int i = index; i < s.size(); i++)v.push_back(s[i]);
				break;
			}
			string str1 = s.substr(index, n);
			string str2 = s.substr(index + n, n);
			if (str1.compare(str2) == 0) {
				cnt++;
				index += n;
			}
			else {
				if (cnt > 1) {
					vector<char>temp;
					while (cnt > 0) {
						temp.push_back(cnt % 10);
						cnt /= 10;
					}
					for (int i = 0; i < temp.size(); i++)v.push_back(temp[i]);
				}
				cnt = 1;
				for (int i = index; i < index + n; i++) {
					v.push_back(s[i]);
				}
				index += n;
			}
		}
		answer = (answer > v.size()) ? v.size() : answer;
	}
	return answer;
}

int main() {
	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		string s;
		cin >> s;
		cout << test_case<<": " << solution(s) << endl;
	}
}