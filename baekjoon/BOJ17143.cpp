// ���ÿ�

#include <iostream>
#include <vector>
using namespace std;

struct shark {
	int size;
	int dir;
	int speed;
};
int R, C, M;
int catchNum;
shark map[102][102];
int dr[5] = { 0,-1,1,0,0 };
int dc[5] = { 0,0,0,1,-1 };

void getshark(int index) {			//�����̸鼭 ���ȹ���ϴ� �Լ�
	for (int r = 1; r <= R; r++) {
		if (map[r][index].size != 0) {
			catchNum += map[r][index].size;
			//cout << "������: [" << r << "][" << index << "]��° ��� ��Ҵ�! " << map[r][index].size <<"/ "<<catchNum << endl;
			map[r][index].size = 0;
			
			return;
		}
	}
}

void sharkmove() {		//��� �����̴� �Լ�
	shark array[102][102];
	for (int i = 1; i <= R; i++)
		for (int j = 1; j <= C; j++)
			array[i][j] = { 0,0,0 };

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (map[i][j].size != 0) {
				int a = i;
				int b = j;
				shark temp = map[i][j];
				int speed = (temp.dir <= 2) ? temp.speed % (2*(R - 1)) : temp.speed % (2*(C - 1));
				
				for (int s = 0; s < speed; s++) {
					int nr = a + dr[temp.dir];
					int nc = b + dc[temp.dir];
					if (nr<1 || nc <1 || nr>R || nc >C) {
						if (temp.dir == 1)temp.dir = 2;
						else if (temp.dir == 2)temp.dir = 1;
						else if (temp.dir == 3)temp.dir = 4;
						else if (temp.dir == 4)temp.dir = 3;

						nr += dr[temp.dir]*2;
						nc += dc[temp.dir]*2;
					}
					a = nr;
					b = nc;
				}

				if (array[a][b].size == 0) 
					array[a][b] = temp;
				
				else 
					if (array[a][b].size < temp.size)array[a][b] = temp;
				

				/*cout << "[" << i << "][" << j << "]��ġ ���->[" << a << "][" << b << "]�� �̵�" << endl;
				cout << "ũ���: " << array[a][b].size << endl;
				cout << "=============================================" << endl;*/
				map[i][j].size = 0;
				}
			
			}
		}
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			map[i][j] = array[i][j];
		}
	}
}



int main()
{
	cin >> R >> C >> M;
	for (int i = 0; i < M; i++) {
		int r, c, s, d, z;
		cin >> r >> c >> s >> d >> z;
		shark temp;
		temp.speed = s;
		temp.dir = d;
		temp.size = z;
		map[r][c] = temp;
	}

	for (int i = 1; i <= C; i++) {
		getshark(i);
		//cout << "*** " << i <<"��°" << endl;
		sharkmove();
		
	}
	cout << catchNum << endl;
}