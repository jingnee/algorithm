//졸려
/*
내가 했던 실수 : 반복싸이클이 글자수-1이 아니다.
반복싸이클을 cnt를통해서 구해주어야 함....
*/
#include <iostream>
#include <string>
using namespace std;

string word[1001];
int n;

int main() {
	int x;
	string str;
	cin >> x >> str;
	int length;

	length = str.size();

	int sr, sl;
	//n = x % (length - 1);					//글자수-1횟수만큼 반복됨
	word[0] = str;
	if (length % 2 == 0)sr = length - 1;
	else sr = length - 2;
	int cnt = 0;
	while (1) {
		string temp;

		for (int i = 0; i < length; i += 2) {
			temp += word[cnt][i];
		}
		for (int j = sr; j >= 0; j -= 2) {
			temp += word[cnt][j];
		}
		cnt++;
		word[cnt] = temp;
		if (temp == str) {
			break;
		}
	}
	//cout << cnt << endl;
	//cout << length - 1 << endl;
	cout << word[x%cnt] << endl;
	//cout << word[x % (length - 1)] << endl;

	return 0;

}


/*
#include <iostream>
#include <string>
using namespace std;
string word[1001];
int n;
int main() {
int x;
string str;
cin >> x >> str;
int length;
//cin >> word[0];
length = str.size();
if (length % 2 == 0) {		//짝수인경우
int cnt = 0;
word[cnt] = str;
while (1) {
string temp;
for (int i = 0; i < length; i += 2) {
temp += word[cnt][i];
}
for (int j = length - 1; j >= 0; j -= 2) {
temp += word[cnt][j];
}
cnt++;
word[cnt] = temp;
if (temp == str) {
break;
}
}
cout << word[x%cnt];
}
else {		//홀수인경우
int cnt = 0;
word[cnt] = str;
while (1) {
string temp;
for (int i = 0; i < length; i += 2) {
temp += word[cnt][i];
}
for (int j = length - 2; j >= 0; j -= 2) {
temp += word[cnt][j];
}
cnt++;
word[cnt] = temp;
if (temp == str) {
break;
}
}
cout << word[x%cnt];
}
}
*/