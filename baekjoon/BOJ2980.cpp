/*도로와 신호등*/
#include<iostream>
using namespace std;

int N, L, D, R, G;
bool road[1001];			//true = 신호등 존재
int light[1001][2];

int main() {
	int time = 0;
	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		int num, g, r;
		cin >> num >> r >> g;
		light[num][0] = r;
		light[num][1] = g;
		road[num] = 1;
	}
	for (int i = 0; i < L; i++) {
		if (!road[i]) {
			time++;
			continue;
		}
		else {
			int total = light[i][0] + light[i][1];
			int num = time%total;
			if (num >= light[i][0]) {
				time++;
			}
			else {
				num = light[i][0] - num;
				time = time + num + 1;
			}
		}
	}
	cout << time << "\n";
}
