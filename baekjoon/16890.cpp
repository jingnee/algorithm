/*창업*/
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

char koosaga[300001], cubelover[300001];
char answer[300002];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str1, str2;
	cin >> str1 >> str2;
	strcpy(koosaga, str1.c_str());
	strcpy(cubelover, str2.c_str());
	int n = str1.size();

	sort(koosaga, koosaga + n);
	sort(cubelover, cubelover + n);
	int idx = 0;
	int cnt = 0;
	int si = 0, ei = n - 1;
	int kl = 0, kr = (n + 1) / 2 - 1 ;
	int cl = (n + 1) / 2, cr = n-1;

	while (cnt < n) {
		if (cnt % 2 == 0) {		//koosaga 차례
			if (koosaga[kl] < cubelover[cr]) {
				answer[si] = koosaga[kl];
				kl++;
				si++;
			}
			else {
				answer[ei] = koosaga[kr];
				kr--;
				ei--;
			}
		}
		else {					//cubelover 차례
			if (cubelover[cr] > koosaga[kl]) {
				answer[si] = cubelover[cr];
				cr--;
				si++;
			}
			else {
				answer[ei] = cubelover[cl];
				cl++;
				ei--;
			}
		}
		cnt++;
	}
	for (int i = 0; i < n; i++)cout << answer[i];
}
