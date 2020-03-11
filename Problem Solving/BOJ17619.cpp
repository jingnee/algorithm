/*개구리 점프*/
#include <iostream>
#include <algorithm>
using namespace std;

struct pos {
	int x1, x2, y, num;
};
pos Log[100001];
int question[100001];
int N, Q;
bool cmp(pos a, pos b) {
	if (a.x1 < b.x1)return true;
	else return false;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> Q;
	for (int i = 1; i <= N; i++) {
		int x1, x2, y;
		cin >> x1 >> x2 >> y;
		Log[i] = pos{ x1,x2,y,i };
	}
	//좌표 순으로 정렬
	sort(Log + 1, Log + N + 1, cmp);

	int cnt = 0;
	int lastX = 0;

	for (int i = 1; i <= N; i++) {
		//이전 통나무의 뒤쪽 위치가 다음 통나무의 앞쪽보다 앞에있으면 이동할 수 없음
		if (lastX < Log[i].x1) {
			question[Log[i].num] = ++cnt;
			lastX = Log[i].x2;
		}
		//이동한다면 같은값을 가짐(부모가같다 의미)
		else {
			question[Log[i].num] = cnt;
			lastX = (lastX < Log[i].x2) ? Log[i].x2 : lastX;
		}
	}

	for (int q = 0; q < Q; q++) {
		int a, b;
		cin >> a >> b;
		if (question[a] == question[b])cout << 1 << "\n";
		else cout << 0 << "\n";
	}
}