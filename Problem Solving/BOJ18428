/*감시 피하기*/
#include <iostream>
#include <string>
#include <vector>
#include <utility>
using namespace std;

char map[6][6];
int N;
string answer = "NO";
vector<pair<int, int>> teacher;
vector<pair<int,int>> student;
pair<int, int> obstacle[3];
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };
bool possible() {
	//int num = student.size();
	int flag = 0;
	for (int i = 0; i < teacher.size(); i++) {
		int r = teacher[i].first;
		int c = teacher[i].second;
		for (int d = 0; d < 4; d++) {
			int nr = r + dr[d];
			int nc = c + dc[d];
			while (1) {
			 if (nr < 0 || nc < 0 || nr >= N || nc >= N || map[nr][nc] == 'O')break;
			 if (map[nr][nc] == 'S') return false;

			 nr += dr[d];
			 nc += dc[d];
			}
		}
	}
	return true;
}

void simul(int cnt) {
	if (!answer.compare("YES"))return;
	if (cnt == 3) {
		bool ans = possible();
		if (ans)answer = "YES";
		for (int s = 0; s < student.size(); s++) 
			map[student[s].first][student[s].second] = 'S';	
		return;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 'X') {
				obstacle[cnt].first = i;
				obstacle[cnt].second = j;
				map[i][j] = 'O';
				simul(cnt + 1);
				map[i][j] = 'X';
			}
		}
	}
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'T')teacher.push_back(make_pair(i, j));
			else if (map[i][j] == 'S')student.push_back(make_pair(i, j));
		}
	}
	simul(0);
	cout << answer << "\n";
}
