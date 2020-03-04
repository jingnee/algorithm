/*이차원 배열과 연산*/
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
		return a.first < b.first;		//수에 대해서 오름차순
	}
	else return a.second < b.second;				//갯수에 대해서 오름차순
}

void rowSort() {			//행 정렬
	//int *visit = new int[cNum + 1];					//cNum은 최대 행의 길이를 갖고 있으므로 숫자는 cNum+1까지만 가질 수 있음
	int visit[101];					//visit에 들어가는 값에 cNum보다 큰 값일 수 있다..(처음에 꼭 1,2,3으로 주어지지 않을 수 있음)

	for (int i = 1; i <= rNum; i++) {
		memset(visit, 0, sizeof(int)*101);
		vector<pair<int, int>> row;					//한 행의 수와 갯수를 담는 벡터

		for (int j = 1; j <= cNum; j++) {			//한 행에 갯수 담기
			visit[map[i][j]]++;
			map[i][j] = 0;
		}
		for (int k = 1; k <= 100; k++) {			//갯수 담은 배열 벡터에 넣기
			if (visit[k] != 0)
				row.push_back(make_pair(k, visit[k]));
		}
		sort(row.begin(),row.end(),compare);				//벡터 정렬

		if (cNum < row.size() * 2)cNum = row.size() * 2;
		//int size = row.size() * 2;
		int j = 1;
		vector<pair<int, int>>::iterator it;
		for (it = row.begin(); it != row.end();it++) {		//원래 맵에 다시 넣기
			//pair<int, int> temp = row.at(it);
			//row.pop_back();
			map[i][j++] = (*it).first;
			map[i][j++] = (*it).second;
		}
		////맵에 넣은 벡터 길이가 원래맵보다 작을때
		//while (j<=cNum) {
		//	map[i][j] = 0;
		//	j++;
		//}
	}
}

void columnSort() {			//열 정렬
	//int *visit = new int[rNum + 1];					//rNum은 최대 열의 길이를 갖고 있으므로 숫자는 rNum+1까지만 가질 수 있음
	int visit[101];

	for (int j = 1; j <= cNum; j++) {
		memset(visit, 0, sizeof(int)*101);
		vector<pair<int, int>> column;					//한 열의 수와 갯수를 담는 벡터

		for (int i = 1; i <= rNum; i++) {			//한 행에 갯수 담기
			visit[map[i][j]]++;
			map[i][j] = 0;
		}
		for (int k = 1; k <= 100; k++) {			//갯수 담은 배열 벡터에 넣기
			if (visit[k] != 0)
				column.push_back(make_pair(k, visit[k]));
		}
		sort(column.begin(), column.end(), compare);				//벡터 정렬

		if (rNum < column.size() * 2)rNum = column.size() * 2;
		//int size = row.size() * 2;
		int i = 1;
		vector<pair<int, int>>::iterator it;
		for (it = column.begin(); it != column.end(); it++) {		//원래 맵에 다시 넣기
			//pair<int, int> temp = row.at(it);
			//row.pop_back();
			map[i++][j] = (*it).first;
			map[i++][j] = (*it).second;
		}
		//맵에 넣은 벡터 길이가 원래맵보다 작을때
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
		//행과 열 중 무엇이 큰지 
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