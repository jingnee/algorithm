/*준환이의 운동 관리*/
#include <iostream>
using namespace std;

int L, U, X;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		cin >> L >> U >> X;
		if (X < L)cout << "#" << test_case << " " << L - X << "\n";
		else if(X <= U)cout << "#" << test_case << " " << 0 << "\n";
		else cout << "#" << test_case << " " << -1 << "\n";
	}
}
