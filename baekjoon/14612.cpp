//±è½Ä´ç
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int N, M, table, time;
vector<pair<int, int>> vec;
string order;

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> order;

		if (order == "order") {
			cin >> table >> time;
			vec.push_back(make_pair(time, table));
		}
		else if (order == "sort") {
			sort(vec.begin(), vec.end());	
		}
		else {
			cin >> table;
			for (vector<pair<int, int>>::iterator iter = vec.begin(); iter != vec.end(); iter++) {
				if (iter->second == table) {
					vec.erase(iter);
					break;
				}
			}
		}
		if (vec.size() == 0) {
			cout << "sleep\n";
			continue;
		}
		for (auto v : vec)cout << v.second << " ";
		cout << "\n";
	}
	return 0;
}