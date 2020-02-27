/*DSLR
1. 네개의 명령어 D(n*=2), S(n-=1), L(n을 왼쪽으로 밀기), R(n을 오른쪽으로 밀기)를 이용해서 최소의 명령어 수행으로 원하는 숫자를 만들기
2. D나 S명령어 수행에서 1 ~ 9999를 넘어갈 수 없다. (넘어갈 경우 나머지연산)
3. BFS로 모든 명령어를 수행할때마다 큐에 넣어줌. 만약 큐에 넣을값이 초깃값과 같으면 안넣는다.
*/
//중복체크를 하지 않으면 메모리 초과가 발생!!

#include<iostream>
#include<string>
#include<queue>
#include<cstring>
using namespace std;

int T, A, B;
string answer;
bool visit[100000];
struct Number {
	int regi;
	string cmd;
};
queue<Number> number;

int D(Number temp) {

	int num = (temp.regi * 2) % 10000;

	if (!visit[num]) {
		visit[num] = true;
		if (num == B)return 1;
		else {
			Number temp2;
			temp2.cmd = temp.cmd + "D";
			temp2.regi = num;
			number.push(temp2);
		}
	}
	//cout << num << endl;
	return 0;
}
int S(Number temp) {
	int num;
	if (temp.regi == 0)num = 9999;				//0인지 체크먼저 해야함 (런타임에러발생) --> 레지스터는 0이상 10000미만
	else num = temp.regi - 1;

	if (!visit[num]) {
		visit[num] = true;

		if (num == B)return 1;
		else {
			Number temp2;
			temp2.cmd = temp.cmd + "S";
			temp2.regi = num;
			number.push(temp2);
		}
	}
	//cout << num << endl;

	return 0;
}
int L(Number temp) {
	/*int d1, d2, d3, d4, num, regi;
	regi = temp.regi;
	d4 = regi % 10;
	regi /= 10;
	d3 = regi % 10;
	regi /= 10;
	d2 = regi % 10;
	regi /= 10;
	d1 = regi % 10;*/
	//num = ((d2 * 10 + d3) * 10 + d4) * 10 + d1;

	int num;
	int f = temp.regi / 1000;
	int b = temp.regi - f * 1000;
	num = f + b * 10;

	if (!visit[num]) {
		visit[num] = true;

		if (num == B)return 1;
		else {
			Number temp2;
			temp2.cmd = temp.cmd + "L";
			temp2.regi = num;
			number.push(temp2);
		}
	}
	//cout << num << endl;

	return 0;
}
int R(Number temp) {
	/*int d1, d2, d3, d4, num, regi;
	regi = temp.regi;
	d4 = regi % 10;
	regi /= 10;
	d3 = regi % 10;
	regi /= 10;
	d2 = regi % 10;
	regi /= 10;
	d1 = regi % 10;

	num = ((d4 * 10 + d1) * 10 + d2) * 10 + d3;*/

	int num;
	int b = temp.regi % 10;
	int f = (temp.regi-b)/10;
	num = f + b*1000;

	if (!visit[num]) {
		visit[num] = true;

		if (num == B)return 1;
		else {
			Number temp2;
			temp2.cmd = temp.cmd + "R";
			temp2.regi = num;
			number.push(temp2);
		}
	}
	//cout << num << endl;

	return 0;
}

void BFS() {
	Number temp = number.front();
	number.pop();

		if (D(temp) == 1) {
			answer = temp.cmd + "D";
			return;
		}
		if (S(temp) == 1)
		{
			answer = temp.cmd + "S";
			return;
		}
		if (L(temp) == 1) {
			answer = temp.cmd + "L";
			return;
		}
		if (R(temp) == 1) {
			answer = temp.cmd + "R";
			return;
		}

		BFS();
}

int main() {
	cin >> T;
	for (int test_case = 0; test_case < T; test_case++) {
		cin >> A >> B;
		//number.clear();
		answer = "";
		while (!number.empty())number.pop();
		memset(visit, false, sizeof(visit));
		Number temp;
		temp.regi = A;
		temp.cmd = "";
		number.push(temp);
		visit[A] = true;

		BFS();
		cout << answer << endl;
	}
}