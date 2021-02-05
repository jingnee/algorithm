//���� ä���
#include <iostream>
#include <functional>
#include <queue>
using namespace std;

int N, fuel, dist, ans;
priority_queue<pair<int, int>> pq;	//���� ��������(����,�Ÿ�)
priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq2;		//�Ÿ� ��������(�Ÿ�,����)

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	while (N--) {
		int d, f;
		cin >> d >> f;
		//�Ÿ� ������������ ����
		pq2.push(make_pair(d, f));
	}
	cin >> dist >> fuel;
	while (fuel < dist) {
		//���� ����� �� �� �ִ� �Ÿ��� pq�� ���
		while (!pq2.empty() && fuel >= pq2.top().first) {
			int d = pq2.top().first;
			int f = pq2.top().second;
			pq.push(make_pair(f, d));
			pq2.pop();
		}
		//pq�� ���� �ְ� ������ �� ����� �� �� �ִ� ���� ���ٴ� ��
		if (pq.empty()) {
			cout << "-1";
			return 0;
		}
		ans++;
		fuel += pq.top().first;
		pq.pop();
	}

	cout << ans;
}