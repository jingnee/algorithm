///*N-Queen*/
//#include <iostream>
//#include <vector>
//using namespace std;
//
//int N, ans;
//vector<pair<int, int>> queen;
//
//bool check(int r, int c) {
//	for (int i = 0; i < queen.size(); i++) {
//		if (queen[i].first == r)return false;
//		if (queen[i].second == c)return false;
//		if (queen[i].first - r == queen[i].second - c)return false;
//		if (r - queen[i].first == c - queen[i].second)return false;
//		if (queen[i].first - r == c - queen[i].second) return false;
//		if (r - queen[i].first == queen[i].second - c)return false;
//	}
//	return true;
//}
//
//void dfs(int num, int r, int c) {
//	if (num == N) {
//		ans++;
//		return;
//	}
//
//	for (int i = r; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			if (check(i, j)) {		//i,j¹øÂ° ÄýÀ» ³õÀ» ¼ö ÀÖ´Ù¸é
//				queen.push_back(make_pair(i, j));
//				dfs(num + 1, i, j);
//				queen.pop_back();
//			}
//		}
//	}
//}
//
//int main() {
//	int T;
//	cin >> T;
//	for (int test_case = 1; test_case <= T; test_case++) {
//		ans = 0;
//		cin >> N;
//		dfs(0, 0, 0);
//		cout << "#" << test_case << " " << ans << endl;
//	}
//}

#include<iostream>
#include<math.h>
using namespace std;

int ans, N;
int queen[10];				//queen[i]=j : [i][j]¿¡ Äý Á¸Àç
void dfs(int num) {
	int n;
	if (num == N) {
		ans++;
		return;
	}

	for (int i = 0; i < N; i++) {
		n = 1;
		for (int j = 0; j < num; j++) {			//ÀúÀåÇÑ ÄýÀÇ °¹¼ö¸¸Å­ Á¶»ç(ÄýÀÇ °¹¼ö=Å½»öÇÑ Çà)
			if (queen[j] == i || abs(num - j) == abs(i - queen[j])) {
				n = 0;
				break;
			}
		}
		if (n) {
			queen[num] = i;
			dfs(num + 1);
		}
	}
}

int main() {
		int T;
		cin >> T;
		for (int test_case = 1; test_case <= T; test_case++) {
			ans = 0;
			cin >> N;
			dfs(0);
			cout << "#" << test_case << " " << ans << endl;
		}
}