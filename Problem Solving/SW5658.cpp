//보물상자 비밀번호
#include<iostream>
#include<algorithm>
using namespace std;

int N, K;
int len;
string kind[28];
//string str1;
char str[28];
int answer[28];
long long makenum(string str) {
	long long num = 0, cnt = 1;
	int ten = 1;
	for (int i = len-1; i >= 0; i--, cnt++) {
		if (str[i] >= '0' && str[i] <= '9') {
			num += (str[i] - '0')*ten;
			ten *= 16;
		}
		else {
			num += (str[i] - 'A' + 10)*ten;
			ten *= 16;
		}
	}
	return num;
}
void rotate(string str1) {
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		//if(i<N)kind[cnt++] = str1.substr(i, len);
		//else 
		char *temp = new char[len];
		int index = 0;
		for (int j = i; j < i + len && index<len; j++) {
			j %= N;
			temp[index++] = str1[j];
		}
		temp[index] = '\0';
		index = 0;
		kind[i] = temp;
	}
	sort(kind,kind+N);
}

int main() {
	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		
		cin >> N >> K;
		len = N / 4;
		cin >> str;
		string str1;
		for (int i = 0; i < N; i++)str1 += str[i];

		//cout << str << endl;
		rotate(str1);

		int kk = K;
		int answer = 0;
		for (int i = N-1; i > 0; i--) {
			if (kk == 1) {
				answer = i;
				break;
			}
			if (kind[i].compare(kind[i - 1]) == 0)continue;
			else {
				kk--;
			}
		}
		//cout << kk << endl;

		cout << "#" << test_case << " " << makenum(kind[answer]) << endl;
		

	}
}