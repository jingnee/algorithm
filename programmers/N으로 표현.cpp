//N으로 표현
#include <iostream>
#include <vector>
using namespace std;

int conti[9] = { 0,1,11,111,1111,11111, 111111, 1111111, 11111111 };
vector<vector<int>> vec;

int solution(int N, int number) {
	if (N == number)return 1;

	vector<int> newvec;
	newvec.push_back(N);
	vec.push_back(newvec);
	vec.push_back(newvec);

	for (int i = 2; i <= 8; i++) {
		vector<int>newvec;
		newvec.push_back(N*conti[i]);
		if (N*conti[i] == number)return i;

		for (int j = 1; j <= i / 2; j++) {
			int k = i - j;
			for (auto a : vec[j]) {
				for (auto b : vec[k]) {
					if (a + b == number || a - b == number || a*b == number || a / b == number || b / a == number || b - a == number)return i;
					newvec.push_back(a + b);
					if (a - b > 0)newvec.push_back(a - b);
					if (b - a > 0)newvec.push_back(b - a);
					newvec.push_back(a*b);
					if (a / b != 0)newvec.push_back(a / b);
					if (b / a != 0)newvec.push_back(b / a);
				}
			}
		}
		vec.push_back(newvec);
	}
	return -1;
}

int main() {
	cout << solution(1, 99999);
}
