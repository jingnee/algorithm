//평범한 배낭
#include <iostream>
#include <algorithm>
using namespace std;

int N, K;
int kg[100001], weight[102], value[102];

int main() {
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> weight[i] >> value[i];
	}

	for (int i = 1; i <= N; i++) {
		for (int j = K; j >= 1; j--) {
			if (weight[i] <= j)
				kg[j] = max(kg[j], kg[j - weight[i]] + value[i]);
			else break;
		}
	}
	cout << kg[K];
}
