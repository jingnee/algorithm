/*구간 합 구하기 4*/
//#include<stdio.h>
#include<iostream>
using namespace std;

//cout,cin 으로 시간줄여서 한경우 44ms
//printf, scanf으로 한경우 60ms

int N, M;
int main() {
	ios_base::sync_with_stdio(false);		//이부분없으면 시간초과
	cout.tie(NULL); 
	cin.tie(NULL);

	cin >> N >> M;
	//scanf("%d %d", &N, &M);
	int *arr = new int[N];
	int *psum = new int[N+1];
	psum[0] = 0;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		//scanf("%d", &arr[i]);
		psum[i + 1] = psum[i] + arr[i];
	}
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		//scanf("%d %d", &a, &b);
		cout << psum[b] - psum[a-1] << "\n";
		//printf("%d\n", psum[b] - psum[a - 1]);
	}
}