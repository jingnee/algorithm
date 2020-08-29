/*가능한 시험 점수*/
#include <iostream>
#include <cstring>
using namespace std;

int arr[100];
int visit[10001];
int N, answer, temp;

int main() {
	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		cin >> N;
		visit[0] = 1;
		answer = 0, temp = 0;
		for (int i = 0; i < N; i++) {
			cin >> arr[i];
			temp += arr[i];
			for (int j = temp; j >= 0; j--) {
				if (visit[j]) {
					visit[j + arr[i]]++;
				}
			}
			visit[arr[i]]++;
		}
		for (int i = 0; i < 10001; i++)if (visit[i] > 0)answer++;

		cout << "#" << test_case << " " << answer << "\n";
		memset(arr, 0, sizeof(arr));
		memset(visit, false, sizeof(visit));
	}
}
