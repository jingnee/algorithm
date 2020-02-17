/*러시아 국기 같은 깃발*/
#include<iostream>
using namespace std;

int N, M;
int countColor(int w,int b, int r, char **map) {
	int answer = 0;
	for (int w_index = 1; w_index <= w; w_index++) {
		for (int j = 0; j < M; j++) {
			if (map[w_index][j] != 'W')answer++;
		}
	}
	for (int b_index = w+1; b_index <= w + b; b_index++) {
		for (int j = 0; j < M; j++) {
			if (map[b_index][j] != 'B')answer++;
		}
	}
	for (int r_index = w + b+1; r_index < N - 1; r_index++) {
		for (int j = 0; j < M; j++) {
			if (map[r_index][j] != 'R')answer++;
		}
	}
	return answer;
}

int main() {
	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		int answer = 0;
		int mini = 987654321;
		cin >> N >> M;
		char **map = new char*[N];
		for (int i = 0; i < N; i++) {
			map[i] = new char[M];
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> map[i][j];
			}
		}
		for (int i = 0; i < M; i++) {
			if (map[0][i] != 'W')answer++;
			if (map[N - 1][i] != 'R')answer++;
			if (N == 3 && map[1][i] != 'B')answer++;
		}
		
		if (N > 3) {
			int arr[3];
			for (int b = 1; b <= N - 2; b++) {
				arr[1] = b;
				for (int w = 0; w <= N - 2 - b; w++) {
					arr[0] = w;
					arr[2] = N - 2 - w - b;
					int mm = countColor(arr[0], arr[1], arr[2], map);
					if (mm < mini)mini = mm;
				}
			}
			answer += mini;
		}

		cout << "#" << test_case << " " << answer << "\n";
	}
}