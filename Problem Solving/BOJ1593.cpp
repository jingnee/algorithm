/*문자 해독*/
#include <iostream>
#include <string>
#include <map>
using namespace std;

int g, s, answer;
string W, S;
//map<char, int>g_str;
int ww[256];
int ss[256];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> g >> s;
	cin >> W >> S;

	for (int i = 0; i < g; i++) //g_str[W[i]]++;
	{
		ww[W[i]]++;
		ss[S[i]]++;
	}

	//map<char, int>temp;
	//for (int i = 0; i < g; i++)temp[S[i]]++;

	bool flag = true;
	//map iterator 사용
	/*map<char, int>::iterator iter1;
	map<char, int>::iterator iter2;*/
	//for (iter1 = g_str.begin(), iter2 = temp.begin(); iter1 != g_str.end(); iter1++, iter2++) {
	//	if (iter1->first != iter2->first || iter1->second != iter2->second) {
	//		flag = false;
	//		break;
	//	}
	//}


	//map 사용
	//for (int i = 0; i < g; i++) {
	//	if (temp[W[i]] != g_str[W[i]]) {
	//		flag = false;
	//		break;
	//	}
	//}

	for (int i = 0; i < 26; i++) {
		if (ww['a' + i] != ss['a' + i]) {
			flag = false;
			break;
		}
		if (ww['A' + i] != ss['A' + i]) {
			flag = false;
			break;
		}
	}
	if (flag)answer++;

	for (int i = g; i < s; i++) {
		/*temp[S[i-g]]--;
		temp[S[i]]++;*/
		ss[S[i]]++;
		ss[S[i - g]]--;

		flag = true;
		//for (iter1 = g_str.begin(), iter2 = temp.begin(); iter1 != g_str.end(); iter1++, iter2++) {
		//	if (iter1->first != iter2->first || iter1->second != iter2->second) {
		//		flag = false;
		//		break;
		//	}
		//}


		//map 방법
		//count로 비교하면 값이 다름.. 왜지? value찾는건데... -> 공부하기
		//for (int j = 0; j < g; j++) {
		//	if (temp[W[j]] != g_str[W[j]]) {
		//		flag = false;
		//		break;
		//	}
		//}
		for (int i = 0; i < 26; i++) {
			if (ww['a' + i] != ss['a' + i]) {
				flag = false;
				break;
			}
			if (ww['A' + i] != ss['A' + i]) {
				flag = false;
				break;
			}
		}
		if (flag)answer++;
	}
	
	cout << answer << "\n";
}
