// Sum
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//int map[100][100];
//int countt[202];      //0~99�� �� ���� �� 100��, 100~199�� �� ���� �� 100��, 200,201�� �밢���� ��
int main() {
	int T = 10;
	int cnt = 0;
	int num, number;
	while (T-- > 0) {
		cin >> num;
		vector<int> countt(202, 0);
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				cin >> number;
				cnt++;
				countt[i] += number;
				countt[100 + j] += number;
				if (i == j)countt[200] += number;
				if (i + j == 99)countt[201] += number;
			}
		}
		sort(countt.begin(), countt.end());
		cout << "#" << num << " " << countt[201] << endl;
	}
}