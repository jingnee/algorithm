/*다음 펠린드롬 수*/ 
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;
	string str2;
	cin >> str;
	int length = str.length();
	str2 = str;
	if (str.compare("9") == 0) {
		cout << "11\n";
		return 0;
	}

	for (int i = 0; i < length / 2; i++)str2[length - 1 - i] = str[i];
	int center = length / 2;
	int mid = center;
	while (str2.compare(str) <= 0) {
		if (mid==length) {
			str2[0] = '1';
			str2 += '1';
			break;
		}
		else {
			if (str2[mid] == '9') {
				str2[mid] = '0';
				str2[length - mid - 1] = '0';
				mid++;
			}
			else {
				char ch = str2[mid] + 1;
				str2[mid] = ch;
				str2[length - mid - 1] = ch;
				break;
			}
		}
	}

	cout << str2 << "\n";
}
