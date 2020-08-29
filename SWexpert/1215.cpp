#include<iostream>
using namespace std;

char map[9][9];
int N;
int main() {
	int Test_case=10;
	int answer = 0, flag = 0;
	//cin >> Test_case;
	for (int t = 1; t <= Test_case; t++) {
		cin >> N;
		answer = 0;
		for (int i = 0; i < 8; i++)cin >> map[i];
		if (N == 1) {
			answer = 64;
			cout << "#" << t << " " << answer << endl;
			continue;
		}
		for (int i = 0; i < 8; i++) {			//가로 회문찾기
			for (int j = 0; j <= 8 - N; j++) {
				if (map[i][j] == map[i][j + N - 1]) {
					int s = j + 1;
					int e = j + N - 2;
					while (s <= e) {
						if (map[i][s++] != map[i][e--]) {
							flag = 1;
							break;
						}
					}		
					if (flag == 0) {
						answer++;
						//cout << "answer: " << answer << ", i: " << i << ", j: " << j << endl;
					}
					flag = 0;
				}
			}
		}

		for (int j = 0; j < 8; j++) {			//세로 회문찾기
			for (int i = 0; i <= 8 - N; i++) {
				if (map[i][j] == map[i+N-1][j]) {
					int s = i + 1;
					int e = i + N - 2;
					while (s <= e) {
						if (map[s++][j] != map[e--][j]) {
							flag = 1;
							break;
						}
					}					
					if (flag == 0)
					{
						answer++;
						//cout << "answer: " << answer << ", i: " << i << ", j: " << j << endl;
					}
					flag = 0;
				}
			}
		}
		cout << "#" << t << " " << answer << endl;
		answer = 0;
	}
}