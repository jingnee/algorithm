//�ߺ� ���� �����ϱ�
#include<iostream>
#include<set>
using namespace std;

int N;
set<int>s;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		s.insert(num);
	}
	for (auto a : s)cout << a << " ";
}