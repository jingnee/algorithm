/*소가 정보섬에 올라온 이유*/
#include <iostream>
using namespace std;

int N, Q, sum;
int cows[200001];
int FourCows[200001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int num, cha;
	cin >> N >> Q;
	for (int i = 0; i < N; i++) cin >> cows[i];
	FourCows[0] = cows[0] * cows[1] * cows[2] * cows[3];
	
	for (int i = 1; i < N; i++) {
		int next_num = i + 3;
		if (next_num >= N)next_num -= N;
		FourCows[i] = FourCows[i - 1] / cows[i - 1] * cows[next_num];
	}
	for (int k = 0; k < N; k++)sum += FourCows[k];

	for (int i = 0; i < Q; i++) {
		cin >> num;
		num--;
		//cha = N - num;
		for (int j = num, k = 0; k < 4; j--, k++) {
			sum -= FourCows[(N + j) % N];
			FourCows[(N + j) % N] *= -1;
			sum += FourCows[(N + j) % N];
		}
		cout << sum << "\n";
	}
}
