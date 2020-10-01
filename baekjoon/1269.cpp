//대칭 차집합
#include <iostream>
#include <set>
using namespace std;

int A, B;
set<int>s;
int cnt;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> A >> B;
	for (int i = 0; i < A; i++) {
		int a;
		cin >> a;
		s.insert(a);
	}
	for (int i = 0; i < B; i++) {
		int b;
		cin >> b;
		if (s.count(b))cnt++;
	}

	cout << (A + B - cnt * 2);
}
