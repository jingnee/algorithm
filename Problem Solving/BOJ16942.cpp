#include <iostream>
#include <string>
using namespace std;

string str;
int answer;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> str;

	for (int i = 0; i < str.length(); i++) {
		char pivot = str[i];
		int index = i;
		int ans = 1;

		for (int j = i + 1; str[j];j++) {
			if ((j-index)%2 ==1 && str[j] == pivot) {
				index = j;
				ans++;
			}
		}
		if (answer < ans)answer = ans;
	}
	cout << answer << "\n";
}
