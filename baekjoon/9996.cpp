//한국이 그리울 땐 서버에 접속하지
#include <iostream>
#include <string>
using namespace std;

int N;
string type1, type2;

bool ismatch(string str) {
	int idx = (str.size() > type2.size()) ? str.size() - type2.size() : -1;

	if (str.size() < type1.size())return false;
	if (str.substr(0, type1.size()) != type1)return false;

	if (idx == -1 || type1.size() > idx)return false;
	if (str.substr(idx) != type2)return false;

	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string type;
	cin >> N >> type;
	for (int i = 0; i < type.size(); i++) {
		if (type[i] == '*') {
			type1 = type.substr(0, i);
			type2 = type.substr(i + 1);
			break;
		}
	}

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		if (ismatch(str))cout << "DA\n";
		else cout << "NE\n";
	}
}
