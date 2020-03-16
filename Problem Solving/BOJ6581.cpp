/*HTML*/
#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	int sum = 0;
	while (cin >> str) {
		if (str == "<br>") {
			cout << "\n";
			sum = 0;
		}
		else if (str == "<hr>") {
			if (sum != 0) cout << "\n";
			for (int i = 0; i < 80; i++)cout << "-";
			cout << "\n";
			sum = 0;
		}
		else {
			int len = str.length();
			if (sum == 0) {
				sum = len;
				cout << str;
			}
			else {
				if (sum + len + 1 <= 80) {
					cout << " ";
					sum += 1;
					cout << str;
					sum += len;
					if (sum == 80) {
						cout << "\n";
						sum = 0;
					}
				}
				else {
					cout << "\n";
					cout << str;
					sum = len;
				}
			}
			
		}
	}
}
