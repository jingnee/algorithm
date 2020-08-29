/*거북이*/
#include <iostream>
#include <string>
using namespace std;

//북,동,남,서
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };
int N;
string str;
int min_x, min_y, max_x, max_y;

//기존의 minMax라는 이름의 함수가 출력초과를 발생시킨듯;;
//min~max등의 이름 사용할때 조심하자..
void checkNum(int x, int y) {
	if (x < min_x)min_x = x;
	if (y < min_y)min_y = y;
	if (x > max_x)max_x = x;
	if (y > max_y)max_y = y;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> str;
		min_x = 0, min_y = 0, max_x = 0, max_y = 0;
		int curX = 0, curY = 0;
		int dir = 0;
		for (auto s: str) {
			switch (s) {
			case 'F':
				curX += dr[dir];
				curY += dc[dir];
				checkNum(curX, curY);
				break;
			case 'B':
				curX -= dr[dir];
				curY -= dc[dir];
				checkNum(curX, curY);
				break;
			case 'L':
				dir = (dir + 1) % 4;
				break;
			case 'R':
				dir = (dir + 3) % 4;
				break;
			}
		}
		cout << (max_x - min_x)*(max_y - min_y) << endl;
	}
}
