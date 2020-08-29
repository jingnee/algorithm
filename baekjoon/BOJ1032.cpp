// 명령 프롬프트
#include <iostream>
#include <string>
using namespace std;

int N;
string str[51];
int main() {
	char answer[51];
	char ch;
	int flag = 0;
	int index = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> str[i];
	}
	int length = str[0].length();

	for (int i = 0; i < length; i++) {
		ch = str[0][i];
		//if (flag == 1)break;
		for (int j = 1; j < N; j++) {
			if (ch != str[j][i]) {
				flag = 1;
				break;
			}

		}
		if (flag == 0) {
			answer[index++] = ch;
		}
		else if (flag == 1) {			//뒷부분에 같은게 존재할 수도 있는데 조사안함
			answer[index++] = '?';
			flag = 0;
		}
	}

	/*for (int i = index; i < length; i++) {
		answer[i] = '?';
	}*/
	

	for (int i = 0; i < length; i++)
		cout << answer[i];

}