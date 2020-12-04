//µË∫∏¿‚
#include<iostream>
#include<map>
#include<string>
using namespace std;

map<string,bool>notSee;
map<string, bool>notSeeListen;
int N, M;

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		notSee[str] = true;
	}
	for (int i = 0; i < M; i++) {
		string str;
		cin >> str;
		if (notSee[str])notSeeListen[str] = true;
	}
	cout << notSeeListen.size() << "\n";
	for (auto m : notSeeListen)cout << m.first << "\n";
}