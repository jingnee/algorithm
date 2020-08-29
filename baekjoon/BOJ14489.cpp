//스타트와링크
#include<iostream>
using namespace std;

int map[20][20];
int start_order[10];
int link_order[10];
bool visit[10];
int N;
int answer=987654321;
void find_linkCombi() {			//start팀 조합보고 link팀 조합 생성
	int index = 0;
	for (int i = 0,j=0; i < N; i++) {

		if (start_order[j] != i)link_order[index++] = i;
		else if (start_order[j] == i) {
			if(j<N/2 -1)
			j++;
		}
	}
	/*cout << "link조합: ";
	for (int i = 0; i < N / 2; i++)cout << link_order[i];
	cout << endl;*/
}

void count() {
	int s_num = 0, l_num = 0;
	for (int i = 0; i < N / 2 - 1; i++) {
		for (int j = i + 1; j < N / 2; j++) {
			int a = start_order[i];
			int b = start_order[j];
			s_num += map[a][b] + map[b][a];
		}
	}

	for (int i = 0; i < N / 2 - 1; i++) {
		for (int j = i + 1; j < N / 2; j++) {
			int a = link_order[i];
			int b = link_order[j];
			l_num += map[a][b] + map[b][a];
		}
	}
	int cha = (s_num > l_num) ? s_num - l_num : l_num - s_num;
	answer = (answer > cha) ? cha : answer;
	//cout << "s_num: " << s_num << " l_num: " << l_num << " answer: " << answer << endl;
}

void combi(int index, int cnt) {			//start조합찾아줌(N중 절반만 찾음)
	if (cnt == N / 2) {
		/*cout << "-----------------------" << endl;
		cout << "start조합: ";
		for (int i = 0; i < N / 2; i++)cout << start_order[i];
		cout << endl;*/

		find_linkCombi();
		count();
		return;
	}
		for (int i = index;	 i < N; i++) {
			if (visit[i] == false) {
				visit[i] = true;
				start_order[cnt] = i;
				combi(i, cnt + 1);
				visit[i] = false;
			}	
		}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	
	combi(0,0);
	cout << answer << endl;

}