/*¿ä¸®»ç*/
#include<iostream>
using namespace std;

int N;
int map[16][16];
int min_answer;
int visit[16];

int cntNum() {
	int a = 0;
	int b = 0;
	for (int i = 0; i < N; i++) {
		if (visit[i] == true) {
			for (int j = 0; j < N; j++) {
				if (visit[j] == true)a = a + map[i][j];
			}
		}
		else if (visit[i] == false) {
			for (int j = 0; j < N; j++) {
				if (visit[j] == false)b = b + map[i][j];
			}
		}
	}
	int cha = (a - b < 0) ? b - a : a - b;
	return cha;
}

void combi(int index, int cnt) {
	if (cnt == N / 2) {
		int mini = cntNum();
		if (mini < min_answer)min_answer = mini;
		return;
	}
	for (int i = index; i < N; i++) {
		if (visit[i] != true) {
			visit[i] = true;
			combi(i, cnt+1);
			visit[i] = false;
		}
	}
}

int main() {
	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		min_answer = 987654321;
		cin >> N;
		for (int i = 0; i < N; i++)visit[i] = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
			}
		}

		combi(0, 0);
		cout << "#" << test_case << " " << min_answer << "\n";
	}
}