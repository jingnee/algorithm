//올림픽
#include <iostream>
using namespace std;

int country[1001][3];
int main() {
	int N, K;
	cin >> N >> K;
	int num;
	for (int i = 1; i <= N; i++) {
		cin >> num;
		for (int j = 0; j < 3; j++) {
			cin >> country[num][j];
		}
	}
	num = 1;
	for (int i = 1; i <= N; i++) {
		if (K == i)continue;			//비교하려는 국가가 등수를 알고싶은 국가랑 같으면 continue

		if (country[i][0] > country[K][0]) num++;				//금메달이 더 큰경우
		else if (country[i][0] == country[K][0]) {
			if (country[i][1] > country[K][1])num++;			//금메달 갯수는 같은데 은메달이 더 많은 경우
			else if (country[i][1] == country[K][1]) {
				if (country[i][2] > country[K][2])num++;		//금은 갯수는 같고 동메달이 더 많은 경우
			}
		}
	}
	cout << num << endl;
}