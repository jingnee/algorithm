/*K번째 수
1. K번째 값은 K보다 작거나 같다!
2. 임의의 mid를 정하고 mid보다 작은 수의 갯수가 몇개인지 찾는다.
2-1. 그 갯수가 K보다 크다면 mid의 수를 줄이고, 크다면 mid를 증가시킨다.
2-2. mid보다 작은 수의 갯수는 행(또는 열)의 갯수만큼 반복하는데, 각 행에서 mid보다 작은 수들을 행마다 더하는 것이다.
i번째 행들의 원소 값들은 i의 배수인데, i번째 행에서 mid 이하인 원소들의 값은 mid/i가 된다.*/
#include <iostream>
#include <algorithm>
using namespace std;

int N, K;
int ans;
int main() {
	cin >> N >> K;

	int left = 1;
	int right = K;
	while (left <= right) {
		long long cnt = 0;
		int mid = (left + right) / 2;
		//첫번째 예제에서 mid가 4가 되는데(left=1, right=7), i가 1일때 mid/1 == 4로 1행에서 mid이하인 최대원소갯수인(N은 열의 갯수)을 넘는다. 그래서 min(mid/i, N)
		for (int i = 1; i <= N; i++)cnt += min(mid / i,N);
		if (cnt < K)left = mid + 1;
		else {
			ans = mid;
			right = mid - 1;
		}
	}
	cout << ans;
}
