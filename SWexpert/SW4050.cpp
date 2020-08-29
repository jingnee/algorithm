#include <iostream>
#include <algorithm>
using namespace std;

int N;
int main() {
	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		cin >> N;
		int *clothes = new int[N];
		for (int i = 0; i < N; i++) {
			cin >> clothes[i];
		}

		sort(clothes, clothes + N);

		//int m = N / 3;
		int sum = 0;
		int j = 1;
		for (int i = N-1; i >=0 ; i--) {
			if (j != 3)sum += clothes[i];
			j++;
			if (j == 4)j = 1;
		}
		cout << "#" << test_case << " " << sum << endl;
	}
}