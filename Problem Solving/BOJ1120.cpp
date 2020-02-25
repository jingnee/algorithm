/*문자열
1. 두개의 문자열이 주어질때 (A,B) A의 앞이나 뒤에 아무 문자나 추가했을때 B랑 제일 비슷한 문자열 만들기
각 자리값이 다른 경우의 자릿값 갯수출력*/

#include<iostream>
#include<string>
using namespace std;

int num;
int mini = 987654321;

int main() {
	string str1, str2;
	cin >> str1 >> str2;
	int size1 = str1.length();
	int size2 = str2.length();
	num = size2 - size1;

	for (int i = 0; i <= num; i++) {
		int minNum = 0;
		int k = i;
		for (int j = 0; j < str1.length(); j++,k++) {
			
			if (str1[j] != str2[k])minNum++;
			
		}
		mini = (mini > minNum) ? minNum : mini;
	}

	cout << mini << endl;
}