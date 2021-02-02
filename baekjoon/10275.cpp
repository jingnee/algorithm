//°ñµå ·¯½Ã
#include <iostream>
#include <bitset>
#include <string>
using namespace std;

int T;
int main() {
	cin >> T;
	while (T--) {
		long long n, a, b;
		cin >> n >> a >> b;

		string s_a = bitset<63>(a).to_string();
		string s_b = bitset<63>(b).to_string();

		int idx1 = 0, idx2 = 0;
		for (int i = s_a.length() - 1; i >= 0; i--) {
			if (s_a[i] == '1') break;
			idx1++;
		}
		for (int i = s_b.length() - 1; i >= 0; i--) {
			if (s_b[i] == '1') break;
			idx2++;
		}
		int idx = (idx1 < idx2) ? idx1 : idx2;
		cout << n - idx << "\n";
	}
	
}