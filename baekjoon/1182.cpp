//부분수열의 합
#include<iostream>
using namespace std;

int N, S, answer;
int arr[20];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> S;
	for (int i = 0; i < N; i++)cin >> arr[i];

	for (int i = 1; i < (1 << N); i++) {
		int sum = 0;
		for (int j = 0; j < N; j++) {
			if (i&(1 << j)) 
				sum += arr[j];
		}
		if (sum == S)answer++;
	}
	cout << answer;
}