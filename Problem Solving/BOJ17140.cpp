/*������ �迭�� ����*/
#include <iostream>
#include <vector>
#include <utility>
#include <cstring>
#include <algorithm>
using namespace std;

int r, c, k;
int answer;
int rNum = 3, cNum = 3;
int map[101][101];

bool compare(pair<int, int>a, pair<int, int>b) {
	if (a.second == b.second) {
		return a.first < b.first;		//���� ���ؼ� ��������
	}
	else return a.second < b.second;				//������ ���ؼ� ��������
}

void rowSort() {			//�� ����
	//int *visit = new int[cNum + 1];					//cNum�� �ִ� ���� ���̸� ���� �����Ƿ� ���ڴ� cNum+1������ ���� �� ����
	int visit[101];					//visit�� ���� ���� cNum���� ū ���� �� �ִ�..(ó���� �� 1,2,3���� �־����� ���� �� ����)

	for (int i = 1; i <= rNum; i++) {
		memset(visit, 0, sizeof(int)*101);
		vector<pair<int, int>> row;					//�� ���� ���� ������ ��� ����

		for (int j = 1; j <= cNum; j++) {			//�� �࿡ ���� ���
			visit[map[i][j]]++;
			map[i][j] = 0;
		}
		for (int k = 1; k <= 100; k++) {			//���� ���� �迭 ���Ϳ� �ֱ�
			if (visit[k] != 0)
				row.push_back(make_pair(k, visit[k]));
		}
		sort(row.begin(),row.end(),compare);				//���� ����

		if (cNum < row.size() * 2)cNum = row.size() * 2;
		//int size = row.size() * 2;
		int j = 1;
		vector<pair<int, int>>::iterator it;
		for (it = row.begin(); it != row.end();it++) {		//���� �ʿ� �ٽ� �ֱ�
			//pair<int, int> temp = row.at(it);
			//row.pop_back();
			map[i][j++] = (*it).first;
			map[i][j++] = (*it).second;
		}
		////�ʿ� ���� ���� ���̰� �����ʺ��� ������
		//while (j<=cNum) {
		//	map[i][j] = 0;
		//	j++;
		//}
	}
}

void columnSort() {			//�� ����
	//int *visit = new int[rNum + 1];					//rNum�� �ִ� ���� ���̸� ���� �����Ƿ� ���ڴ� rNum+1������ ���� �� ����
	int visit[101];

	for (int j = 1; j <= cNum; j++) {
		memset(visit, 0, sizeof(int)*101);
		vector<pair<int, int>> column;					//�� ���� ���� ������ ��� ����

		for (int i = 1; i <= rNum; i++) {			//�� �࿡ ���� ���
			visit[map[i][j]]++;
			map[i][j] = 0;
		}
		for (int k = 1; k <= 100; k++) {			//���� ���� �迭 ���Ϳ� �ֱ�
			if (visit[k] != 0)
				column.push_back(make_pair(k, visit[k]));
		}
		sort(column.begin(), column.end(), compare);				//���� ����

		if (rNum < column.size() * 2)rNum = column.size() * 2;
		//int size = row.size() * 2;
		int i = 1;
		vector<pair<int, int>>::iterator it;
		for (it = column.begin(); it != column.end(); it++) {		//���� �ʿ� �ٽ� �ֱ�
			//pair<int, int> temp = row.at(it);
			//row.pop_back();
			map[i++][j] = (*it).first;
			map[i++][j] = (*it).second;
		}
		//�ʿ� ���� ���� ���̰� �����ʺ��� ������
		/*while (i<=rNum) {
			map[i][j] = 0;
			i++;
		}*/
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> r >> c >> k;
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			cin >> map[i][j];
		}
	}

	while (map[r][c] != k) {
		//��� �� �� ������ ū�� 
		if (rNum >= cNum)rowSort();	
		else columnSort();
		answer++;
		if (answer > 100) {
			answer = -1;
			break;
		}
		//cout << "***************" << endl;
		//for (int i = 1; i <= rNum; i++) {
		//	for (int j = 1; j <= cNum; j++) {
		//		cout << map[i][j];
		//	}cout << endl;
		//}
	}

	cout << answer << endl;
}