/* 수족관 */
#include <iostream>
#include <vector>
#include <utility>
using namespace std;
#define MAX 40001

int N, K;
pair<int, int> tank[MAX];				//깊이,물빠진 높이 
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

		//왼쪽
		for (int j = x - 1; j >= 0; j--) {
			//if (tank[j].first < y)break;
			////하수구 구멍보다 깊이가 더 깊고, 물차있는 높이가 구멍보다 위일때(작은값일때)
			//if (tank[j].first >= y && tank[j].second < y)tank[j].second = y;
			height = (height > tank[j].first) ? tank[j].first : height;
			tank[j].second = (height < tank[j].second) ? tank[j].second : height;

		}
		//하수구 구멍 물높이 갱신
		//for (int j = x; j <= x2; j++)tank[j].second = y;
		height = tank[x].first;
		//오른쪽
		for (int j = x + 1; j < row; j++) {
			//if (tank[j].first < y)break;
			////하수구 구멍보다 깊이가 더 깊고, 물차있는 높이가 구멍보다 위일때(작은값일때)
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