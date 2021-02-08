//줄 서는 방법
#include <string>
#include <vector>

using namespace std;

long long facto = 1;
vector<int> solution(int n, long long k) {
	vector<int> answer;
	vector<int> numbers;
	for (int i = 1; i <= n; i++) {
		numbers.push_back(i);
		facto *= i;
	}
	k--;
	while (numbers.size()>1) {
		facto /= (long long)n;
		int idx = k / facto;
		answer.push_back(numbers[idx]);
		numbers.erase(numbers.begin() + idx);
		k %= facto;
		n--;
	}
	answer.push_back(numbers[0]);
	return answer;
}