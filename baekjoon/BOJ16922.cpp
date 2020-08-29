#include <iostream>
using namespace std;

bool Sum[1001];		//나올 수 있는 최댓값 = 50*20 = 1000 배열인덱스는 0부터
int Roma[4] = { 1,5,10,50 };
int result, N;
void Homogeneous(int index, int sum, int cnt) {		//중복조합의 H=Homogeneous
	if (cnt == N) {
		if (Sum[sum] == false) {
			Sum[sum] = true;
			result++;
		}
		return;
	}
	for (int i = index; i < 4; i++)
		Homogeneous(i, sum + Roma[i], cnt + 1);
}
int main() {
	cin >> N;
	Homogeneous(0, 0, 0);
	cout << result << endl;
}
/*
	이문제가 중복 조합으로 푸는 문제지만 중복조합의 값이 나오지 않는 이유!
	단순히 조합하는것이아니라 "조합된 값"으로 판단하는 문제이기 때문
	예를들어서 N이 6인경우 {1,1,1,1,1,50}과 {10,10,10,10,10,5}의 경우 조합은 달라도 55로 값은 같기때문에
	중복조합계산으로는 두개로 치지만 이 문제에서는 하나로 친다.
*/