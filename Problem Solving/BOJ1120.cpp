/*���ڿ�
1. �ΰ��� ���ڿ��� �־����� (A,B) A�� ���̳� �ڿ� �ƹ� ���ڳ� �߰������� B�� ���� ����� ���ڿ� �����
�� �ڸ����� �ٸ� ����� �ڸ��� �������*/

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