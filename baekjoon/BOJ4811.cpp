/*알약*/
#include <iostream>
#include <cstring>
using namespace std;

int n;
long long cache[31][31];

long long DFS(int H, int W) {
	if (H == 0)return 1;

	long long &ans = cache[H][W];
	if (ans != -1)return ans;

	ans = 0;
	//1개짜리 알약이 1개이상이면 1개알약 빼고 반알약을 넣어
	if (H > 0) ans += DFS(H - 1, W + 1);
	//1개짜리 알약이 0개이고, 반개 알약이 1개 이상이면 반 알약 먹어
	if (W > 0) ans += DFS(H, W - 1);

	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	memset(cache, -1, sizeof(cache));

	while(1){
		cin >> n;
		if (n == 0)return 0;
		cout << DFS(n,0) << "\n";
	}
}
