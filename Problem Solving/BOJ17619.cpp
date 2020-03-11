/*������ ����*/
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
	//��ǥ ������ ����
	sort(Log + 1, Log + N + 1, cmp);

	int cnt = 0;
	int lastX = 0;

	for (int i = 1; i <= N; i++) {
		//���� �볪���� ���� ��ġ�� ���� �볪���� ���ʺ��� �տ������� �̵��� �� ����
		if (lastX < Log[i].x1) {
			question[Log[i].num] = ++cnt;
			lastX = Log[i].x2;
		}
		//�̵��Ѵٸ� �������� ����(�θ𰡰��� �ǹ�)
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