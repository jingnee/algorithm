/*시험*/
#include<iostream>
#include<vector>
#include<utility>
#include<cstring>
using namespace std;
#define MAX 2000

int N, T, P;
int test[MAX][MAX];
int tester[MAX][MAX];

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int TC;
	cin >> TC;
	for (int test_case = 1; test_case <= TC; test_case++) {
		cin >> N >> T >> P;
		int *scores = new int[T];			//문제당 점수 배열
		memset(scores, 0, sizeof(int)*T);

		for (int i = 0; i < N; i++) {
			int cnt = 0;
			for (int j = 0; j < T; j++) {
				cin >> test[i][j];
				if (test[i][j] == 0)scores[j]++;
				else cnt++;
			}
			tester[i][1] = cnt;
		}

		for (int i = 0; i < N; i++) {
			int score = 0;
			for (int j = 0; j < T; j++) {
				score += scores[j] * test[i][j];
			}
			tester[i][0] = score;
		}

		int rank = 1;
		for (int i = 0; i < N; i++) {
			if (i == P - 1)continue;
			if (tester[i][0] > tester[P - 1][0])rank++;				//점수가 더 높으면 rank++
			else if (tester[i][0] == tester[P - 1][0]) {			//점수가 같은데
				if (tester[i][1] > tester[P - 1][1])rank++;			//푼갯수가 더 많으면 rank++
				else if (tester[i][1] == tester[P - 1][1]) {		//푼갯수가 같다면
					if (i < P - 1)rank++;							//번호가 더 앞이면 rank++;
				}
			}
		}

		cout << "#" << test_case << " " << tester[P-1][0] << " " << rank << "\n";

	}
}


//int **test = new int*[N];			//전체 입력받는 배열
//for (int i = 0; i < N; i++) {
//	test[i] = new int[T];
//	memset(test[i], 0, sizeof(int)*T);
//}

//int **tester = new int*[N];					//tester[i][0]은 점수, tester[i][1]은 문제푼 갯수
//for (int i = 0; i < N; i++) {
//	tester[i] = new int[2];
//	memset(tester[i], 0, sizeof(int) * 2);
//}
