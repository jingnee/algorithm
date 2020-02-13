/*
벌꿀 채취
1. 
2. 3<=N(벌통크기)<=10
	1<=M(벌통갯수)<=5
	10<=C(벌꿀최대양)<=30

3. 시작위치,가능한벌통배열,최댓값 을 가지는 구조체생성
캘 수 있는 벌통배열을 모두 구한다.
for(벌통배열을 모두 검사){
	//벌통배열로 가능한 모든 조합을 구한다.(nCr에서 r이 1인경우부터N까지)
	//조합이 만들어지면 조합배열에 들어있는 값이 C를 넘지않는지 확인
	//넘지않는다면 최댓값 구해서 그 구조체 배열에 넣어준다.
}
구조체 배열에서 벌통배열이 겹치지않으면서 가장 큰값을 가지는 두 벌통배열(최댓값) 더한다.
*/

#include<iostream>
#include<vector>
using namespace std;

int N, M, C;
vector<vector<int>> map;
struct hives {
	int r;
	int c;
	int max;
	vector<int> honey;
};
//vector<hives> hive;
int order[10];
int visit[10];
int find_max(int n) {			//주어진 조합에서 최댓값찾기
	int num = 0;
	for (int i = 0; i < n; i++) {
		num += (order[i] * order[i]);
	}
	return num;
}

void combi(int cnt, int n, int sum, hives *hive) {		//n개를 고르는 조합
	if (sum > C)return;
	if (cnt == n) {
		int num = find_max(n);
		if (num > (*hive).max)(*hive).max = num;
		return;
	}

	for (int i = 0; i < M; i++) {
		if (visit[i] == false) {
			visit[i] = true;
			order[cnt] = (*hive).honey.at(i);
			combi(cnt + 1, n, sum + order[cnt], hive);
			visit[i] = false;
		}
		
	}

}

int main() {
	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		cin >> N >> M >> C;
		map.assign(N, vector<int>(N, 0));				//2차원 vector 초기화!! 꼭 알아두기
		vector<hives> hive;

		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				cin >> map[i][j];

		for (int i = 0; i < N; i++) {				//가능한 벌통 구조체들 모두 만들어두기
			for (int j = 0; j <= N - M; j++) {
				hives temp;
				temp.r = i;
				temp.c = j;
				for (int k = j; k < j+M; k++)
					temp.honey.push_back(map[i][k]);
				temp.max = 0;
				hive.push_back(temp);
			}
		}

		for (int i = 0; i < hive.size(); i++) {				//최댓값 넣어주기
			hives *temp = &hive.at(i);
			for (int j = 1; j <= M; j++) {
				combi(0, j, 0, temp);
			}

		}

		int answer = 0;
		int maximum = 0;
		for (int i = 0; i < hive.size()-1; i++) {
			answer = hive.at(i).max;
			for (int j = 0; j < hive.size(); j++) {
				if (hive.at(i).r != hive.at(j).r || hive.at(i).c + M <= hive.at(j).c) {
					if (answer + hive.at(j).max > maximum)maximum = answer + hive.at(j).max;
				}
			}
		}

		//최댓값 순으로 두개뽑는데 안겹치는거찾기.. 여기가 문제
		/*for (int i = 0; i < hive.size(); i++)
			cout << "[" << hive.at(i).r << "][" << hive.at(i).c << "]부터 " << M << "개배열에서 최댓값은 " << hive.at(i).max << endl;*/
		cout << "#" << test_case << " " << maximum << endl;

	}
}