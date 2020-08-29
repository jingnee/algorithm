/*Ãß¾ïÀÇ 2048*/

#include<iostream>
#include<queue>
using namespace std;

int N;
int map[20][20];
int map2[20][20];

int main() {
	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		char dir[5];
		int d;
		cin >> N >> dir;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
				map2[i][j] = 0;
			}
		}

		if (!strcmp(dir, "left")) {
			for (int i = 0; i < N; i++) {
				queue<int> que;
				for (int j = 0; j < N; j++) {
					if (map[i][j] != 0)que.push(map[i][j]);
				}
				int index = 0;
				while (!que.empty()) {
					int num = que.front();
					que.pop();
					if (!que.empty() && num == que.front()) {
						map2[i][index++] = num * 2;
						que.pop();
					}
					else {
						map2[i][index++] = num;
					}
				}
			}

		}

		else if (!strcmp(dir, "right")) {
			for (int i = 0; i < N; i++) {
				queue<int> que;
				for (int j = N-1; j >= 0; j--) {
					if (map[i][j] != 0)que.push(map[i][j]);
				}
				int index = N-1;
				while (!que.empty()) {
					int num = que.front();
					que.pop();
					if (!que.empty() && num == que.front()) {
						map2[i][index--] = num * 2;
						que.pop();
					}
					else {
						map2[i][index--] = num;
					}
				}
			}

		}

		else if (!strcmp(dir, "up")) {
			for (int j = 0; j < N; j++) {
				queue<int> que;
				for (int i = 0; i < N; i++) {
					if (map[i][j] != 0)que.push(map[i][j]);
				}
				int index = 0;
				while (!que.empty()) {
					int num = que.front();
					que.pop();
					if (!que.empty() && num == que.front()) {
						map2[index++][j] = num * 2;
						que.pop();
					}
					else {
						map2[index++][j] = num;
					}
				}
			}

		}
		else if (!strcmp(dir, "down")) {
			for (int j = 0; j < N; j++) {
				queue<int> que;
				for (int i = N-1; i >= 0; i--) {
					if (map[i][j] != 0)que.push(map[i][j]);
				}
				int index = N-1;
				while (!que.empty()) {
					int num = que.front();
					que.pop();
					if (!que.empty() && num == que.front()) {
						map2[index--][j] = num * 2;
						que.pop();
					}
					else {
						map2[index--][j] = num;
					}
				}
			}

		}


		cout << "#" << test_case << endl;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cout << map2[i][j] << ' ';
			}cout << endl;
		}
	}
}
