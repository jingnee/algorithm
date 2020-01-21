//피자 굽기
#include<iostream>
using namespace std;

int N, D;
int oven[300000];
int pizza[300000];
int mini = 987654321;

int main() {
	int answer = 0;
	cin >> D >> N;
	for (int i = 0; i < D; i++) {		//oven[i]=n;		//oven i깊이까지 가는데 가장 좁은 지름
		int size;
		cin >> size;
		if (size > mini)oven[i] = mini;
		else {
			mini = size;
			oven[i] = size;
		}
	}
	for (int j = 0; j < N; j++)cin >> pizza[j];

	int j = 0;
	for (int i = D - 1; i >= 0; i--) {		//오븐은 아래위치부터 피자는 첫번째부터 비교
		if (oven[i] >= pizza[j]) {
			j++;
			if (j == N) {
				answer = i + 1;
				break;
			}
		}
	}

	cout << answer << endl;
}