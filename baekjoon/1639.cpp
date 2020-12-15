//행운의 티켓
#include <iostream>
#include <string>
using namespace std;

string numbers;
int sum[101];

int main() {
	cin >> numbers;
	
	sum[0] = 0;
	sum[1] = numbers[0] - '0';
	for (int i = 1; i < numbers.size(); i++)sum[i + 1] = sum[i] + (numbers[i] - '0');
	
	int length = numbers.size();
	for (int len = numbers.size() / 2; len >= 0; len--) {
		for (int idx = len, i = 0; idx + len <= length; idx++, i++) {
			if (sum[idx] - sum[i] == sum[idx + len] - sum[idx]) {
				cout << len*2;
				return 0;
			}
		}
	}
	cout << "0";
}