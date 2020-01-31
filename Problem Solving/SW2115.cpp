/*
���� ä��
1. 
2. 3<=N(����ũ��)<=10
	1<=M(���밹��)<=5
	10<=C(�����ִ��)<=30

3. ������ġ,�����ѹ���迭,�ִ� �� ������ ����ü����
Ķ �� �ִ� ����迭�� ��� ���Ѵ�.
for(����迭�� ��� �˻�){
	//����迭�� ������ ��� ������ ���Ѵ�.(nCr���� r�� 1�ΰ�����N����)
	//������ ��������� ���չ迭�� ����ִ� ���� C�� �����ʴ��� Ȯ��
	//�����ʴ´ٸ� �ִ� ���ؼ� �� ����ü �迭�� �־��ش�.
}
����ü �迭���� ����迭�� ��ġ�������鼭 ���� ū���� ������ �� ����迭(�ִ�) ���Ѵ�.
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
int find_max(int n) {			//�־��� ���տ��� �ִ�ã��
	int num = 0;
	for (int i = 0; i < n; i++) {
		num += (order[i] * order[i]);
	}
	return num;
}

void combi(int cnt, int n, int sum, hives *hive) {		//n���� ���� ����
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
		map.assign(N, vector<int>(N, 0));				//2���� vector �ʱ�ȭ!! �� �˾Ƶα�
		vector<hives> hive;

		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				cin >> map[i][j];

		for (int i = 0; i < N; i++) {				//������ ���� ����ü�� ��� �����α�
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

		for (int i = 0; i < hive.size(); i++) {				//�ִ� �־��ֱ�
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

		//�ִ� ������ �ΰ��̴µ� �Ȱ�ġ�°�ã��.. ���Ⱑ ����
		/*for (int i = 0; i < hive.size(); i++)
			cout << "[" << hive.at(i).r << "][" << hive.at(i).c << "]���� " << M << "���迭���� �ִ��� " << hive.at(i).max << endl;*/
		cout << "#" << test_case << " " << maximum << endl;

	}
}