/* 나무자르기

*/

#include <iostream>
using namespace std;

long long result;
long long N, M;
long long trees[1000000];
int main() {
	cin >> N >> M;
	long long max_tree = 0;
	for (int i = 0; i < N; i++) {
		cin >> trees[i];
		if (max_tree < trees[i]) {
			max_tree = trees[i];
		}
	}

	long long left = 0, right = max_tree;
	long long mid;
	while (left <= right) {
		mid = (left + right) / 2;
		long long tall = 0;
		for (int i = 0; i < N; i++) 
			if (trees[i] > mid)tall += (trees[i] - mid);

		if (tall >= M) {
			left = mid+1;
			if (result < mid)result = mid;
		}
		
		else if(tall < M) right = mid - 1;

	}
	cout << result;
}