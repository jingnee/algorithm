/*���� �� ���ϱ� 4*/
//#include<stdio.h>
#include<iostream>
using namespace std;

//cout,cin ���� �ð��ٿ��� �Ѱ�� 44ms
//printf, scanf���� �Ѱ�� 60ms

int N, M;
int main() {
	ios_base::sync_with_stdio(false);		//�̺κо����� �ð��ʰ�
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