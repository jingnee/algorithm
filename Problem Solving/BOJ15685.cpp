/*드래곤 커브*/
#include <iostream>
#include <vector>
using namespace std;

bool visit[102][102];
int dr[4] = { 0,-1,0,1 };
int dc[4] = { 1,0,-1,0 };
int N;

void makeCurve(int r, int c, int dir, int g) {
	vector<int> dirVec;
	dirVec.push_back(dir);
	for (int i = 0; i < g; i++) {
		for (int j = dirVec.size() - 1; j >= 0; j--) {
			dirVec.push_back((dirVec[j] + 1) % 4);
		}
	}
	visit[r][c] = true;
	for (int i = 0; i < dirVec.size(); i++) {
		r += dr[dirVec[i]];
		c += dc[dirVec[i]];
		visit[r][c] = true;
	}
}
bool valid(int r, int c) {
	for (int i = r; i < r + 2; i++) {
		for (int j = c; j < c + 2; j++) {
			if (i > 100 || j > 100)return false;
			if (visit[i][j] == false)return false;
		}
	}
	return true;
}
int findSquare() {
	int answer = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (valid(i, j))answer++;
		}
	}
	return answer;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int r, c, d, g;
		cin >> c >> r >> d >> g;
		makeCurve(r, c, d, g);
	}
	cout << findSquare() << "\n";
}
