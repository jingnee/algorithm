//AC
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

vector<string> vec;
void push_vec(string arr) {
	//[]인경우
	if (arr.size() == 2)return;
	int idx = 1;
	for (int i = 1; i < arr.size(); i++) {
		if (arr[i] == ',' || arr[i] == ']') {
			string number = arr.substr(idx, i - idx);
			vec.push_back(number);
			idx = i + 1;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	while (T--) {
		string p, arr;
		int n;
		vec.clear();
		cin >> p >> n;
		cin >> arr;
		push_vec(arr);
		int _s = 0, _e = vec.size() - 1;
		//false인경우 순서대로
		bool order = false, fail = false;

		for (auto o : p) {
			if (o == 'D' && _s > _e) {
				fail = true;
				break;
			}
			else if (o == 'R') {
				order = !order;
			}
			else if (o == 'D') {
				//역순인경우
				if (order) _e--;
				//순서대로인경우
				else _s++;
			}
		}
		if (fail) {
			cout << "error\n";
			continue;
		}

		cout << "[";
		if (!order) {
			for (int i = _s; i <= _e; i++) {
				cout << vec[i];
				if (i != _e)cout << ",";
			}
		}
		else {
			for (int i = _e; i >= _s; i--) {
				cout << vec[i];
				if (i != _s)cout << ",";
			}
		}
		cout << "]\n";
	}
}