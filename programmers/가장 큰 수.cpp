#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector<string> num;

string solution(vector<int> numbers) {
	string answer = "";
	int zero_cnt = 0;
	for (int i = 0; i<numbers.size(); i++) {
		num.push_back(to_string(numbers[i]));
		if (numbers[i] == 0)zero_cnt++;
	}
	if (zero_cnt == numbers.size())return "0";

	sort(num.begin(), num.end(), [](string s1, string s2) {
		return (s1 + s2) >(s2 + s1); });
	for (auto n : num)answer += n;
	return answer;
}