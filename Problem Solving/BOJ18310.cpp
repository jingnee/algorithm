/*안테나*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

long long total;
vector<int> antenas;
int N;

int binary(int s, int e) {
	int left = s;
	int right = e;
	int dist = 2e9, ret = 0;

	while (left < right) {
		int mid = (left + right) / 2;
		int num = antenas[mid];
		int temp = 0;

		for (int i = 0; i < antenas.size(); i++)temp += abs(antenas[i] - num);
		if (temp <= dist) {
			right = mid - 1;
			dist = temp;
			ret = num;
		}
		else left = mid + 1;
	}
	return ret;
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int inputNum;
		cin >> inputNum;
		antenas.push_back(inputNum);
	}

	sort(antenas.begin(), antenas.end());
	
	cout << binary(0, N - 1);
}
