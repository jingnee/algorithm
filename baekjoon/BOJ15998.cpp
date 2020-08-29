/*īī���Ӵ�*/
#include <iostream>
using namespace std;

int N;
long long a[300002];
long long b[300002];
long long M;
//long long MAX = 9000000000000000000;
bool first = true;

long long gcd(long long x, long long y) {
	return (y ? gcd(y, x%y) : x);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> a[i] >> b[i];
		M = gcd(M, b[i] - b[i - 1] - a[i]);
	}

	for (int i = 1; i <= N; i++) {
		if (b[i]-b[i-1] == a[i])continue;
		//a�� ����ΰ�� (������ �ɷ������ �ϴµ�, ���� �ȸ����� �Ʒ��� ���Ƿ�)
		//������ �ݾ��� �����ݾ׺��� ������
		//a�� �����ε� ������ �����ݾ׺��� ������(�̸� ������ �ɷ������ �ϴµ�, �ƴѰ��)
		if ((M&&M <= b[i]) || a[i] > 0 || (a[i] < 0 && -a[i] < b[i - 1])) {
			cout << "-1\n";
			return 0;
		}
	}

	if (M == 0)M = 1;
	cout << M << "\n";

	return 0;
}