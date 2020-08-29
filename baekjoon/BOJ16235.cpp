//나무 재테크
#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 11
using namespace std;


int N, M, K;
int nu_init[MAX][MAX];
int nutriment[MAX][MAX];
vector<int> tree[MAX][MAX];				//나무 나이들을 가지는 배열
int dr[8] = { -1,-1,-1,0,1,1,1,0 };
int dc[8] = { -1,0,1,1,1,0,-1,-1 };

void springSummer() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (tree[i][j].size() == 0)continue;		//나무들이 없는 경우는 탐색X
			sort(tree[i][j].begin(), tree[i][j].end());	//나무들 나이로 정렬
			int deadNutri = 0;							//죽은 나무들양분 더할 임시변수
			vector<int> temp;							//죽지않은 나무더할 임시 벡터
			for (int k = 0; k < tree[i][j].size(); k++) {
				if (nutriment[i][j] >= tree[i][j][k]) {
					nutriment[i][j] -= tree[i][j][k];
					temp.push_back(tree[i][j][k] + 1);
					//cout << "이제[" << i << "][" << j << "]위치 " << k << "번째 나무를 지난 나무양분은" << nutriment[i][j] << endl;
				}
				else {
					deadNutri += (tree[i][j][k] / 2);
				}
			}

			tree[i][j].clear();
			for (int t = 0; t < temp.size(); t++) {
				tree[i][j].push_back(temp[t]);
			}
			nutriment[i][j] += deadNutri;
			//if (deadNutri != 0)
			//cout << "죽은양분더한 [" << i << "][" << j << "]위치의 양분값은" << nutriment[i][j] << endl;
		}
	}
}

void fall() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (tree[i][j].size() == 0)continue;
			for (int k = 0; k < tree[i][j].size(); k++) {
				if (tree[i][j][k] %5 == 0) {
					//cout << "[" << i << "][" << j << "]위치 " << k << "번째 나무의 나이는" << tree[i][j][k] << endl;
					for (int dir = 0; dir < 8; dir++) {
						int nr = i + dr[dir];
						int nc = j + dc[dir];
						if (nr >= 1 && nc >= 1 && nr <= N && nc <= N) {
							tree[nr][nc].push_back(1);
						}
					}
				}
			}
		}
	}
}

void winter() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			nutriment[i][j] += nu_init[i][j];
		}
	}
}

int check() {
	int answer = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			answer += tree[i][j].size();
		}
	}
	return answer;
}
int main() {
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> nu_init[i][j];
			nutriment[i][j] = 5;
		}
	}
	for (int i = 0; i < M; i++) {
		int r, c, age;
		cin >> r >> c >> age;
		tree[r][c].push_back(age);
	}

	while (K > 0) {
		springSummer();
		//cout << "=========================" << endl;
		//for (int i = 1; i <= N; i++) {
		//	for (int j = 1; j <= N; j++) {
		//		cout << nutriment[i][j];
		//	}cout << endl;
		//}
		fall();
		//cout << "나무갯수출력" << endl;
		//for (int i = 1; i <= N; i++) {
		//	for (int j = 1; j <= N; j++) {
		//		cout << tree[i][j].size();
		//	}cout << endl;
		//}
		//cout << "=========================" << endl;
		winter();
		K--;
	}

	cout << check() << endl;


}