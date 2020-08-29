/*2루수 이름이 뭐야*/
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

		/*문자열 전체중에서 anj를 찾음
		int n = str.find("anj");
		값을 못찾으면 npos를 리턴
		if (n != string::npos)flag = true;*/

		if (str == "anj")flag = true;
	}
	if (flag)cout << "뭐야;\n";
	else cout << "뭐야?\n";
}