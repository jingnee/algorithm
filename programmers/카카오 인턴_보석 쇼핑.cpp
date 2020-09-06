/*보석 쇼핑*/
#include <iostream>
#include <set>
#include <map>
#include <string>
#include <string>
#include <vector>

using namespace std;

set<string> types;
vector<int> solution(vector<string> gems) {
	vector<int> answer;
	for (auto g : gems)types.insert(g);
	int tot = types.size();
	int start = 0, end = gems.size() - 1, s = 0;
	map<string, int> m;
	for (int i = 0; i < gems.size(); i++) {
		m[gems[i]]++;
		if (m.size() == tot) {
			while (m[gems[s]] > 1) {
				m[gems[s]]--;
				s++;
			}
			if (end - start > i - s) {
				start = s;
				end = i;
			}
		}
	}
	answer.push_back(start + 1);
	answer.push_back(end + 1);
	return answer;
}

int main() {
	//vector<int> ret = solution({ "DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA" });
	//vector<int> ret = solution({"AA", "AB", "AC", "AA", "AC"});
	//vector<int> ret = solution({"XYZ", "XYZ", "XYZ"});
	vector<int> ret = solution({"ZZZ", "YYY", "NNNN", "YYY", "BBB"});
	cout << ret[0] << ", " << ret[1];
}
