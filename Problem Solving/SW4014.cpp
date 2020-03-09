/*활주로 건설*/
#include <iostream>
#include <vector>
using namespace std;

int N, X;
int map[20][20];
int countRow() {
	int ans = 0;
	for (int i = 0; i < N; i++) {
		vector<pair<int, int>>v;
		int num = map[i][0], count = 1;
		for (int j = 1,k; j < N; j++) {
			for (k = j; k < N && map[i][k] == num; k++, count++);
			v.push_back(make_pair(num, count));
			num = map[i][k];
			count = 1;
			j = k;
			if (j == N - 1)v.push_back(make_pair(num, count));
		}
		int flag = 0;
		for (int s = 0; s < v.size()-1; s++) {
			if (v[s].first < v[s + 1].first && v[s + 1].first - v[s].first == 1) {			//뒤에가 더 큰수
				if (v[s].second < X) {
					flag = 1;
					break;
				}
			}
			else if(v[s].first > v[s + 1].first && v[s].first - v[s + 1].first == 1){			//앞에가 더 큰수
				if (v[s + 1].second >= X) {			//뒤에 있는 애의 길이가 X보다 크면 X만큼 빼주고
					v[s + 1].second -= X;
				}
				else {
					flag = 1;
					break;
				}
			}
			else {
				flag = 1;
				break;
			}
		}
		if (flag == 0) 
			ans++;	
	}
	return ans;
}
int countColumn() {
	int ans = 0;
	for (int j = 0; j < N; j++) {
		vector<pair<int, int>>v;
		int num = map[0][j], count = 1;
		for (int i = 1, k; i < N; i++) {
			for (k = i; k < N && map[k][j] == num; k++, count++);
			v.push_back(make_pair(num, count));
			num = map[k][j];
			count = 1;
			i = k;
			if (i == N - 1)v.push_back(make_pair(num, count));
		}
		int flag = 0;
		for (int s = 0; s < v.size() - 1; s++) {
			if (v[s].first < v[s + 1].first && v[s+1].first-v[s].first == 1) {			//뒤에가 더 큰수
				if (v[s].second < X) {
					flag = 1;
					break;
				}
			}
			else if (v[s].first > v[s + 1].first && v[s].first - v[s + 1].first == 1) {			//앞에가 더 큰수
				if (v[s + 1].second >= X) {			//뒤에 있는 애의 길이가 X보다 크면 X만큼 빼주고
					v[s + 1].second -= X;
				}
				else {
					flag = 1;
					break;
				}
			}
			else {
				flag = 1;
				break;
			}
		}
		if (flag == 0)
			ans++;
	}
	return ans;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		cin >> N >> X;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
			}
		}
		int num = countRow();
		int num2 = countColumn();
		//cout << "num: " << num <<" "<< "num2: " << num2 << "\n";
		int answer = num + num2;

		cout << "#" << test_case << " " << answer << "\n";
	}
}