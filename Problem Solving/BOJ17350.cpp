/*2��� �̸��� ����*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> names;
int N;
int main() {
	bool flag = false;
	cin >> N;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		names.push_back(str);

		/*���ڿ� ��ü�߿��� anj�� ã��
		int n = str.find("anj");
		���� ��ã���� npos�� ����
		if (n != string::npos)flag = true;*/

		if (str == "anj")flag = true;
	}
	if (flag)cout << "����;\n";
	else cout << "����?\n";
}