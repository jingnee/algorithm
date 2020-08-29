/*모든 순열*/
#include <iostream>
using namespace std;

int N;
int num[8];
bool visit[9];

void print() {
	for (int i = 0; i < N; i++)cout << num[i] << " ";
	cout << "\n";
}

void permutation(int cnt) {
	if (cnt == N) {
		print();
		return;
	}
	for (int i = 1; i <= N; i++) {
		if (visit[i])continue;
		visit[i] = true;
		num[cnt] = i;
		permutation(cnt + 1);
		visit[i] = false;
	}
}

int main() {
	cin >> N;
	permutation(0);
}
