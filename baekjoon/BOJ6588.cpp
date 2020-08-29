/*골드 바흐의 추측*/
#include <iostream>
#include <cstring>
using namespace std;

#define MAX 1000001

bool prime[MAX];

void makePrime() {
	memset(prime, true, sizeof(prime));
	prime[0] = prime[1] = false;
	for (int i = 2; i*i < MAX; i++) {
		if (prime[i])
		for (int j = i*i; j < MAX; j+=i)prime[j] = false;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	makePrime();
	while (1) {
		int num;
		cin >> num;
		if (num == 0)break;
		int left = 2;
		int right = num - 2;
		bool flag = true;
		while (!prime[left] || !prime[right]) {
			left++, right--;
			if (left > num || right < 0) {
				flag = false;
				break;
			}
		}
		if (flag) 
			cout << num << " = " << left << " + " << right << "\n";
		else cout << "Goldbach's conjecture is wrong.\n";
	}
}
