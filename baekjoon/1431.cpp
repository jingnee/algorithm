//�ø��� ��ȣ
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(string s1, string s2) {
	//���̰� �ٸ��ٸ� ª�� ������
	if (s1.size() != s2.size())return s1.size() < s2.size();
	//���̰� ���ٸ� ��� �ڸ� �� �� ��
	else {
		int num1 = 0; int num2 = 0;
		for (auto s : s1) {
			if (s >= '0' && s <= '9')num1 += s - '0';
		}
		for (auto s : s2) {
			if (s >= '0' && s <= '9')num2 += s - '0';
		}

		//�ڸ��������� ���� ������
		if (num1 != num2)return num1 < num2;
		else return s1 < s2;
	}
}

int N;
vector<string>vec;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	while (N--) {
		string st;
		cin >> st;
		vec.push_back(st);
	}
	sort(vec.begin(), vec.end(),compare);
	for (auto v : vec)cout << v << "\n";
}