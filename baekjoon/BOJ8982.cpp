/* ������ */
#include <iostream>
#include <vector>
#include <utility>
using namespace std;
#define MAX 40001

int N, K;
pair<int, int> tank[MAX];				//����,������ ���� 
int main() {
	cin >> N;
	int x, y, x2, y2;
	//0,0
	cin >> x >> y;
	for (int i = 0; i < N / 2 - 1; i++) {
		cin >> x >> y >> x2 >> y2;
		for (int j = x; j < x2; j++) {
			tank[j].first = y;
		}
	}
	//X,0
	cin >> x >> y;

	int row = x;
	vector<int> hole;
	cin >> K;
	for (int i = 0; i < K; i++) {
		cin >> x >> y >> x2 >> y2;
		hole.push_back(x);
	}

	for (int i = 0; i < hole.size(); i++) {
		x = hole[i];
		int height = tank[x].first;
		tank[x].second = height;

		//����
		for (int j = x - 1; j >= 0; j--) {
			//if (tank[j].first < y)break;
			////�ϼ��� ���ۺ��� ���̰� �� ���, �����ִ� ���̰� ���ۺ��� ���϶�(�������϶�)
			//if (tank[j].first >= y && tank[j].second < y)tank[j].second = y;
			height = (height > tank[j].first) ? tank[j].first : height;
			tank[j].second = (height < tank[j].second) ? tank[j].second : height;

		}
		//�ϼ��� ���� ������ ����
		//for (int j = x; j <= x2; j++)tank[j].second = y;
		height = tank[x].first;
		//������
		for (int j = x + 1; j < row; j++) {
			//if (tank[j].first < y)break;
			////�ϼ��� ���ۺ��� ���̰� �� ���, �����ִ� ���̰� ���ۺ��� ���϶�(�������϶�)
			//if (tank[j].first >= y && tank[j].second < y)tank[j].second = y;

			height = (height > tank[j].first) ? tank[j].first : height;
			tank[j].second = (height < tank[j].second) ? tank[j].second : height;
		}
	}

	int ans = 0;
	for (int i = 0; i < row; i++) {
		if (tank[i].first > tank[i].second)
		ans += tank[i].first - tank[i].second;
	}
	cout << ans;
}