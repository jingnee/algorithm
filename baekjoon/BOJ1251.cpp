/*단어 나누기*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string answer = "";
int main() {
	string str;
	cin >> str;
	
	if (str.length() == 3) {
		cout << str << "\n";
		return 0;
	}

	for (int i = 1; i <= str.length() - 2; i++) {
		for (int j = i; j <= str.length() - 2; j++) {
			string first = str.substr(0, i);
			string second = str.substr(i, j - i + 1);
			string third = str.substr(j + 1);
			reverse(first.begin(), first.end());
			reverse(second.begin(), second.end());
			reverse(third.begin(), third.end());
			first.append(second).append(third);
			//compare 비교하면 틀림
			if (answer == "")answer = first;
			else {
				if (answer > first)answer = first;
			}
		}
	}
	cout << answer << "\n";
}
