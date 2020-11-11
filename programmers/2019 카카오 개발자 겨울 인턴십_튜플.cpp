#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
bool visit[100001];

vector<int> solution(string s) {
	vector<int> answer;
	int s_size = s.size();
	int cnt = 0;
	vector<int> numbers[501];
	for (int i = 1; i < s_size - 1; i++) {
		int idx = i;
		vector<int> temp;
		if (s[i] == '{') {
			idx = ++i;
			while (s[i] != '}') {
				if (s[i++] == ',') {
					string st = s.substr(idx, i - idx - 1);
					idx = i;
					reverse(st.begin(),st.end());
					int ten = 1;
					int num = 0;
					for (int j = 0; j < st.size(); j++) {
						num += (st[j] - '0')*ten;
						ten *= 10;
					}
					//numbers[cnt].push_back(num);
					temp.push_back(num);
				}
			}
			//} 직전에 있는 숫자
			string st = s.substr(idx, i - idx);
			idx = ++i;
			reverse(st.begin(), st.end());
			int ten = 1;
			int num = 0;
			for (int j = 0; j < st.size(); j++) {
				num += (st[j] - '0')*ten;
				ten *= 10;
			}
			//numbers[cnt].push_back(num);
			temp.push_back(num);
			int temp_size = temp.size();
			numbers[temp_size] = temp;
			cnt = (cnt<temp_size)?temp_size:cnt;
		}
	}
	for (int k = 1; k <= cnt; k++) {
		for (int l = 0; l < numbers[k].size(); l++) {
			if (!visit[numbers[k][l]]) {
				answer.push_back(numbers[k][l]);
				visit[numbers[k][l]] = true;
				break;
			}
		}
		//answer.push_back(numbers[k].back());
	}
	return answer;
}
