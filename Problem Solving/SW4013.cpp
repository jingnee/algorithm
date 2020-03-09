/*
 [SW] 특이한 자석
 1. 날에 자성이 들어있는 자석 4개가 있다. 시계방향 또는 반시계방향으로 회전이 가능한데, 회전시 다음 자석과 붙어있는 날이 같았으면 pass,
 달랐으면 현재자석 회전과 반대방향으로 회전한다.
 2. 방향 > 시계방향:1 , 반시계방향: -1
	자성 > N극:0, S극:1
	자석은4개, 자성은 8개
3. magnetic[4][8]: magnetic 정보가 들어있음
	arrow[4]	: 화살표위치
	index[4][2]	: 닿아있는 자성의 위치(
	[0][1]:자석1에서 1,2닿아있는위치, 
	[1][0]:자석2에서 1,2닿아있는 위치,
	[1][1]:자석2에서 2,3닿아있는위치,
	[2][0]:자석3에서 2,3닿아있는위치,
	[2][1]:자석3에서 3,4닿아있는위치,
	[3][0]:자석4에서 3,4닿아있는위치)

시계방향으로 돌아가면 화살표는 왼쪽으로, 반시계방향으로 돌아가면 화살표는 오른쪽이로 이동하므로
화살표의 위치는 방향*-1
*/


#include<iostream>
using namespace std;

int magnetic[4][8];
void rotate(int m, int d) {		//m번 자석을 d방향으로 돌림
	if (d == 1) {	//시계방향회전. [0]=[7], [1]=[0], [2]=[1], ... [7]=[6]
		int temp = magnetic[m][0];
		magnetic[m][0] = magnetic[m][7];
		for (int i = 7; i > 1; i--)magnetic[m][i] = magnetic[m][i - 1];
		magnetic[m][1] = temp;
	}

	else if (d == -1) {
		int temp = magnetic[m][7];
		magnetic[m][7] = magnetic[m][0];
		for (int i = 0; i < 6; i++)magnetic[m][i] = magnetic[m][i + 1];
		magnetic[m][6] = temp;
	}
}

bool check(int a, int b) {		//a자석과 b자석의 닿아있는 자성이 같은지 확인
	if (a > b) {
		if (magnetic[a][6] == magnetic[b][2])return true;
		else return false;
	}
	else {
		if (magnetic[a][2] == magnetic[b][6])return true;
		else return false;
	}
}
//main에서 돌리라고 받은 자석의 왼쪽자석을 돌리는것.그러니까 이 함수는 왼쪽자석이 인자값으로 들어오므로 오른쪽 자석과 비교
void turn_left(int m, int d) {		
	if (m < 0 || m>4)return;
	else if (!check(m, m + 1)) {	//체크함수에서 자성이 다르게 나오면
		turn_left(m - 1, d*-1);
		rotate(m, d);
	}
}
void turn_right(int m, int d) {
	if (m < 0 || m>4)return;
	else if (!check(m - 1, m)) {
		turn_right(m + 1, d*-1);
		rotate(m, d);
	}
}

int main() {
	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		int k;
		int magnetic_num, direction;
		cin >> k;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 8; j++) {
				cin >> magnetic[i][j];
			}
		}

		for (int i = 0; i < k; i++) {
			cin >> magnetic_num >> direction;
			magnetic_num--;

			turn_left(magnetic_num - 1, direction*-1);
			turn_right(magnetic_num + 1, direction*-1);
			rotate(magnetic_num, direction);
		}

		int answer = 0;
		for (int i = 0; i < 4; i++) {
			if (magnetic[i][0] == 1) {
				int num;
				if (i == 0)num = 1;
				else if (i == 1)num = 2;
				else if (i == 2)num = 4;
				else if (i == 3)num = 8;
				answer += num;
			}
		}
		cout << "#" << test_case << " " << answer << endl;
	}
}

/*
이코드 문제점: 왼쪽으로 탐색하려면 계속 왼쪽으로 가면서 탐색해야하는데 나느 왼쪽으로가서 왼쪽오른쪽 둘다 돌리고있으니까 문제점이 생기는듯

#include<iostream>
using namespace std;

int magnetic[4][8];
int arrow[4];
int index[4][2];
int visit[4];
int changeArrow(int arrow, int d) {		//화살표위치를 바꾸어주는 함수
	int new_arrow = arrow + d;
	if (new_arrow < 0)new_arrow = 7;
	else if (new_arrow > 7)new_arrow = 0;
	return new_arrow;
}

void simul(int m_num, int direction) {
	arrow[m_num] = changeArrow(arrow[m_num], direction);		//화살표위치변경
	//visit[m_num] = 1;
	//왼쪽 탐색

		if (index[m_num][0] != -1) {
			//if(visit[m_num-1]==1)index[m_num][0] = changeArrow(index[m_num][0], direction);
			if (magnetic[m_num][index[m_num][0]] == magnetic[m_num - 1][index[m_num - 1][1]]) {
				index[m_num][0] = changeArrow(index[m_num][0], direction);
			}
			else {
				index[m_num][0] = changeArrow(index[m_num][0], direction);
				simul(m_num - 1, direction*-1);
				//visit[m_num - 1] = 0;
			}
		}

	//오른쪽 탐색

		if (index[m_num][1] != -1) {
			//if (visit[m_num+1] == 1)index[m_num][0] = changeArrow(index[m_num][0], direction);
			if (magnetic[m_num][index[m_num][1]] == magnetic[m_num + 1][index[m_num + 1][0]]) {		//같은자성이면 다음애 회전시키지말고, 현재자석 index값만 변경(닿아있는위치)
				index[m_num][1] = changeArrow(index[m_num][1], direction);
			}

			else {
				index[m_num][1] = changeArrow(index[m_num][1], direction);
				simul(m_num + 1, direction*-1);
				//visit[m_num + 1] = 0;
			}
		}

	//index[m_num][0] = changeArrow(index[m_num][0], direction);
	//index[m_num][1] = changeArrow(index[m_num][1], direction);
}

int main() {
	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		int k;
		int magnetic_num, direction;
		cin >> k;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 8; j++) {
				cin >> magnetic[i][j];
			}
		}
		//초기화 작업  2랑6임
		index[0][0] = -1;
		index[0][1] = 2;
		index[1][0] = 6;
		index[1][1] = 2;
		index[2][0] = 6;
		index[2][1] = 2;
		index[3][0] = 6;
		index[3][1] = -1;
		for (int i = 0; i < 4; i++) {
			arrow[i] = 0;
			visit[i] = 0;
		}

		for (int i = 0; i < k; i++) {
			cin >> magnetic_num >> direction;
			direction *= -1;
			magnetic_num--;

			simul(magnetic_num, direction);
			for (int i = 0; i < 4; i++)visit[i] = 0;
		}

		int answer = 0;
		for (int i = 0; i < 4; i++) {
			if (magnetic[i][arrow[i]] == 1) {
				int num;
				if (i == 0)num = 1;
				else if (i == 1)num = 2;
				else if (i == 2)num = 4;
				else if (i == 3)num = 8;
				answer += num;
			}
		}

		cout << "#" << test_case << " " << answer << endl;

	}
}
*/
