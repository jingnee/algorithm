/*제국*/
#include <iostream>
#include <map>
#include <set>
#include <string>
using namespace std;

int N, M;
map<string, string> parent;
set<string> s;

string getParent(string str) {
	if (parent[str] == str)return str;
	else return parent[str] = getParent(parent[str]);
}

void fight(string king1, string king2, int w) {
	string mom_king1 = getParent(king1);
	string mom_king2 = getParent(king2);
	map<string, string>::iterator iter;

	//다른 왕국 끼리 공격
	if (mom_king1 != mom_king2) {
		if (w == 1) {
			for (iter = parent.begin(); iter != parent.end(); iter++) {
				if ((*iter).second == mom_king2) {
					parent[(*iter).first] = mom_king1;
				}
			}
		}
		else if (w == 2) {
			for (iter = parent.begin(); iter != parent.end(); iter++) {
				if ((*iter).second == mom_king1) {
					parent[(*iter).first] = mom_king2;
				}
			}
		}
	}

	//속국이 자기 왕국 공격
	else {
		if (w == 1 && king1 != mom_king1) {
			for (iter = parent.begin(); iter != parent.end(); iter++) {
				if ((*iter).second == mom_king2) {
					parent[(*iter).first] = king1;
				}
			}
		}
		else if (w == 2 && king2 != mom_king2) {
			for (iter = parent.begin(); iter != parent.end(); iter++) {
				if ((*iter).second == mom_king1) {
					parent[(*iter).first] = king2;
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;
	cin >> N >> M;
	getline(cin, str);			//줄바꿈 입력
	for (int i = 0; i < N; i++) {
		getline(cin, str);
		parent.insert(pair<string, string>(str, str));
	}
	for (int i = 0; i < M; i++) {
		string king1, king2;
		int n;
		getline(cin, king1, ',');
		getline(cin, king2, ',');
		cin >> n;
		getline(cin, str);			//줄바꿈 입력
		fight(king1, king2, n);
	}
	for (auto a : parent)s.insert(a.second);
	cout << s.size() << "\n";
	for (auto a : s)cout << a << "\n";
}
