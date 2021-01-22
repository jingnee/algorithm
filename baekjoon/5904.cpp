//Moo 게임
#include <iostream>
using namespace std;

long long N;

int main() {
	cin >> N;
	long long tot_len = 3;	//수열의 전체 길이
	long long mid_len = 4;	//중간 moo..oo 의 길이

	//N번째 인덱스보다는 수열이 길어야해
	while (N > tot_len) {
		tot_len = tot_len * 2 + mid_len;
		mid_len++;
	}
	mid_len--;

	//N번째 인덱스가 중간 추가된 수열에 있는지, 그 앞에 있는지, 그 뒤에 있는지
	while (1) {
		int prev_len = (tot_len - mid_len) / 2;
		//이전 수열길이 안에 있으면 그 이전 수열로 다시 따져
		if (N <= prev_len) {
			tot_len = prev_len;
			mid_len--;
		}
		//이전수열과 추가된 수열을 빼면 이전수열의 길이임. 그걸로 다시 따져
		else if (N > prev_len + mid_len) {
			N -= (prev_len + mid_len);
			tot_len = prev_len;
			mid_len--;
		}
		//중간에 새로 추가된 수열안에 존재하면 답 구할 수 있어
		else {
			N -= prev_len;
			break;
		}
	}
	if (N == 1)cout << "m";
	else cout << "o";
}