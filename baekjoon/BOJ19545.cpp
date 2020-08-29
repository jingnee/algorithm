/*인형들*/
#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

int number[501];
long double DP[501];
long double sums[501];
int N, K;
long double minNum = 2e9;
long double ans = 0.0;

int main() {
	
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> number[i];
		DP[i + 1] = DP[i] + (long double)number[i] * number[i];
		sums[i + 1] = sums[i] + number[i];
	}


	for (int k = K; k <= N; k++) {	
		for (int i = k; i <= N; i++) {

			long double avg = (sums[i] - sums[i - k]) / k;
			long double sum = (DP[i] - DP[i - k]) / k - avg*avg;
			
			ans = sqrt(sum);
			minNum = min(minNum, ans);
		}
	}

	//cout << minNum << "\n";
	printf("%.11Lf\n", minNum);
}

/*28 라인
		((number[1]-avg)^2 + (number[2]-avg)^2 + (number[3]-avg)^2 + ... + (number[k]-avg)^2 )/k
	==	(number[1]^2 + number[2]^2 + number[3]^2 + ... + number[k]^2)/k - 2*avg*(number[1]+number[2]+number[3]+...number[k])/k + avg*avg
	==	(DP[k]-DP[0])/k - 2*avg*(sums[k]-sums[0]) + avg*avg
	==	(DP[k]-DP[0])/k - 2*avg*avg + avg*avg
	==	(DP[k]-DP[0])/k - avg*avg
*/

/* 처음 정답 코드
/*인형들*/
#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

int number[501];
int N, K;
double minNum = 2e9;
double ans = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> number[i];
	}


	for (int k = K; k <= N; k++) {
		
		for (int i = 0; i <= N - k; i++) {
			double avg = 0;
			double sum = 0;

			for (int j = i; j < i + k; j++) {
				avg += (double)number[j]/(double)k;
			}
			
			for (int j = i; j < i + k; j++) {
				sum += ((number[j] - avg)*(number[j] - avg)/k);
			}

			ans = sqrt(sum);
			minNum = min(minNum, ans);
		}
	}

	//cout << minNum << "\n";
	printf("%.12f\n", minNum);
}
*/
