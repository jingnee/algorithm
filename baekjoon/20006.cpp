//랭킹전 대기열
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int p, m;
vector<vector<pair<int, string>>> rooms;

bool sorted(pair<int, string>p1, pair<int, string>p2) {
	if (p1.second < p2.second)return true;
	else return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> p >> m;
	for (int i = 0; i < p; i++) {
		int l;
		string n;
		cin >> l >> n;
		if (rooms.empty()) {
			vector<pair<int, string>> vec;
			vec.push_back(make_pair(l, n));
			rooms.push_back(vec);
		}
		else {
			int idx = 0;
			while (idx < rooms.size()) {
				int num = rooms[idx].front().first;
				if ((l >= num - 10 && l <= num + 10) && rooms[idx].size() < m)break;
				idx++;
			}
			if(idx<rooms.size())
			rooms[idx].push_back(make_pair(l, n));
			else {
				vector<pair<int, string>> vec;
				vec.push_back(make_pair(l, n));
				rooms.push_back(vec);
			}
		}
	}
	for (auto r : rooms) {
		sort(r.begin(), r.end(), sorted);
		if (r.size() == m) {
			cout << "Started!\n";
			for (auto rr : r)cout << rr.first << " " << rr.second << "\n";
		}
		else {
			cout << "Waiting!\n";
			for (auto rr : r)cout << rr.first << " " << rr.second << "\n";
		}
	}
}
