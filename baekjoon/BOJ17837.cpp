/*새로운 게임 2*/
#include <iostream>
#include <vector>
using namespace std;

struct CHESS{
	int r, c, dir;
};

int colorMap[12][12];
vector<int> map[12][12];			//각 체스판에 체스가 몇개 겹쳐있는지
//CHESS chesses[10];					//각 체스들 위치
vector<CHESS>chesses;
int dr[4] = { 0,0,-1,1 };
int dc[4] = { 1,-1,0,0 };

int N, K;
int main() {
	cin >> N >> K;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> colorMap[i][j];
	for (int i = 0; i < K; i++) {
		int r, c, dir;
		cin >> r >> c >> dir;
		r -= 1, c -= 1, dir -= 1;
		//chesses[i] = { r,c,dir };
		chesses.push_back({ r,c,dir });
		map[r][c].push_back(i);
	}

	//bool flag = true;
	int answer = 0;
	while (true) {
		if (answer > 1000) break;

		answer++;
		//cout << "answer:" << answer << endl;
		for (int chessNum = 0; chessNum < K; chessNum++) {			//체스1번부터 시작
			int r = chesses[chessNum].r;
			int c = chesses[chessNum].c;
			int dir = chesses[chessNum].dir;

			int nr = r + dr[dir];
			int nc = c + dc[dir];
			//벗어나거나 파란색인 경우
			if (!(nr>=0 && nc>=0 && nr<N && nc<N) || colorMap[nr][nc] == 2) {
				if (dir == 0)chesses[chessNum].dir = 1;
				else if (dir == 1)chesses[chessNum].dir = 0;
				else if (dir == 2)chesses[chessNum].dir = 3;
				else if (dir == 3)chesses[chessNum].dir = 2;

				nr = r + dr[chesses[chessNum].dir];
				nc = c + dc[chesses[chessNum].dir];
				//cout << chessNum << "이 파란색만남" << endl;
			}

			//다음 위치가 또 파란색일때
			if (!(nr >= 0 && nc >= 0 && nr < N && nc < N) || colorMap[nr][nc] == 2) {
				//cout << chessNum << "이 또 파란색만남" << endl;


				continue;
			}

			//빨간색인 경우
			else if (colorMap[nr][nc] == 1) {
				int index = -1;
				for (int j = map[r][c].size() - 1; j >= 0; j--) {
					int chess = map[r][c][j];
					if (chess == chessNum) {
						index = j;
						break;
					}
				}
				int size = map[r][c].size();
				for (int j = size-1; j >= index; j--) {
					//int chess = map[r][c][j];
					int chess = map[r][c].back();
					map[nr][nc].push_back(chess);
					chesses[chess].r = nr;
					chesses[chess].c = nc;
					map[r][c].pop_back();
					if (map[nr][nc].size() >= 4) { cout << answer << endl; return 0; }

				}
				
				/*int size = map[r][c].size();
				for (int j = index; j < size; j++) {
					map[r][c].pop_back();
				}*/
				//cout << chessNum << "이 빨간색만남" << endl;

			}

			//하얀색인 경우
			else {
				int index = -1;
				for (int j = 0; j < map[r][c].size(); j++) {
					int chess = map[r][c][j];
					//chessNum이 체스판 위치에서 몇번째에 있는지 찾고,
					if (chess == chessNum) index = j;
					//index부터 찾기
					if (index == -1)continue;

					map[nr][nc].push_back(chess);
					//chesses[j] = { nr,nc,dir };
					chesses[chess].r = nr;
					chesses[chess].c = nc;
					if (map[nr][nc].size() >= 4) { cout << answer << endl; return 0; }
				}
				int size = map[r][c].size();
				for (int j = index; j < size; j++)map[r][c].pop_back();
				//cout << chessNum << "이 하얀색만남" << endl;

			}
	}
		/*for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j].size() > 0) {
					cout << "\n=========================\n";

					cout << i << "," << j << "위치에 있는 체스들: ";
					for (int k = 0; k<map[i][j].size(); k++)cout << map[i][j][k] << ",";
	
				}
			}
		}
		cout << "\n=========================\n";
*/
}

	cout<<-1<<endl;
}