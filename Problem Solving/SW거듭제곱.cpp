#include<iostream>
using namespace std;

int N, M;

int power(int num, int cnt) {
	if (cnt == M) {
		return num;
	}
	num *= N;
	power(num, cnt + 1);
}

int main() {

	for (int test_case = 1; test_case <= 10; test_case++) {
		int num;
		cin >> num;
		cin >> N >> M;
		cout << "#" << num << " " << power(1, 0) << endl;
	}
}