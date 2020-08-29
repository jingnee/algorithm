#include<iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string str;
long long k;
vector<pair<int, char>> vec;

int main() {
	cin >> str >> k;
	
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '1' || str[i] == '6')vec.push_back(make_pair(i, '1'));
		else if (str[i] == '2' || str[i] == '7')vec.push_back(make_pair(i, '2'));
	}

	//k번째 비밀번호가 존재하지 않는 경우
	//틀린이유1 ) k >= pow(2,vec.size()) 부분 변경 ==> 등호부분빼면 통과 (k가 1빼야하므로 그런듯)
	if (k < 1 || k >(((unsigned long long)1) << vec.size()) ) {
		printf("-1\n");
		return 0;
	}
	//k를 이진수로 만드는 법
	int size = vec.size();
	k--;
	//틀린이유2) reverse함수사용하지않고 배열크기에서 i만큼 뺀위치부터(즉 뒤에서부터) 인덱스로 접근해서 바꿨더니 틀렸다.. 왜?!
	reverse(vec.begin(), vec.end());
	for (int i = 0; i < vec.size(); i++) {
		if(k%2 == 1) {
			if (vec[i].second == '1')vec[i].second = '6';
			else if (vec[i].second == '2')vec[i].second = '7';
		}
		k /= 2;
	}
	reverse(vec.begin(), vec.end());

	int n = 0;
	for (int i = 0; i < str.size(); i++) {
		if (n < vec.size() && vec[n].first == i)printf("%c",vec[n++].second);
		else printf("%c",str[i]);
	}cout << "\n";
}
