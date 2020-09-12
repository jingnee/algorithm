#include <string>
using namespace std;
//0:U, 1:L, 2:D, 3:R
int map[11][11][4];

bool Go(int r, int c) {	//범위안에 있으면 갈수있다고 판단. true return
	return (r >= 0 && r <= 10 && c >= 0 && c <= 10);
}
int solution(string dirs)
{
	int answer = 0;
	int d = 0;
	int c = 5;
	int r = 5;

	while (dirs[d] != '\0') {
		if (dirs[d] == 'U') {
			if (Go(r - 1, c)) {
				if (map[r][c][0] == 0) {
					map[r][c][0] = 1;
					answer++;
				}
				map[--r][c][2] = 1;
			}
		}

		else if (dirs[d] == 'D') {
			if (Go(r + 1, c)) {
				if (map[r][c][2] == 0) {
					map[r][c][2] = 1;
					answer++;
				}
				map[++r][c][0] = 1;
			}
		}

		else if (dirs[d] == 'L') {
			if (Go(r, c-1)) {
				if (map[r][c][1] == 0) {
					map[r][c][1] = 1;
					answer++;
				}
				map[r][--c][3] = 1;
			}
		}
		else if (dirs[d] == 'R') {
			if (Go(r, c+1)) {
				if (map[r][c][3] == 0) {
					map[r][c][3] = 1;
					answer++;
				}
				map[r][++c][1] = 1;
			}
		}
		d++;
	}
	return answer;
}
