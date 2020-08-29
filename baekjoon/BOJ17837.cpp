/*���ο� ���� 2*/
#include <iostream>
#include <vector>
using namespace std;

struct CHESS{
	int r, c, dir;
};

int colorMap[12][12];
vector<int> map[12][12];			//�� ü���ǿ� ü���� � �����ִ���
//CHESS chesses[10];					//�� ü���� ��ġ
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
		for (int chessNum = 0; chessNum < K; chessNum++) {			//ü��1������ ����
			int r = chesses[chessNum].r;
			int c = chesses[chessNum].c;
			int dir = chesses[chessNum].dir;

			int nr = r + dr[dir];
			int nc = c + dc[dir];
			//����ų� �Ķ����� ���
			if (!(nr>=0 && nc>=0 && nr<N && nc<N) || colorMap[nr][nc] == 2) {
				if (dir == 0)chesses[chessNum].dir = 1;
				else if (dir == 1)chesses[chessNum].dir = 0;
				else if (dir == 2)chesses[chessNum].dir = 3;
				else if (dir == 3)chesses[chessNum].dir = 2;

				nr = r + dr[chesses[chessNum].dir];
				nc = c + dc[chesses[chessNum].dir];
				//cout << chessNum << "�� �Ķ�������" << endl;
			}

			//���� ��ġ�� �� �Ķ����϶�
			if (!(nr >= 0 && nc >= 0 && nr < N && nc < N) || colorMap[nr][nc] == 2) {
				//cout << chessNum << "�� �� �Ķ�������" << endl;


				continue;
			}

			//�������� ���
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
				//cout << chessNum << "�� ����������" << endl;

			}

			//�Ͼ���� ���
			else {
				int index = -1;
				for (int j = 0; j < map[r][c].size(); j++) {
					int chess = map[r][c][j];
					//chessNum�� ü���� ��ġ���� ���°�� �ִ��� ã��,
					if (chess == chessNum) index = j;
					//index���� ã��
					if (index == -1)continue;

					map[nr][nc].push_back(chess);
					//chesses[j] = { nr,nc,dir };
					chesses[chess].r = nr;
					chesses[chess].c = nc;
					if (map[nr][nc].size() >= 4) { cout << answer << endl; return 0; }
				}
				int size = map[r][c].size();
				for (int j = index; j < size; j++)map[r][c].pop_back();
				//cout << chessNum << "�� �Ͼ������" << endl;

			}
	}
		/*for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j].size() > 0) {
					cout << "\n=========================\n";

					cout << i << "," << j << "��ġ�� �ִ� ü����: ";
					for (int k = 0; k<map[i][j].size(); k++)cout << map[i][j][k] << ",";
	
				}
			}
		}
		cout << "\n=========================\n";
*/
}

	cout<<-1<<endl;
}