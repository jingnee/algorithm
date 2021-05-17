//단어 공부
#include <iostream>
#include <map>
#include <string>
using namespace std;

char answer;
int maxi;
int alphabet[26];

int main() {
	string str;
	cin >> str;
	for (auto s : str) 
		alphabet[toupper(s)-'A']++;
	for (int i = 0; i < 26; i++) {
		if (maxi > alphabet[i])continue;
		else if (maxi < alphabet[i]) {
			answer = i + 'A';
			maxi = alphabet[i];
		}
		else if (maxi == alphabet[i])
			answer = '?';
	}
	cout << answer;
}
