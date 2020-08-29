/*팰린드롬 만들기*/
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

vector<char> answer;
map<char, int> alphaNum;
int oddNum;
char oddAlpha;
int main() {
	string str;
	cin >> str;
	
	for (int i = 0; i < str.length(); i++)alphaNum[str[i]]++;

	for (char i = 'A'; i <= 'Z'; i++) {
		if (alphaNum[i] == 0)continue;
		int num = alphaNum[i];
		if (num % 2 != 0) {
			oddNum++;
			oddAlpha = i;
			if (oddNum >= 2) {
				cout << "I'm Sorry Hansoo\n";
				return 0;
			}
		}
		num /= 2;
		while (num--)answer.push_back(i);
	}

	vector<char> add = answer;
	reverse(add.begin(), add.end());

	if (oddNum == 1)answer.push_back(oddAlpha);
	//for (int i = answer.size() - 2; i >= 0; i--)answer.push_back(answer[i]);		이렇게 하면 틀림.. vector에 맞는 메소드쓰자..
	for (int i = 0; i < add.size(); i++)answer.push_back(add[i]);

	for (int i = 0; i < answer.size(); i++)cout << answer[i];
}