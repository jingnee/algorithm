// 전구 스위치
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

#define INF 999999999
int answer, N;
string light, cur, result;

void push(int idx) {							//전구 누르는 함수
	if (idx > 0)
		cur[idx - 1] = (cur[idx - 1] == '0') ? '1' : '0';
	cur[idx] = (cur[idx] == '0') ? '1' : '0';
	if (idx < N - 1)
		cur[idx + 1] = (cur[idx + 1] == '0') ? '1' : '0';
}

void simulate(int idx, int cnt) {				//int->void로 변경 (런타임에러) return값이 있는 함수로 설정해놓고 모든경로에서 값을 반환하지않음. 경고메세지를 무시하지 말자!
	if (idx == N - 1) {
		if (cur[idx - 1] == result[idx - 1]) {
			if (cur[idx] == result[idx])
				answer = min(answer, cnt);
		}
		else {
			push(idx);
			if (cur[idx] == result[idx])
				answer = min(answer, cnt + 1);
		}
		return;
	}

	if (cur[idx - 1] == result[idx - 1])		//현재 인덱스 이전의 전구값이 같으면 전구 누르지않고 인덱스 이동
		simulate(idx + 1, cnt);
	else {
		push(idx);								//현재 인덱스 이전의 전구값이 다르면 현재인덱스에서 전구를 눌러줘야한다.(다음 인덱스로 넘어가버리면 이전전구값을 변경할 수 없으니까)
		simulate(idx + 1, cnt + 1);
	}
}

int main() {
	cin >> N;
	cin >> light >> result;
	cur = light;

	answer = INF;
	simulate(1, 0);					//첫번째 전구 안누르고 시작
	cur = light;					//전구 초기화
	push(0);						//첫번째 전구 누름
	simulate(1, 1);

	if(answer == INF) cout << "-1" << endl;	//정답을 찾지 못한경우 -1출력
	else cout << answer << endl;
	return 0;
}
