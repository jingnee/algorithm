//����
/*
<<<<<<< HEAD
���� �ߴ� �Ǽ� : �ݺ�����Ŭ�� ���ڼ�-1�� �ƴϴ�.
�ݺ�����Ŭ�� cnt�����ؼ� �����־�� ��....
=======
	���� �ߴ� �Ǽ� : �ݺ�����Ŭ�� ���ڼ�-1�� �ƴϴ�.
	�ݺ�����Ŭ�� cnt�����ؼ� �����־�� ��....
>>>>>>> 855c4e9559796f950b95f177cec60a7d0ce02e48
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
	//n = x % (length - 1);					//���ڼ�-1Ƚ����ŭ �ݺ���
	word[0] = str;
	if (length % 2 == 0)sr = length - 1;
	else sr = length - 2;
	int cnt = 0;
<<<<<<< HEAD
	while (1) {
=======
	while(1) {
>>>>>>> 855c4e9559796f950b95f177cec60a7d0ce02e48
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
<<<<<<< HEAD
string word[1001];
int n;
int main() {
int x;
string str;
cin >> x >> str;
int length;
//cin >> word[0];
length = str.size();
if (length % 2 == 0) {		//¦���ΰ��
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
else {		//Ȧ���ΰ��
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
=======

string word[1001];
int n;

int main() {
	int x;
	string str;
	cin >> x >> str;
	int length;

	//cin >> word[0];
	length = str.size();

	if (length % 2 == 0) {		//¦���ΰ��
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

	else {		//Ȧ���ΰ��
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

>>>>>>> 855c4e9559796f950b95f177cec60a7d0ce02e48
}
*/