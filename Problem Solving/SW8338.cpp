/*°è»ê±â*/
#include <iostream>
using namespace std;

int N;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		cin >> N;
		int sum = 0;
		int num;
		for (int i = 0; i < N; i++) {
			cin >> num;
			if (i == 0)sum = num;
			else {
				int add = sum + num;
				int mul = sum * num;
				sum = (add < mul) ? mul : add;
			}
		}
		cout << "#" << test_case << " " << sum << "\n";
	}
}