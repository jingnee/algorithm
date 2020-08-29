/*병사 배치하기*/
#include <iostream>
using namespace std;

int soldier[2000];
int DP[2000];
int N, answer;
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) 
		cin >> soldier[i];
	
	DP[N - 1] = 1;
	answer = 1;
	for (int i = N-2; i >= 0; --i) {
		int num = 1;
		for (int j = i + 1; j < N; j++) {
			if (soldier[i] > soldier[j])
				num = (num < DP[j] + 1) ? DP[j] + 1 : num;
		}
		DP[i] = num;
		answer = (answer < num) ? num : answer;
	}

	cout << N-answer << "\n";
}
