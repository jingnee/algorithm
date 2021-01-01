//단어 수학
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int N, ans;
int alpha[26];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		string word;
		cin >> word;
		int len = word.size();
		int pow = 1;
		for (int j = len - 1; j >= 0; j--) {
			alpha[word[j] - 'A'] += pow;
			pow *= 10;
		}
	}
	sort(alpha, alpha + 26);
	int num = 9;
	for (int i = 25; i >= 0; i--) {
		if (alpha[i] > 0) {
			ans += (alpha[i] * num);
			num--;
		}
	}
	cout << ans;
}