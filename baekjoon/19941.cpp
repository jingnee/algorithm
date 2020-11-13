//ÇÜ¹ö°Å ºÐ¹è
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string str;
int N, K, answer;
int main() {
	cin >> N >> K >> str;
	int idx = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == 'H')continue;
		while (idx < str.size() && idx-i < K) {
			if (abs(idx-i) <= K && str[idx] == 'H')break;
			idx++;
		}
		if (str[idx] == 'H') {
			answer++;
			idx++;
		}
	}
	cout << answer;
}