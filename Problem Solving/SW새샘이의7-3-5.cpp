#include<iostream>
#include<algorithm>
using namespace std;

int numbers[7];
int main() {
	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		int answer = 0;
		for (int i = 0; i < 7; i++)cin >> numbers[i];
		sort(numbers, numbers + 7);
		int num[35];
		int w = 0;
		for (int i = 6; i > 1; i--) {
			for (int j = i - 1; j > 0; j--) {
				for (int k = j - 1; k >= 0; k--) {
					num[w++] = numbers[i] + numbers[j] + numbers[k];
				}
			}
		}
		sort(num, num + 35);
		//값이 같은 수는 빼야함
		int cnt = 0, n = 0;
		for (int i = 34; i >= 0; i--) {
			if (num[i] != num[i - 1])cnt++;
			if (cnt == 5) {
				n = i;
				break;
			}
		}
		answer = num[n];
		cout << "#" << test_case << " " << answer<<endl;
	}
}